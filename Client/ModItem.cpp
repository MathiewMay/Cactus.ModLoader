#include "ModItem.h"
#include "Rendering/ModTextureAtlas.h"
#include "../Minecraft.World/Util/Icon.h"
#include "../Minecraft.World/Util/IconRegister.h"
#include "../Minecraft.Client/Textures/Stitching/StitchedTexture.h"
#include "../Minecraft.World/Items/Item.h"

ModItem::ModItem(int id) : Item(id) {}

int ModItem::getIconType() {
    return Icon::TYPE_MOD_ITEM;
}

void ModItem::registerIcons(IconRegister* iconRegister) {
    StitchedTexture* modIcon = ModTextureAtlas::getInstance()->getIcon(m_textureName);
    if (modIcon != nullptr) {
        icon = modIcon;
        return;
    }
    icon = iconRegister->registerIcon(m_textureName);
}