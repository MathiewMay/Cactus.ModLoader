function main()
	registerEvent("PlayerJoinEvent", function(event)
        local player = event.player

        player.inventory:setItem(0, 407)
        player.inventory:setItem(1, 408)
    end)

    registerEvent("PlayerBlockPlaceEvent", function(event)
        event:setCancelled(false)
    end)

    registerEvent("PlayerBlockBreakEvent", function(event)
        event:setCancelled(false)
    end)

    registerEvent("ItemInteract", function(event)
        event.player.inventory:setItem(0,5915215)
        event.player:sendMessage("hi bub")
    end)
end
