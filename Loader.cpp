#include "Loader.h"

#include "../Minecraft.World/Commands/CommandDispatcher.h"
#include "../Minecraft.World/Level/Level.h"
#include "../Minecraft.World/Level/LevelChunk.h"
#include "../Minecraft.World/Player/Player.h"
#include "../Minecraft.Client/Level/ServerLevel.h"
#include "../Minecraft.Client/Player/ServerPlayer.h"
#include "../Minecraft.Client/Network/PlayerList.h"
#include "../Minecraft.Client/MinecraftServer.h"

#include <filesystem>
#include <fstream>
#include <utility>
#include <string>

#include "../Minecraft.World/Items/Item.h"
#include "Common/EventSystem/EventBindings.h"

class MinecraftServer;

namespace fs = std::filesystem;

Loader::Loader() {
    luaServer.open_libraries(sol::lib::base, sol::lib::string, sol::lib::table, sol::lib::package);
    luaClient.open_libraries(sol::lib::base, sol::lib::string, sol::lib::table, sol::lib::package);

    if (!fs::exists("mods")) {
        fs::create_directory("mods/");
    }

    registerClientFunctions();
    EventBindings::bindServerEvents(luaServer);
    app.DebugPrintf("Cactus ModLoader initialized!\n");
}

void Loader::_debugPrint(string output) {
    app.DebugPrintf(("[Lua] "+output+"\n").c_str());
}

nlohmann::json Loader::getManifest(string filePath) {
    string fullPath = filePath + "/manifest.json";
    auto data = loadFile(fullPath);
    return nlohmann::json::parse(data);
}

std::vector<std::string> langList(2000); //increase if needed

int itemNameIdMax = 1937;
int itemIdMax = 406;

int nextItemNameId() {
    itemNameIdMax += 1;
    return itemNameIdMax;
}

int nextItemId() {
    itemIdMax += 1;
    return itemIdMax;
}

void Loader::registerClientFunctions() {
    luaClient.set_function("registerItem", [this](string name) {
        int itemNameId = nextItemNameId();
        int itemId = nextItemId();
        Item::items[itemId] = (new Item(itemId))->setTextureName(L"stick")->handEquipped()->setDescriptionId(itemNameId)->setUseDescriptionId(IDS_DESC_STICK); // im SO close to getting name working.. unsure whats wrong.
        langList[itemNameId] = name;
        return itemId;
    });

    luaClient.set_function("log", [this](string message) {
        this->log(message);
    });
}

void Loader::changeLang(StringTable& m_stringTable) {
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    for (size_t i = 0; i < langList.size(); i++) {
        if (langList[i].empty()) continue;

        const char* text = langList[i].c_str();
        std::wstring wtext = std::wstring(text, text + strlen(text));
        m_stringTable.addData(i, wtext);
        app.DebugPrintf("[Lua] ");
        app.DebugPrintf(to_string(i).c_str());
        app.DebugPrintf(" is the id for: \n");
        app.DebugPrintf(("[Lua] "+converter.to_bytes(m_stringTable.getString(i))+"\n").c_str());
    }
}

void Loader::registerServerFunctions(MinecraftServer* server) {
    luaServer["server"] = server;

    luaServer.new_usertype<MinecraftServer>("MinecraftServer",
        "getCommandDispatcher", &MinecraftServer::getCommandDispatcher,
        "getPlayers", [](MinecraftServer* server) -> std::vector<std::shared_ptr<ServerPlayer>>& {
            return server->getPlayers()->players;
        }
    );

    luaServer.set_function("log", [this](string message) {
        this->log(message);
    });
    luaServer.set_function("test", [this](string event, sol::function func) {
        this->test(event, func);
    });

    //ok so you need to register EVERYTHING you want with this, im gonna hurt myself
    luaServer.new_usertype<CommandSender>("CommandSender",
        "hasPermission", &CommandSender::hasPermission
    );

    luaServer.new_usertype<Player>("Player",
        "getPos", &Player::getPos,
        "setPos", sol::resolve<void(double, double, double)>(&Player::setPos),
        "abilities", &Player::abilities,
        "changeDimension", &Player::changeDimension,
        "sendMessage", &Player::sendMessage,
        sol::base_classes, sol::bases<CommandSender>()
    );

    luaServer.new_usertype<CommandDispatcher>("CommandDispatcher",
        "performCommand", &CommandDispatcher::performCommand
    );

    luaServer.new_enum<EGameCommand>("EGameCommand", {
            {"COUNT", eGameCommand_COUNT},
            {"EnchantItem", EGameCommand::eGameCommand_EnchantItem},
            {"Experience", EGameCommand::eGameCommand_Experience},
            {"GameMode", EGameCommand::eGameCommand_GameMode},
            {"Give", EGameCommand::eGameCommand_Give},
            {"Kill", EGameCommand::eGameCommand_Kill},
            {"Teleport", EGameCommand::eGameCommand_Teleport},
            {"Time", EGameCommand::eGameCommand_Time},
            {"ToggleDownfall", EGameCommand::eGameCommand_ToggleDownfall}
        }
    );

    luaServer.new_usertype<ServerLevel>("ServerLevel",
        "getBlocksAndData", &ServerLevel::getBlocksAndData,
        "setBlocksAndData", &ServerLevel::setBlocksAndData,
        "getServer", &ServerLevel::getServer
    );
}

