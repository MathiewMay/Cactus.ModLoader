#pragma once

#include "../../../Common/EventSystem/CactusEvent.h"
#include "../../../../Minecraft.Client/Player/ServerPlayer.h"

struct PlayerJoinEvent final : public CactusEvent {
    ServerPlayer* player;

    /* CactusModLoader [IMPL-AT] (Minecraft.Client/Network/PlayerList.cpp) */
    PlayerJoinEvent(ServerPlayer* player) : player(player) {
        eventName = "PlayerJoinEvent";
    }
};
