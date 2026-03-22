#include "BlockRegistry.h"

#include <set>
#include <unordered_map>
#include "ItemRegistry.h"
#include "../Minecraft.World/Blocks/Tile.h"
#include "../../Minecraft.World/Items/TileItems/TileItem.h"
#include "../Client/Rendering/ModTextureAtlas.h"
#include "../Minecraft.World/Items/Item.h"
#include "../Minecraft.World/Blocks/Material.h"
#include "DurangoMedia/loc/strings.h"

struct blockData {
    std::wstring modId;
    std::string name;
    std::string texturePath;
    int nameId;
    int itemId;

    blockData(const std::wstring& modId, const std::string& name, const std::string& texturePath, int nameId, int itemId) :
        modId(modId), name(name), texturePath(texturePath), nameId(nameId), itemId(itemId) {}

    bool operator<(const blockData& other) const {
        return nameId < other.nameId && itemId < other.itemId;
    }
};

std::multiset<blockData> toInit;

int BlockRegistry::registerBlock(const std::wstring& modId, const std::string& name, const std::string& texturePath) {
    int nameId = ItemRegistry::nextItemNameId();
    int itemId = ItemRegistry::nextItemId();

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

            Tile* tile = (new Tile(itemId, Material::dirt))
                ->setTextureName(wname)
                ->setDescriptionId(nameId)
                ->setUseDescriptionId(IDS_DESC_STICK);

            Item::items[itemId] = (new TileItem(itemId - 256))
                ->setTextureName(wname)
                ->handEquipped()
                ->setDescriptionId(nameId)
                ->setUseDescriptionId(IDS_DESC_STICK);
        } else {
            (new Tile(itemId, Material::grass, true))->setTextureName(L"dirt")->setDescriptionId(nameId)->setUseDescriptionId(IDS_DESC_ANVIL);
            Item::items[itemId] = (new TileItem(itemId-256))->setTextureName(L"stick")->handEquipped()->setDescriptionId(nameId)->setUseDescriptionId(IDS_DESC_STICK);
        }
    }


    ItemRegistry::langList[nameId] = wname;
    return itemId;
}