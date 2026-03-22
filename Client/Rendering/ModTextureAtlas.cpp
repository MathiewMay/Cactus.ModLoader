#include "ModTextureAtlas.h"

#include "../../Minecraft.Client/Textures/Texture.h"
#include "../../Minecraft.Client/Textures/TextureManager.h"
#include "../../Minecraft.Client/Textures/BufferedImage.h"
#include "../../Minecraft.Client/Textures/TextureHolder.h"
#include "../../Minecraft.Client/UI/SimpleIcon.h"
#include "../../Minecraft.Client/Textures/Stitching/StitchedTexture.h"
#include "../../Minecraft.Client/Textures/Stitching/StitchSlot.h"
#include "../../Minecraft.Client/Textures/Stitching/Stitcher.h"

#include <cstring>

#include "Textures/Stitching/PreStitchedTextureMap.h"

ModTextureAtlas* ModTextureAtlas::instance = nullptr;

void ModTextureAtlas::createInstance() {
    instance = new ModTextureAtlas();
}

ModTextureAtlas* ModTextureAtlas::getInstance() {
    return instance;
}

void ModTextureAtlas::registerTexture(const std::wstring& name, std::vector<int> pixels, int width, int height) {
    if (built) {
        built = false;
        pending.clear();
    }
    pending.push_back({ name, std::move(pixels), width, height });
}

void ModTextureAtlas::build() {
    if (pending.empty()) return;

    const std::wstring atlasName = L"mod_atlas";

    if (atlasTexture != nullptr) {
        TextureManager::getInstance()->unregisterTexture(atlasName, atlasTexture);
        delete atlasTexture;
        atlasTexture = nullptr;
    }

    Stitcher stitcher(atlasName, MAX_ATLAS_SIZE, MAX_ATLAS_SIZE, true);

    std::vector<Texture*> tempTextures;
    std::vector<TextureHolder*> holders;

    std::unordered_map<TextureHolder*, std::wstring> holderNames;

    for (const PendingTexture& pt : pending) {
        BufferedImage* img = new BufferedImage(pt.width, pt.height, BufferedImage::TYPE_INT_ARGB);
        memcpy(img->getData(), pt.pixels.data(), pt.width * pt.height * sizeof(int));

        Texture* tex = TextureManager::getInstance()->createTexture(pt.name, Texture::TM_CONTAINER, pt.width, pt.height, Texture::TFMT_RGBA, false);
        tex->transferFromImage(img);
        delete img;

        TextureHolder* holder = new TextureHolder(tex);
        holderNames[holder] = pt.name;
        stitcher.addTexture(holder);
        tempTextures.push_back(tex);
        holders.push_back(holder);
    }

    stitcher.stitch();
    std::vector<StitchSlot*>* slots = stitcher.gatherAreas();
    atlasTexture = stitcher.constructTexture(false);
    atlasTexture->updateOnGPU();

    for (auto& kv : icons) delete kv.second;
    icons.clear();

    for (StitchSlot* slot : *slots) {
        TextureHolder* holder = slot->getHolder();
        auto it = holderNames.find(holder);
        if (it == holderNames.end()) continue;
        const std::wstring& name = it->second;

        SimpleIcon* icon = new SimpleIcon(name, 0.0f, 0.0f, 1.0f, 1.0f);
        icon->init(atlasTexture, nullptr, slot->getX(), slot->getY(), holder->getWidth(), holder->getHeight(), holder->isRotated());
        icons[name] = icon;
    }
    delete slots;

    for (TextureHolder* h : holders) delete h;

    //pending.clear();
    built = true;
}

StitchedTexture* ModTextureAtlas::getIcon(const std::wstring& name) {
    auto it = icons.find(name);
    if (it != icons.end()) return it->second;
    return nullptr;
}

bool ModTextureAtlas::isModIcon(Icon* icon) {
    for (auto& kv : icons) {
        if (kv.second == icon) return true;
    }
    return false;
}

int ModTextureAtlas::getAtlasGlId() {
    return atlasTexture ? atlasTexture->getGlId() : -1;
}

void ModTextureAtlas::registerPendingTexturesIntoTerrainAtlas(PreStitchedTextureMap *terrainMap) {
    for (const PendingTexture& pendingTexture : pending) {
        terrainMap->registerIconFromPixels(pendingTexture.name, pendingTexture.pixels, pendingTexture.width, pendingTexture.height);
    }
}

void ModTextureAtlas::finalizeIntoTerrainMap(PreStitchedTextureMap* terrainMap) {
    if (pending.empty()) return;

    std::vector<std::pair<std::wstring, std::vector<int>>> modTextures;
    for (const PendingTexture& pt : pending) {
        modTextures.push_back({ pt.name, pt.pixels });
    }

    terrainMap->expandWithModTextures(modTextures, 16, 16);

    for (const PendingTexture& pt : pending) {
        Icon* icon = terrainMap->registerIcon(pt.name);
        if (icon) icons[pt.name] = dynamic_cast<StitchedTexture*>(icon);
    }

    pending.clear();
    stitchedIntoTerrain = true;
}
