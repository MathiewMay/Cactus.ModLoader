//
// Created by mathiew on 2026-03-14.
//

#ifndef INC_4JCRAFT_LOADER_H
#define INC_4JCRAFT_LOADER_H

#include "Common/EventSystem/EventBus.h"
#include "../../Minecraft.Client/Utils/StringTable.h"
#include "includes/sol/sol.hpp"
#include "includes/json/json.hpp"

class Loader {
    public:
        Loader();
        void collectMods();

        void registerServerFunctions();


        void changeLang(StringTable &m_stringTable);

        void refreshServerScripts();
        void refreshCommonScripts();
        void refreshClientScripts();

        void executeServerScripts();
        void executeCommonScripts();
        void executeClientScripts();

        static void _debugPrint(std::string output);

        std::map<std::string, nlohmann::json> mods_;

        std::map<std::string, std::string> mainServerFiles_;
        std::map<std::string, std::string> mainClientFiles_;
        std::map<std::string, std::string> mainCommonFiles_;

        sol::state luaServer;
        sol::state luaClient;
        sol::state luaCommon;
    private:
        static void log(std::string message);

        static nlohmann::json getManifest(std::string filePath);

        void registerCommonFunctions();
        void registerClientFunctions();

        static std::string loadFile(std::string fileName);

        void test(std::string event, sol::function func);

        std::map<std::string, sol::environment> serverModEnvironments_;
        std::map<std::string, sol::environment> clientModEnvironments_;
        std::map<std::string, sol::environment> commonModEnvironments_;
};


#endif //INC_4JCRAFT_LOADER_H