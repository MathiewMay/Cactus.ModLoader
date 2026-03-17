#include "EventBindings.h"

#include "../Minecraft.Client/Player/ServerPlayerGameMode.h"
#include "../Minecraft.Client/Player/ServerPlayer.h"
#include "../Minecraft.World/Level/Storage/LevelSettings.h"

/* Server Includes */
#include "Server/Events/Item/ItemInteractEvent.h"
#include "Server/Events/Player/PlayerBlockBreakEvent.h"
#include "Server/Events/Player/PlayerBlockPlaceEvent.h"
#include "Server/Events/Player/PlayerConnectionEvent.h"
#include "Server/Events/Player/PlayerJoinEvent.h"
#include "EventBus.h"

void EventBindings::bindServerEvents(sol::state& lua) {
    lua.set_function("registerEvent",
        [](const std::string& event_name, sol::function callback) {
            EventBus::Get().registerListener(event_name, sol::protected_function(std::move(callback)));
        }
    );

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
        },
        "getItem", [](Inventory& inv, const int slot) {
            return inv.getItem(slot);
        }
    );

    lua.new_usertype<ItemInstance>("ItemInstance",
        "getHoverName", [](ItemInstance& item) {
            return item.getHoverName();
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
        "canFly", &ServerPlayer::isAllowedToFly,
        "getViewDistance", [](ServerPlayer& player) {
            return player.getViewDistance();
        },
        "displayName", &ServerPlayer::displayName,
        "experience",  &ServerPlayer::experienceProgress,
        "flySpeed", &ServerPlayer::flyingSpeed,
        "level", &ServerPlayer::experienceLevel,
        "name", &ServerPlayer::name,
        "walkSpeed", &ServerPlayer::walkingSpeed,
        "giveExp", [](ServerPlayer& player, float amount) {
            player.experienceProgress += amount;
        },
        "giveExpLevels", [](ServerPlayer& player, int amount) {
            player.experienceLevel += amount;
        },
        "setExp", [](ServerPlayer& player, float amount) {
            player.experienceProgress = amount;
        },
        "setLevel", [](ServerPlayer& player, float amount) {
            player.experienceLevel = amount;
        },
        "gamemode", &ServerPlayer::gameMode,
        "inventory", &ServerPlayer::inventory,
        "setGameMode", [](ServerPlayer& player, int gameTypeId) {
            GameType* type = GameType::byId(gameTypeId);
            if (type) player.setGameMode(type);
        },
        "sendMessage", [](ServerPlayer& p, const std::wstring& message) {
            p.sendMessage(message);
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

    lua.new_usertype<PlayerConnectionEvent>("PlayerConnectionEvent",
        "player", &PlayerConnectionEvent::player,
        sol::base_classes, sol::bases<CactusEvent>()
    );

    lua.new_usertype<PlayerJoinEvent>("PlayerJoinEvent",
        "player", &PlayerJoinEvent::player,
        sol::base_classes, sol::bases<CactusEvent>()
    );
}
