#pragma once
#include "../../includes/sol/sol.hpp"

class EventHandler {
    public:
        static void registerServerEvents(sol::state& lua);
};