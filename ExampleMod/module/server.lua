function main()
	registerEvent("PlayerJoinEvent", function(event)
        local player = event.player

        player.inventory:setItem(0, 407)
        player:sendMessage("Welcome to the server "+player:getName())
    end)
end
