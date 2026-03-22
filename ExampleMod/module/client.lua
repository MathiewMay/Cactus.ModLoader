function main()
    local id = registerItem("amethyst_cluster", "Amethyst Cluster", "/amethyst_cluster.png", ItemDefinition.new({
         base=EBaseItem.Weapon,
         tier=Tier.new(3, 5000, 5000, 5000, 5000)
     }))
    id2 = registerBlock("amethyst_block", "Amethyst Block", "/amethyst_block.png", "")
    id2 = registerBlock("andesite", "Andesite", "/andesite.png", "")


    log(tostring(id))
    log(tostring(id2))
end