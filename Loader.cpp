#include "Loader.h"

#include "../Minecraft.Client/MinecraftServer.h"
#include "../Minecraft.World/Commands/CommandDispatcher.h"
#include "../Minecraft.World/Level/Level.h"
#include "../Minecraft.World/Level/LevelChunk.h"
#include "../Minecraft.World/Player/Player.h"
#include "../Minecraft.Client/Level/ServerLevel.h"

#include <filesystem>
#include <fstream>
#include <utility>
#include <string>
#include "Common/EventSystem/EventHandler.h"

namespace fs = std::filesystem;

Loader::Loader() {
    lua.open_libraries(sol::lib::base, sol::lib::string, sol::lib::table);

    if (!fs::exists("mods")) {
        fs::create_directory("mods/");
    }

    registerFunctions();
    app.DebugPrintf("Cactus ModLoader initialized!\n");
    EventHandler::bindEvents(lua);
}

void Loader::_debugPrint(string output) {
    app.DebugPrintf(("[Lua] "+output+"\n").c_str());
}

nlohmann::json Loader::getManifest(string filePath) {
    string fullPath = filePath + "/manifest.json";
    auto data = loadFile(fullPath);
    return nlohmann::json::parse(data);
}

void Loader::registerFunctions() {
    lua.set_function("log", [this](string message) {
        this->log(message);
    });
    lua.set_function("test", [this](string event, sol::function func) {
        this->test(event, func);
    });

    //ok so you need to register EVERYTHING you want with this, im gonna hurt myself
    lua.new_usertype<CommandSender>("CommandSender",
        "hasPermission", &CommandSender::hasPermission
    );

    lua.new_usertype<Player>("Player",
        "getPos", &Player::getPos,
        "setPos", sol::resolve<void(double, double, double)>(&Player::setPos),
        "abilities", &Player::abilities,
        "changeDimension", &Player::changeDimension,
        "sendMessage", &Player::sendMessage,
        sol::base_classes, sol::bases<CommandSender>()
    );

    lua.new_usertype<CommandDispatcher>("CommandDispatcher",
        "performCommand", &CommandDispatcher::performCommand
    );

    lua.new_enum<EGameCommand>("EGameCommand", {
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

    lua.new_usertype<MinecraftServer>("MinecraftServer",
        "getCommandDispatcher", &MinecraftServer::getCommandDispatcher
    );
    lua.new_usertype<ServerLevel>("ServerLevel",
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

void Loader::loadMods() {

}

void Loader::executeServerScripts() {
    for (auto& [id, script] : serverScripts_) {
        auto modProxy = lua[id];

        if (modProxy.valid() && modProxy.get_type() == sol::type::table) {
            sol::table modTable = modProxy;
            sol::protected_function mainFunc = modTable["main"];

            if (mainFunc.valid()) {
                auto result = mainFunc();
                if (!result.valid()) {
                    sol::error err = result;
                    _debugPrint(("Error in '"+id+"': "+err.what()).c_str());
                }
            } else {
                _debugPrint(("Mod "+id+" must have a 'main()' function in its global table, 'function "+id+".main()' is missing"));
            }
        } else {
            _debugPrint(("Mod "+id+" has no global table, '"+id+" = {}' is missing"));
        }
    }
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
    serverScripts_.clear();

    for (const auto & [modId, json] : mods_) {
        if (json["serverMain"].is_null()) {
            _debugPrint(("Mod "+modId+" has no 'serverMain' in its manifest.json"));
            continue;
        }
        string serverMain = json["serverMain"];

        string serverMainPath = "mods/"+modId+"/"+serverMain;
        if (!fs::exists(serverMainPath)) {
            _debugPrint(("Could not find file for "+serverMainPath+" for mod "+modId));
            continue;
        }
        mainServerFiles_[modId] = serverMain;

        auto result = lua.load_file(serverMainPath);

        if (result.valid()) {
            serverScripts_[modId] = std::move(result);
            _debugPrint(modId+"'s '"+serverMain+"' has been loaded successfully");
        } else {
            sol::error err = result;
            _debugPrint("code bad: " + string(err.what()));
        }
    }
}