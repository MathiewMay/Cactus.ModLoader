#include "ItemRegistry.h"
#include "Client/Rendering/ModTextureAtlas.h"
#include "../Minecraft.World/Items/Item.h"
#include "DurangoMedia/loc/strings.h"

std::vector<std::wstring> ItemRegistry::langList(2000);
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

int ItemRegistry::registerItem(const std::wstring& modId, const std::string& name, const std::string& texturePath) {
    int nameId = nextItemNameId();
    int itemId = nextItemId();

    std::wstring wname(name.begin(), name.end());

    if (!texturePath.empty() && ModTextureAtlas::getInstance() != nullptr) {
        std::wstring wpath(texturePath.begin(), texturePath.end());

        BufferedImage* img = new BufferedImage(wpath, true, false, L"mods/"+modId+L"/");

        if (img != nullptr) {
            int w = img->getWidth();
            int h = img->getHeight();

            std::vector<int> pixels(w*h);
            intArray wrapper(pixels.data(), w*h);
            img->getRGB(0,0,w,h,wrapper,0,w);

            ModTextureAtlas::getInstance()->registerTexture(wname, std::move(pixels), w, h);
            delete img;

            Item::items[itemId] = (new Item(itemId - 256))
            ->setTextureName(wname)
            ->handEquipped()
            ->setDescriptionId(nameId)
            ->setUseDescriptionId(IDS_DESC_STICK);
        }else {
            Item::items[itemId] = (new Item(itemId))->setTextureName(L"stick")->handEquipped()->setDescriptionId(nameId)->setUseDescriptionId(IDS_DESC_STICK);
        }
    }


    langList[nameId] = wname;
    return itemId;
}

void ItemRegistry::changeLang(StringTable& m_stringTable) {
    // So c++ just deprecated wstring_convert with no alternative 🥀 either way we could just have used wstring from the start instead of storing langList as a list of strings
    for (size_t i = 0; i < langList.size(); i++) {
        if (langList[i].empty()) continue;
        m_stringTable.addData(i, langList[i]);
    }
}