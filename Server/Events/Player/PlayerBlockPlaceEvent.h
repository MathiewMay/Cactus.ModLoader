#pragma once

#include "../../../Common/EventSystem/CactusEvent.h"
#include "../../../../Minecraft.Client/Player/ServerPlayer.h"

struct PlayerBlockPlaceEvent final : public CancellableCactusEvent {
    ServerPlayer* player;
    int x, y, z;
    int blockId;

    /* CactusModLoader [IMPL-AT] (Minecraft.Client/Network/PlayerConnection.cpp) */
    PlayerBlockPlaceEvent(ServerPlayer* player, int x, int y, int z, int blockId) : player(player), x(x), y(y), z(z), blockId(blockId) {
        eventName = "PlayerBlockPlaceEvent";
    }
};