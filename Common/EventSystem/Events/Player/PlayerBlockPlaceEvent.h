#pragma once

#include "../../CactusEvent.h"
#include "../../../Minecraft.Client/Player/ServerPlayer.h"

struct PlayerBlockPlaceEvent final : public CancellableCactusEvent {
    ServerPlayer* player;
    int x, y, z;
    int blockId;

    /* CactusModLoader [IMPL-AT] (Minecraft.World/Items/TileItems/TileItem.cpp) */
    PlayerBlockPlaceEvent(ServerPlayer* player, int x, int y, int z, int blockId) : player(player), x(x), y(y), z(z), blockId(blockId) {
        eventName = "PlayerBlockPlace";
    }
};