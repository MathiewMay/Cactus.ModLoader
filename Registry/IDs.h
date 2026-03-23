#pragma once

#include <unordered_map>

class Item;

class IDMapping {
public:
    struct MappedItem {
        int id;
        bool isBlock;
        int aux;
    };

    static std::unordered_map<std::string, MappedItem> stringToID;
    static void staticCtor();
    static void add(std::string ns, std::string name, bool isBlock, int id);

    static MappedItem get(std::string k);
};