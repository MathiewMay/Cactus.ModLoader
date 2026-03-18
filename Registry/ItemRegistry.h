#pragma once

#include "../../Minecraft.Client/Utils/StringTable.h"
#include <vector>
#include <string>

class ItemRegistry {
public:
    static int registerItem(const std::string& name);
    static void changeLang(StringTable& m_stringTable);
private:
    static std::vector<std::string> langList;
    static int itemNameIdMax;
    static int itemIdMax;

    static int nextItemNameId();
    static int nextItemId();
};