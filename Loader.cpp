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
#include "Common/EventSystem/EventHandler.h"

namespace fs = std::filesystem;

Loader::Loader() {
    lua.open_libraries(sol::lib::base, sol::lib::string, sol::lib::table);

    if (!fs::exists("mods")) {
        fs::create_directory("mods/");
    }

    registerFunctions();
    app.DebugPrintf("Cactus modloader initalized!\n");
    EventHandler::bindEvents(lua);
}

void Loader::_debugPrint(std::string output) {
    app.DebugPrintf(("[Lua] "+output+"\n").c_str());
}

nlohmann::json Loader::getManifest(std::string filePath) {
    std::string fullPath = filePath + "/manifest.json";
    auto data = loadFile(fullPath);
    return nlohmann::json::parse(data);
}

void Loader::registerFunctions() {
    lua.set_function("log", [this](std::string message) {
        this->log(message);
    });
    lua.set_function("test", [this](std::string event, sol::function func) {
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

void Loader::log(std::string message) {
    app.DebugPrintf(("[Lua] " + message + "\n").c_str());
}

std::string Loader::loadFile(std::string fileName) {
    std::ifstream file(fileName);
    std::stringstream buf;
    buf << file.rdbuf();
    return buf.str();
}

void Loader::test(std::string event, sol::function func) { //testing function returning from lua
    func();
}

void Loader::loadMods() {
    for (auto & [id, script] : compiledScripts_) {
        auto result = script();
        if (!result.valid()) {
            sol::error err = result;
            _debugPrint(("Error in '"+id+"': "+err.what()).c_str());
        }
    }

    for (auto& [id, script] : compiledScripts_) {
        auto modProxy = lua[id];

        if (modProxy.valid() && modProxy.get_type() == sol::type::table) {
            sol::table modTable = modProxy;
            sol::protected_function mainFunc = modTable["main"];

            if (mainFunc.valid()) {
                auto r = mainFunc();
                if (!r.valid()) {
                    sol::error err = r;
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

void Loader::collectMods() { //todo: remove possible mem leaks, i do not know how to memory manage :sunglasses:
    //iterate through mods folder
    for (const auto & modEntry : fs::directory_iterator("mods/")) {
        std::map<std::string, std::any> modTbl;
        nlohmann::json json = getManifest(modEntry.path()); //eat json data yummy :yum:
        modTbl["modId"] = json["modId"].get<std::string>();
        modTbl["name"] = json["name"].get<std::string>();
        modTbl["version"] = json["version"].get<std::string>();
        std::string modId = json["modId"].get<std::string>();

        mods_[modEntry.path().filename().c_str()] = modTbl; //apply mod data into mod tbl

        std::string moduleFolder = modEntry.path().string() + "/module";
        if (fs::exists(moduleFolder)) {
            for (const auto & modFile : fs::directory_iterator(moduleFolder)) {
                if (modFile.path().extension() == ".lua") {
                    auto r = lua.load_file(modFile.path().string());

                    if (r.valid()) {
                        compiledScripts_[modId] = std::move(r);
                    } else {
                        sol::error err = r;
                        _debugPrint("code bad: " + std::string(err.what()));
                    }
                }
            }
        }
    }
}

/* //incase global modloader is fucked
int Loader::getModCount() { //dont touch internal variables as this should be used without creating new Loader.cpp
    auto hasLuaFiles = false;
    int modCount = 0;

    for (const auto & modEntry : fs::directory_iterator("mods/")) {

        std::string moduleFolder = modEntry.path().string() + "/module";
        if (fs::exists(moduleFolder)) {
            for (const auto & modFile : fs::directory_iterator(moduleFolder)) {
                if (modFile.path().extension() == ".lua") {
                    hasLuaFiles = true;
                }
            }
        }
        if (hasLuaFiles) {
            modCount += 1;
        }
    }
    return modCount;
}*/