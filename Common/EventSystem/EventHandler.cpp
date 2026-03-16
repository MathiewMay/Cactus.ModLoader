#include "EventHandler.h"

#include "Events/Player/PlayerBlockBreakEvent.h"
#include "Events/Player/PlayerBlockPlaceEvent.h"
#include "../../Minecraft.Client/Player/ServerPlayerGameMode.h"
#include "../../Minecraft.Client/Player/ServerPlayer.h"
#include "Common/EventSystem/Events/Item/ItemInteractEvent.h"

// todo: maybe rename class? this isnt really a event handler

void EventHandler::registerServerEvents(sol::state& lua) {
    lua.set_function("registerEvent",
        [](const std::string& event_name, sol::function callback) {
            EventBus::Get().registerListener(event_name, sol::protected_function(std::move(callback)));
        });

    lua.new_usertype<CancellableCactusEvent>("CancellableCactusEvent",
        "setCancelled", &CancellableCactusEvent::setCancelled,
        "isCancelled", &CancellableCactusEvent::isCancelled,
        sol::base_classes, sol::bases<CactusEvent>()
        );

    lua.new_usertype<CactusEvent>("CactusEvent",
        "name", &CactusEvent::eventName
        );

    lua.new_usertype<Inventory>("Inventory",
        "setItem", [](Inventory& inv, const int slot, const int itemId) {
            inv.setItem(slot, std::make_shared<ItemInstance>(itemId, 1, 0));
        }
    );

    lua.new_usertype<ServerPlayer>("ServerPlayer",
        "getGamemode", sol::property([](ServerPlayer& p) -> std::string {
            if (p.gameMode->isSurvival()) return "survival";
            if (p.gameMode->isCreative()) return "creative";
            return "unknown";
        }),
        "inventory", &ServerPlayer::inventory,
        "sendMessage", [](ServerPlayer& p, const std::string& message) {
            p.sendMessage(std::wstring(message.begin(), message.end()));
        }
    );

    lua.new_usertype<PlayerBlockBreakEvent>("PlayerBlockBreakEvent",
        "player", &PlayerBlockBreakEvent::player,
        "x", &PlayerBlockBreakEvent::x,
        "y", &PlayerBlockBreakEvent::y,
        "z", &PlayerBlockBreakEvent::z,
        "blockId", &PlayerBlockBreakEvent::blockId,
        sol::base_classes, sol::bases<CancellableCactusEvent, CactusEvent>()
    );

    lua.new_usertype<PlayerBlockPlaceEvent>("PlayerPlaceBlockEvent",
        "player", &PlayerBlockPlaceEvent::player,
        "x", &PlayerBlockPlaceEvent::x,
        "y", &PlayerBlockPlaceEvent::y,
        "z", &PlayerBlockPlaceEvent::z,
        "blockId", &PlayerBlockPlaceEvent::blockId,
        sol::base_classes, sol::bases<CancellableCactusEvent, CactusEvent>()
    );

    lua.new_usertype<ItemInteractEvent>("ItemInteractEvent",
        "item", &ItemInteractEvent::item,
        "level", &ItemInteractEvent::level,
        "player", &ItemInteractEvent::player,
        sol::base_classes, sol::bases<CactusEvent>()
    );
}