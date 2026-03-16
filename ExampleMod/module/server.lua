function main()
	log("Ran log function from script!")

	number = 8

	log((number+2).."<- this is number 10")

	registerEvent("PlayerBlockBreak", function(event)
		if event.player.gamemode ~= "creative" then
			event.player.inventory:setItem(0, 407)
			event.player.inventory:setItem(1, 408)
			event.player:sendMessage("You are not allowed to break block id "..event.blockId)
			event:setCancelled(true)
		end
	end)

	registerEvent("PlayerBlockPlace", function(event)
		if event.player.gamemode ~= "creative" then
			event.player:sendMessage("You are not allowed to place block id "..event.blockId.." located")
			event:setCancelled(true)
		end
	end)
end
