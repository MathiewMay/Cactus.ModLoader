#pragma once

#include "../../../Common/EventSystem/CactusEvent.h"
#include "../../../../Minecraft.Client/Player/ServerPlayer.h"

struct PlayerBlockBreakEvent final : public CancellableCactusEvent {
    ServerPlayer* player;
    int x, y, z;
    int blockId;

    /* CactusModLoader [IMPL-AT] (Minecraft.Client/Network/PlayerConnection.cpp) */
    PlayerBlockBreakEvent(ServerPlayer* player, int x, int y, int z, int blockId) : player(player), x(x), y(y), z(z), blockId(blockId) {
        eventName = "PlayerBlockBreak";
    }
};
