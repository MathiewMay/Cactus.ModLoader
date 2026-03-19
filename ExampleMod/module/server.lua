function main()
	registerEvent("PlayerJoinEvent", function(event)
        local player = event.player

        player.inventory:setItem(0, 407)
    end)

    registerEvent("PlayerBlockPlaceEvent", function(event)
        event:setCancelled(false)
    end)

    registerEvent("PlayerBlockBreakEvent", function(event)
        event:setCancelled(false)
    end)

    log("item interact")
    registerEvent("ItemInteract", function(event)
        log(event)
        log(event.level)
        log(event.level.isClientside)
        log(event.level.isClientside())
    end)
    log("did we error")
end
