#pragma once
#include "../../includes/sol/sol.hpp"

class EventHandler {
    public:
        static void bindEvents(sol::state& lua);
};