void Loader::log(string message) {
    app.DebugPrintf(("[Lua] " + message + "\n").c_str());
}

string Loader::loadFile(string fileName) {
    std::ifstream file(fileName);
    stringstream buf;
    buf << file.rdbuf();
    return buf.str();
}

void Loader::test(string event, sol::function func) { //testing function returning from lua
    func();
}

void Loader::collectMods() {
    //iterate through mods folder
    for (const auto & modEntry : fs::directory_iterator("mods/")) {
        nlohmann::json json = getManifest(modEntry.path()); //eat json data yummy :yum:

        string modPath = modEntry.path().string();

        if (json["modId"].is_null()) {
            _debugPrint((modPath+" has no 'modId' please add one"));
            continue;
        }
        string modId = json["modId"].get<string>();

        mods_[modId] = json;
    }
}

void Loader::refreshServerScripts() {
    serverModEnvironments_.clear();

    for (const auto & [modId, json] : mods_) {
        if (!json.contains("serverMain") || json["serverMain"].is_null()) {
            _debugPrint(("Mod "+modId+" has no 'serverMain' in its manifest.json skipping."));
            continue;
        }
        string serverMain = json["serverMain"].get<string>();

        string serverMainPath = "mods/"+modId+"/"+serverMain;
        if (!fs::exists(serverMainPath)) {
            _debugPrint(("Could not find file for "+serverMainPath+" for mod "+modId));

            continue;
        }
        mainServerFiles_[modId] = serverMain;

        string currentPath = luaServer["package"]["path"];
        string newPath = "mods/"+modId+"/?.lua;"+currentPath;
        luaServer["package"]["path"] = newPath;
        
        sol::environment modEnv(luaServer, sol::create, luaServer.globals());
        auto result = luaServer.script_file(serverMainPath, modEnv);

        if (result.valid()) {
            serverModEnvironments_[modId] = std::move(modEnv);
            _debugPrint(modId+"'s '"+serverMain+"' has been loaded successfully");
        } else {
            sol::error err = result;
            _debugPrint("code bad: " + string(err.what()));
        }
    }
}

void Loader::refreshClientScripts() {
    clientModEnvironments_.clear();

    for (const auto & [modId, json] : mods_) {
        if (!json.contains("clientMain") || json["clientMain"].is_null()) {
            _debugPrint(("Mod "+modId+" has no 'clientMain' in its manifest.json skipping..."));
            continue;
        }
        string clientMain = json["clientMain"].get<string>();

        string clientMainPath = "mods/"+modId+"/"+clientMain;
        if (!fs::exists(clientMainPath)) {
            _debugPrint(("Could not find file for "+clientMainPath+" for mod "+modId));
            continue;
        }
        mainClientFiles_[modId] = clientMain;

        sol::environment modEnv(luaClient, sol::create, luaClient.globals());
        auto result = luaClient.script_file(clientMainPath, modEnv);

        if (result.valid()) {
            clientModEnvironments_[modId] = std::move(modEnv);
            _debugPrint(modId+"'s '"+clientMain+"' has been loaded successfully");
        } else {
            sol::error err = result;
            _debugPrint("code bad: " + string(err.what()));
        }
    }
}

void Loader::executeServerScripts() {
    for (auto& [id, environment] : serverModEnvironments_) {
        sol::protected_function mainFunc = environment["main"];

        if (mainFunc.valid()) {
            auto result = mainFunc();
            if (!result.valid()) {
                sol::error err = result;
                _debugPrint(("Error in '"+id+"': "+err.what()).c_str());
            }
        } else {
            _debugPrint(("Mod "+id+" must have a 'main()' function in its global table, 'function "+id+".main()' is missing"));
        }
    }
}

void Loader::executeClientScripts() {
    for (auto& [id, environment] : clientModEnvironments_) {
        sol::protected_function mainFunc = environment["main"];

        if (mainFunc.valid()) {
            auto result = mainFunc();
            if (!result.valid()) {
                sol::error err = result;
                _debugPrint(("Error in '"+id+"': "+err.what()).c_str());
            }
        } else {
            _debugPrint(("Mod "+id+" must have a 'main()' function in its global table, 'function "+id+".main()' is missing"));
        }
    }
}
