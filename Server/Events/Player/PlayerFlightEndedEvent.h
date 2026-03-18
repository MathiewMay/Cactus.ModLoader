#pragma once

#include "../../../Common/EventSystem/CactusEvent.h"
#include "../../../../Minecraft.Client/Player/ServerPlayer.h"

struct PlayerFlightEndedEvent final : public CactusEvent {
    ServerPlayer* player;

    /* CactusModLoader [IMPL-AT] (Minecraft.Client/Network/PendingConnection.cpp) */
    PlayerFlightEndedEvent(ServerPlayer* player) : player(player) {
        eventName = "FlightEndedEvent";
    }
};
