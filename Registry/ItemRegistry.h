#pragma once

#include "../Minecraft.Client/Utils/StringTable.h"
#include <vector>
#include <string>

struct ItemDefinition;

class ItemRegistry {
    public:
        static int registerItem(const std::wstring& modId, const std::string& name,  const std::string& itemTextPath = "");
        static void changeLang(StringTable& m_stringTable);

        static int nextItemNameId();
        static int nextItemId();
        static std::vector<std::wstring> langList; //keep these 3 public for block registry

    private:
        static int itemNameIdMax;
        static int itemIdMax;
};