#pragma once

struct LuaVec3 {
    double x, y, z;
    LuaVec3(double x, double y, double z) : x(x), y(y), z(z) {}
    double distanceTo(const LuaVec3& target) const {
        return std::sqrt(std::pow(x-target.x, 2) + std::pow(y-target.y, 2) + std::pow(z-target.z, 2) );
    }
    std::string toString() const {
        return "Vec3(x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", z: " + std::to_string(z) + ")";
    }
};

struct LuaBlock {
    LuaVec3 pos;
    int id;
};