#pragma once

#include <string>
#include "../../includes/sol/sol.hpp"

struct CactusEvent {
    std::string eventName;
};

struct CancellableCactusEvent : public CactusEvent {
    bool cancelled = false;

    void setCancelled(bool value) { cancelled = value; }
    bool isCancelled() const {return cancelled;}
};