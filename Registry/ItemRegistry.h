#pragma once

#include "../Minecraft.Client/Utils/StringTable.h"
#include <vector>
#include <string>

class ItemRegistry {
public:
    static int registerItem(const std::string& name,  const std::string& texturePath = "");
    static void changeLang(StringTable& m_stringTable);
private:
    static std::vector<std::wstring> langList;
    static int itemNameIdMax;
    static int itemIdMax;

    static int nextItemNameId();
    static int nextItemId();
};