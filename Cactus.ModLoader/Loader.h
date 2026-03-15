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

        void registerFunctions();
        void collectMods();
        static int getModCount();
        void loadMods();

        static void _debugPrint(std::string output);

        std::map<std::string, std::map<std::string, std::any>> mods_;

        sol::state lua;
    private:
        static void log(std::string message);

        static nlohmann::json getManifest(std::string filePath);

        static std::string loadFile(std::string fileName);

        void test(std::string event, sol::function func);


        std::map<std::string, sol::load_result> compiledScripts_;
};


#endif //INC_4JCRAFT_LOADER_H