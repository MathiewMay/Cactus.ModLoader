#include "CactusMod.h"
#include <string_view>
#include "includes/sol/sol.hpp"

std::string_view CactusMod::getName() const {
    return metadata.at("name");
};

std::string_view CactusMod::getModID() const {
    return metadata.at("modId");
};

sol::protected_function CactusMod::getServerFunction(std::string n) {
    return getServerEnv()[n];
};

sol::protected_function CactusMod::getClientFunction(std::string n) {
    return getClientEnv()[n];
};

std::string_view CactusMod::getServerEntry() const {
    return metadata.at("serverMain");
};

std::string_view CactusMod::getClientEntry() const {
    return metadata.at("clientMain");
};

void CactusMod::setServerEnv(sol::environment env) {
    serverEnv = std::move(env);
};

void CactusMod::setClientEnv(sol::environment env) {
    clientEnv = std::move(env);
};

sol::environment& CactusMod::getServerEnv() {
    return serverEnv;
};

sol::environment& CactusMod::getClientEnv() {
    return clientEnv;
};
