function main()
	log("Ran log function from script!")

	number = 8

	log((number+2).."<- this is number 10")

	registerEvent("PlayerBlockBreak", function(event)
		if event.player.gamemode.isSurvival then
            event.player:setGameMode(GameMode.CREATIVE)
			event.player:sendMessage("You are not allowed to break block id "..event.blockId)
			event:setCancelled(true)
		end
	end)

	registerEvent("PlayerBlockPlace", function(event)
		if event.player.gamemode.isSurvival then
			event.player:sendMessage("You are not allowed to place block id "..event.blockId)
			event:setCancelled(true)
		end
	end)
end
