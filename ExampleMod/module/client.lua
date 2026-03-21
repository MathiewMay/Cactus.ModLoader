function main()
    local id = registerItem("Amethyst Cluster", "/amethyst_cluster.png", ItemDefinition.new({
        base=EBaseItem.Weapon,
        tier=Tier.new(3, 5000, 5000, 5000, 5000)
    }))

    log(tostring(id))
end