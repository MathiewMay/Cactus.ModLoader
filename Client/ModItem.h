#pragma once

#include "../Minecraft.World/Items/Item.h"

class IconRegister;

class ModItem : public Item {
public:
    explicit ModItem(int id);

    int getIconType() override;

    void registerIcons(IconRegister *iconRegister) override;
private:
    std::wstring m_textureName;
};