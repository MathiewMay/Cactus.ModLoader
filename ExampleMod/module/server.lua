function main()
	registerEvent("PlayerJoinEvent", function(event)
        local player = event.player

        player.inventory:setItem(0, 1, "example_mod:amethyst_cluster")
        player.inventory:setItem(1, 1, "example_mod:amethyst_block")
        player.inventory:setItem(2, 1, "minecraft:creeper_skull")
    end)

    registerEvent("PlayerBlockPlaceEvent", function(event)
        event:setCancelled(false)
    end)

    registerEvent("PlayerBlockBreakEvent", function(event)
        event:setCancelled(false)
    end)

    registerEvent("ItemInteract", function(event)
        event.player:sendMessage("hi bub")
    end)
end
