#pragma once

#include "Common/EventSystem/EventBus.h"
#include "includes/sol/sol.hpp"
#include "includes/json/json.hpp"

class MinecraftServer;

class Loader {
public:
    Loader();
    void collectMods();

    void registerServerFunctions(MinecraftServer* server);

    static void log(const std::string &message);

    void refreshServerScripts();
    void refreshClientScripts();

    void executeServerScripts();
    void executeClientScripts();

    static void _debugPrint(std::string output);

    std::map<std::string, nlohmann::json> mods_;

    std::map<std::string, std::string> mainServerFiles_;
    std::map<std::string, std::string> mainClientFiles_;

    sol::state luaServer;
    sol::state luaClient;
private:
    static nlohmann::json getManifest(std::string filePath);

    static std::string loadFile(std::string fileName);

    std::map<std::string, sol::environment> serverModEnvironments_;
    std::map<std::string, sol::environment> clientModEnvironments_;
};