#pragma once
#include <unordered_map>
#include <utility>

class Item;

class IDMapping {
public:
    struct MappedItem {
        int id;
        bool isBlock;
    };

    static std::unordered_map<std::string, MappedItem> stringToID;
    static void staticCtor();
    static void add(std::string ns, std::string name, bool isBlock, int id);
    static std::pair<bool,int> get(std::string k);
};