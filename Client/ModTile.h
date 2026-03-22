#pragma once
#include "../../Minecraft.World/Util/Icon.h"
#include "../Minecraft.World/Blocks/Tile.h"
#include "Rendering/ModTextureAtlas.h"
#include "Textures/Stitching/StitchedTexture.h"

class ModTile : public Tile {
    std::wstring m_modTextureName;

public:
    ModTile(int id, Material* material, const std::wstring& modTextureName) : Tile(id, material), m_modTextureName(modTextureName) {}

    int getIconType() const override {
        if (ModTextureAtlas::getInstance() && ModTextureAtlas::getInstance()->isStitchedToTerrain()) {
            return Icon::TYPE_TERRAIN;
        }
        return Icon::TYPE_MOD_TILE;
    }

    Icon* getTexture(int face) override {
        if (!ModTextureAtlas::getInstance()) return nullptr;
        return ModTextureAtlas::getInstance()->getIcon(m_modTextureName);
    }
    Icon* getTexture(int face, int data) override {
        return getTexture(face);
    }
    Icon* getTexture(LevelSource *level, int x, int y, int z, int face) override {
        return getTexture(face);
    }
};
