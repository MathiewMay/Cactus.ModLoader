#include "Loader.h"

#include <filesystem>
#include <fstream>
#include <utility>
#include <string>

#include "Lua/LuaBindings.h"

class MinecraftServer;

namespace fs = std::filesystem;

Loader::Loader() {
    luaServer.open_libraries(sol::lib::base, sol::lib::string, sol::lib::table, sol::lib::package);
    luaClient.open_libraries(sol::lib::base, sol::lib::string, sol::lib::table, sol::lib::package);

    if (!fs::exists("mods")) {
        fs::create_directory("mods/");
    }

    LuaBindings::bindCommonFunctions({ &luaServer, &luaClient });
    LuaBindings::bindClientFunctions(luaClient);
    LuaBindings::bindServerEvents(luaServer);
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

void Loader::log(const string& message) {
    app.DebugPrintf(("[Lua] " + message + "\n").c_str());
}

string Loader::loadFile(string fileName) {
    std::ifstream file(fileName);
    stringstream buf;
    buf << file.rdbuf();
    return buf.str();
}

void Loader::registerServerFunctions(MinecraftServer *server) {
    LuaBindings::bindServerFunctions(luaServer, server);
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
