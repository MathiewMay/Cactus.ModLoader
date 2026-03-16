#include "EventBindings.h"

#include "../Minecraft.Client/Player/ServerPlayerGameMode.h"
#include "../Minecraft.Client/Player/ServerPlayer.h"
#include "../Minecraft.World/Level/Storage/LevelSettings.h"

/* Server Includes */
#include "Server/Events/Item/ItemInteractEvent.h"
#include "Server/Events/Player/PlayerBlockBreakEvent.h"
#include "Server/Events/Player/PlayerBlockPlaceEvent.h"

void EventBindings::bindServerEvents(sol::state& lua) {
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

    lua.new_usertype<ServerPlayerGameMode>("ServerPlayerGameMode",
        "isSurvival", sol::property(&ServerPlayerGameMode::isSurvival),
        "isCreative", sol::property(&ServerPlayerGameMode::isCreative)
    );

    lua["GameMode"] = sol::table(lua, sol::create);
    lua["GameMode"]["NOT_SET"]   = 0;
    lua["GameMode"]["SURVIVAL"]  = 0;
    lua["GameMode"]["CREATIVE"]  = 1;
    lua["GameMode"]["ADVENTURE"] = 2;

    lua.new_usertype<ServerPlayer>("ServerPlayer",
        "gamemode", &ServerPlayer::gameMode,
        "inventory", &ServerPlayer::inventory,
        "setGameMode", [](ServerPlayer& player, int gameTypeId) {
            GameType* type = GameType::byId(gameTypeId);
            if (type) player.setGameMode(type);
        },
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

    lua.new_usertype<PlayerBlockPlaceEvent>("PlayerBlockPlaceEvent",
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