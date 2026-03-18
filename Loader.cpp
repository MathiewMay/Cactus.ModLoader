#include "Loader.h"

#include <filesystem>
#include <fstream>
#include <utility>
#include <string>

#include "Lua/LuaBindings.h"

class MinecraftServer;

namespace fs = std::filesystem;
using string = std::string;

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

bool hasMetadata(nlohmann::json& json, const std::string& key) {
    return !json[key].is_null();
}

void Loader::collectMods() {
    //iterate through mods folder
    for (const auto & modEntry : fs::directory_iterator("mods/")) {
        nlohmann::json json = getManifest(modEntry.path()); //eat json data yummy :yum:
        
        string modPath = modEntry.path().string();
        
        CactusMod m;
        bool missingRequired = false;

        for ( const auto & metadata : requiredMetadata ) {
            if (!hasMetadata(json, metadata)) {
                _debugPrint((modPath+" missing metadata '"+metadata+"' please add it to your manifest.json"));
                missingRequired = true;
                break;
            }
            m.metadata[metadata] = json[metadata].get<std::string>();
        }

        if (missingRequired) continue;

        mods_[m.getName()] = m;
    }
}

void Loader::refresh(sol::state& luaState,std::string_view (CactusMod::*getEntry)() const,bool prependPath) {
    for (auto& [name,mod] : mods_) {
        std::string modName = std::string(mod.getName());
        std::string modId = std::string(mod.getModID());
        std::string modEntry = std::string((mod.*getEntry)());

        std::string scriptPath = "mods/" + modId + "/" + modEntry;
        if (!fs::exists(scriptPath)) {
            _debugPrint("Could not find file for " + scriptPath + " for mod " + modName);
            continue;
        }

        if (prependPath) {
            std::string currentPath = luaState["package"]["path"];
            luaState["package"]["path"] = "mods/" + modId + "/?.lua;" + currentPath;
        }

        sol::environment modEnv(luaState, sol::create, luaState.globals());
        auto result = luaState.script_file(scriptPath, modEnv);

        if (result.valid()) {
            if (&luaState == &luaServer) {
                mod.setServerEnv(std::move(modEnv));
            } else {
                mod.setClientEnv(std::move(modEnv));
            }
            _debugPrint(modId + "'s '" + modEntry + "' has been loaded successfully");
        } else {
            sol::error err = result;
            _debugPrint("code bad: " + std::string(err.what()));
        }
    }
}

void Loader::refreshServerScripts() {
    refresh(luaServer,&CactusMod::getServerEntry,true);
}

void Loader::refreshClientScripts() {
    refresh(luaClient,&CactusMod::getClientEntry,false);
}

void Loader::execute(sol::environment& (CactusMod::*getEnv)()) {
    for (auto& [name, mod] : mods_) {
        std::string modName = std::string(mod.getName());
        sol::protected_function mainFunc = (mod.*getEnv)()["main"];

        if (mainFunc.valid()) {
            auto result = mainFunc();
            if (!result.valid()) {
                sol::error err = result;
                _debugPrint(("Error in '"+modName+"': "+err.what()).c_str());
            }
        } else {
            _debugPrint(("Mod "+modName+" must have a 'main()' function in its global table, 'function "+modName+".main()' is missing"));
        }
    }
}

void Loader::executeServerScripts() {
    execute(&CactusMod::getServerEnv);
}

void Loader::executeClientScripts() {
    execute(&CactusMod::getClientEnv);
}
