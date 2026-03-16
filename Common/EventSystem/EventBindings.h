#pragma once
#include "../../includes/sol/sol.hpp"

class EventBindings {
    public:
        static void bindServerEvents(sol::state& lua);
};