function main()
	registerEvent("PlayerJoinEvent", function(event)
        local player = event.player

        player.inventory:setItem(0, "example_mod:amethyst_cluster")
        player.inventory:setItem(1, "example_mod:amethyst_block")
        player.inventory:setItem(2, "example_mod:andesite")
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
