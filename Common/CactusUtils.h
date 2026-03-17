#pragma once

#include "../../Minecraft.World/Items/TileItems/TileItem.h"
#include "../../Minecraft.World/Items/TileItems/PlanterTileItem.h"
#include "../../Minecraft.World/Items/TileItems/SkullItem.h"
#include "../../Minecraft.World/Items/TileItems/WaterLilyTileItem.h"
#include "../../Minecraft.World/Items/SignItem.h"
#include "../../Minecraft.World/Items/DoorItem.h"
#include "../../Minecraft.World/Items/BedItem.h"

class Item;

static bool isPlaceableItem(Item* item) {
    if (item == nullptr) return false;
    return dynamic_cast<TileItem*>(item) != nullptr ||
           dynamic_cast<TilePlanterItem*>(item) != nullptr ||
           dynamic_cast<SkullItem*>(item) != nullptr ||
           dynamic_cast<WaterLilyTileItem*>(item) != nullptr ||
           dynamic_cast<SignItem*>(item) != nullptr ||
           dynamic_cast<DoorItem*>(item) != nullptr ||
           dynamic_cast<BedItem*>(item) != nullptr;
}