function main()
    local id = registerItem("Amethyst Cluster", "/amethyst_cluster.png", ItemDefinition.new({
         base=EBaseItem.Weapon,
         tier=Tier.new(3, 5000, 5000, 5000, 5000)
     }))
    id2 = registerBlock("Amethyst Block", "/amethyst_block.png", "")


    log(tostring(id))
    log(tostring(id2))
end