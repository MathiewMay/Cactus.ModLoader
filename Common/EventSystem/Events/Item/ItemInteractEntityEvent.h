#pragma once

#include "../../CactusEvent.h"

struct ItemInteractEntityEvent final : public CactusEvent {
    ItemInstance* item;
    Mob* mob;

    /* CactusModLoader [IMPL-AT] (Minecraft.World/Item/Item.cpp) */
    ItemInteractEntityEvent(ItemInstance item, Mob &mob) : item(&item), mob(&mob) {
        eventName = "ItemInteractEntity";
    }
};
