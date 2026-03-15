#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <type_traits>
#include "../../includes/sol/sol.hpp"
#include "CactusEvent.h"

class EventBus {
public:
    using Listener = sol::protected_function;

    static EventBus& Get() {
        static EventBus instance;
        return instance;
    }

    void registerListener(const std::string& eventName, Listener listener) {
        listeners_[eventName].push_back(std::move(listener));
    }

    void clearListeners() {
        listeners_.clear();
    }

    template<typename E>
    bool fire(E& event) {
        auto it = listeners_.find(event.eventName);
        if (it == listeners_.end()) return false;

        bool wasCanceled = false;
        for (auto& fn : it->second) {
            if (!fn.valid()) continue;
            auto result = fn(&event);

            if (result.valid() && result.get_type() == sol::type::boolean && result.template get<bool>()) {
                if constexpr (std::is_base_of_v<CancellableCactusEvent, E>) {
                    event.setCancelled(true);
                }
            }
            if constexpr (std::is_base_of_v<CancellableCactusEvent, E>) {
                if (event.isCancelled()) wasCanceled = true;
            }
        }
        return wasCanceled;
    }

private:
    EventBus() = default;
    std::unordered_map<std::string, std::vector<Listener>> listeners_;
};