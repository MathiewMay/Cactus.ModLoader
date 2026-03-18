#include "ItemRegistry.h"
#include "../../Minecraft.World/Items/Item.h"

std::vector<std::string> ItemRegistry::langList(2000);
int ItemRegistry::itemNameIdMax = 1937;
int ItemRegistry::itemIdMax = 406;

int ItemRegistry::nextItemNameId() {
    itemNameIdMax += 1;
    return itemNameIdMax;
}

int ItemRegistry::nextItemId() {
    itemIdMax += 1;
    return itemIdMax;
}

int ItemRegistry::registerItem(const std::string& name) {
    int nameId = nextItemNameId();
    int itemId = nextItemId();

    Item::items[itemId] = (new Item(itemId))->setTextureName(L"stick")->handEquipped()->setDescriptionId(nameId)->setUseDescriptionId(IDS_DESC_STICK);

    langList[nameId] = name;
    return itemId;
}

void ItemRegistry::changeLang(StringTable& m_stringTable) {
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    for (size_t i = 0; i < langList.size(); i++) {
        if (langList[i].empty()) continue;

        const char* text = langList[i].c_str();
        std::wstring wtext = std::wstring(text, text + strlen(text));
        m_stringTable.addData(i, wtext);
        app.DebugPrintf("[Lua] ");
        app.DebugPrintf(to_string(i).c_str());
        app.DebugPrintf(" is the id for: \n");
        app.DebugPrintf(("[Lua] "+converter.to_bytes(m_stringTable.getString(i))+"\n").c_str());
    }
}