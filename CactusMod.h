#pragma once

#include <string>
#include <unordered_map>
#include "includes/sol/sol.hpp"

class CactusMod {
private:
    typedef std::unordered_map<std::string, std::string> Mapping;
    sol::environment serverEnv;
    sol::environment clientEnv;
public:
    Mapping metadata;

    CactusMod() = default;
    ~CactusMod() = default;

    std::string_view getName() const;
    std::string_view getModID() const;
    
    sol::protected_function getServerFunction(std::string n);
    sol::protected_function getClientFunction(std::string n);

    std::string_view getServerEntry() const;
    std::string_view getClientEntry() const;

    void setServerEnv(sol::environment env);
    void setClientEnv(sol::environment env);

    sol::environment& getServerEnv();
    sol::environment& getClientEnv();
};