//
// Created by mathiew on 2026-03-14.
//

#ifndef INC_4JCRAFT_LOADER_H
#define INC_4JCRAFT_LOADER_H

#include "Common/EventSystem/EventBus.h"
#include "includes/sol/sol.hpp"
#include "includes/json/json.hpp"

class Loader {
    public:
        Loader();

        void registerServerFunctions();
        void collectMods();

        void refreshServerScripts();
        void refreshClientScripts();

        static int getModCount();
        void loadMods();

        void executeServerScripts();
        void executeClientScripts();

        static void _debugPrint(std::string output);

        std::map<std::string, nlohmann::json> mods_;

        std::map<std::string, std::string> mainServerFiles_;
        std::map<std::string, std::string> mainClientFiles_;

        sol::state luaServer;
        sol::state luaClient;
    private:
        static void log(std::string message);

        static nlohmann::json getManifest(std::string filePath);

        static std::string loadFile(std::string fileName);

        void test(std::string event, sol::function func);


        std::map<std::string, sol::environment> serverModEnvironments_;
        std::map<std::string, sol::environment> clientModEnvironments_;
};


#endif //INC_4JCRAFT_LOADER_H