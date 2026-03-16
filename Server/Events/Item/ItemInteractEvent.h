#pragma once

#include "../../../Common/EventSystem/CactusEvent.h"
#include "../../../../Minecraft.Client/Player/ServerPlayer.h"

struct ItemInteractEvent final : public CactusEvent {
    ItemInstance* item;
    ServerLevel* level;
    ServerPlayer* player;


    /* CactusModLoader [IMPL-AT] (Minecraft.World/Item/Item.cpp) */
    ItemInteractEvent(ItemInstance item, ServerLevel* level, ServerPlayer player) : item(&item), level(level), player(&player) {
        eventName = "ItemInteract";
    }
};
