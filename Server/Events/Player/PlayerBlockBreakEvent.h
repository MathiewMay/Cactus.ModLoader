#pragma once

#include "../../../Common/EventSystem/CactusEvent.h"
#include "../../../../Minecraft.Client/Player/ServerPlayer.h"
#include "Lua/LuaStructs.h"

struct PlayerBlockBreakEvent final : public CancellableCactusEvent {
    ServerPlayer* player;
    LuaBlock block;

    /* CactusModLoader [IMPL-AT] (Minecraft.Client/Network/PlayerConnection.cpp) */
    PlayerBlockBreakEvent(ServerPlayer* player, int x, int y, int z, int blockId) : player(player), block{LuaVec3(x,y,z), blockId} {
        eventName = "PlayerBlockBreakEvent";
    }
};
