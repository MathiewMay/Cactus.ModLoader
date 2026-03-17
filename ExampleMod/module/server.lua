function main()
	registerEvent("PlayerJoinEvent", function(event)
        local player = event.player
    end)

    registerEvent("PlayerBlockPlaceEvent", function(event)
        event:setCancelled(true)
    end)

    registerEvent("PlayerBlockBreakEvent", function(event)
        local players = server:getPlayers()

        for i = 1, #players do
            local player = players[i]
            player:sendMessage("FUCK WAD")
        end

        event:setCancelled(true)
    end)
end
