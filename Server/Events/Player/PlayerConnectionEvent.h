#pragma once

#include "../../../Common/EventSystem/CactusEvent.h"
#include "../../../../Minecraft.Client/Player/ServerPlayer.h"

struct PlayerConnectionEvent final : public CactusEvent {
    ServerPlayer* player;

    /* CactusModLoader [IMPL-AT] (Minecraft.Client/Network/PendingConnection.cpp) */
    PlayerConnectionEvent(ServerPlayer* player) : player(player) {
        eventName = "PlayerConnectionEvent";
    }
};
