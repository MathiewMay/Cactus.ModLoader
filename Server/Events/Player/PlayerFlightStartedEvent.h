#pragma once

#include "../../../Common/EventSystem/CactusEvent.h"
#include "../../../../Minecraft.Client/Player/ServerPlayer.h"

struct PlayerFlightStartedEvent final : public CactusEvent {
    ServerPlayer* player;

    /* CactusModLoader [IMPL-AT] (Minecraft.Client/Network/PendingConnection.cpp) */
    PlayerFlightStartedEvent(ServerPlayer* player) : player(player) {
        eventName = "FlightStartedEvent";
    }
};
