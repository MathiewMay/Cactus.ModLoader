#include "IDs.h"

#include "Minecraft.World/Items/Item.h"
#include "Minecraft.World/Blocks/Tile.h"

std::unordered_map<std::string, IDMapping::MappedItem> IDMapping::stringToID;

void IDMapping::add(std::string ns, std::string name, bool isBlock, int id) {
    std::string n = ns+":"+name;
    stringToID[n] = { id, isBlock, 0 };
}

IDMapping::MappedItem IDMapping::get(std::string k) {
    auto it = stringToID.find(k);
    if (it != stringToID.end()) {
        return it->second;
    }
    return { 0, false, 0 };
}

/* WARNING!!! Boilerplate HELL!!! Want it reduced? USE A FAWKIN MACRO!!! */

void IDMapping::staticCtor() {
    /* Blocks */
    stringToID["minecraft:stone"] = { Tile::rock_Id, true, 0 };
    stringToID["minecraft:grass_block"] = { Tile::grass_Id, true, 0 };
    stringToID["minecraft:dirt"] = { Tile::dirt_Id, true, 0 };
    stringToID["minecraft:cobblestone"] = { Tile::stoneBrick_Id, true, 0 };
    stringToID["minecraft:oak_planks"] = { Tile::wood_Id, true, 0 };
    stringToID["minecraft:spruce_planks"] = { Tile::wood_Id, true, 1 };
    stringToID["minecraft:birch_planks"] = { Tile::wood_Id, true, 2 };
    stringToID["minecraft:jungle_planks"] = { Tile::wood_Id, true, 3 };
    stringToID["minecraft:oak_sapling"] = { Tile::sapling_Id, true, 0 };
    stringToID["minecraft:spruce_sapling"] = { Tile::sapling_Id, true, 1 };
    stringToID["minecraft:birch_sapling"] = { Tile::sapling_Id, true, 2 };
    stringToID["minecraft:jungle_sapling"] = { Tile::sapling_Id, true, 3 };
    stringToID["minecraft:bedrock"] = { Tile::unbreakable_Id, true, 0 };
    stringToID["minecraft:flowing_water"] = { Tile::water_Id, true, 0 };
    stringToID["minecraft:water"] = { Tile::calmWater_Id, true, 0 };
    stringToID["minecraft:flowing_lava"] = { Tile::lava_Id, true, 0 };
    stringToID["minecraft:lava"] = { Tile::calmLava_Id, true, 0 };
    stringToID["minecraft:sand"] = { Tile::sand_Id, true, 0 };
    stringToID["minecraft:gravel"] = { Tile::gravel_Id, true, 0 };
    stringToID["minecraft:gold_ore"] = { Tile::goldOre_Id, true, 0 };
    stringToID["minecraft:iron_ore"] = { Tile::ironOre_Id, true, 0 };
    stringToID["minecraft:coal_ore"] = { Tile::coalOre_Id, true, 0 };
    stringToID["minecraft:oak_log"] = { Tile::treeTrunk_Id, true, 0 };
    stringToID["minecraft:spruce_log"] = { Tile::treeTrunk_Id, true, 1 };
    stringToID["minecraft:birch_log"] = { Tile::treeTrunk_Id, true, 2 };
    stringToID["minecraft:jungle_log"] = { Tile::treeTrunk_Id, true, 3 };
    stringToID["minecraft:oak_leaves"] = { Tile::leaves_Id, true, 0 };
    stringToID["minecraft:spruce_leaves"] = { Tile::leaves_Id, true, 1 };
    stringToID["minecraft:birch_leaves"] = { Tile::leaves_Id, true, 2 };
    stringToID["minecraft:jungle_leaves"] = { Tile::leaves_Id, true, 3 };
    stringToID["minecraft:sponge"] = { Tile::sponge_Id, true, 0 };
    stringToID["minecraft:glass"] = { Tile::glass_Id, true, 0 };
    stringToID["minecraft:lapis_ore"] = { Tile::lapisOre_Id, true, 0 };
    stringToID["minecraft:lapis_block"] = { Tile::lapisBlock_Id, true, 0 };
    stringToID["minecraft:dispenser"] = { Tile::dispenser_Id, true, 0 };
    stringToID["minecraft:sandstone"] = { Tile::sandStone_Id, true, 0 };
    stringToID["minecraft:chiseled_sandstone"] = { Tile::sandStone_Id, true, 1 };
    stringToID["minecraft:cut_sandstone"] = { Tile::sandStone_Id, true, 2 };
    stringToID["minecraft:note_block"] = { Tile::musicBlock_Id, true, 0 };
    stringToID["minecraft:bed"] = { Tile::bed_Id, true, 0 };
    stringToID["minecraft:golden_rail"] = { Tile::goldenRail_Id, true, 0 };
    stringToID["minecraft:detector_rail"] = { Tile::detectorRail_Id, true, 0 };
    stringToID["minecraft:sticky_piston"] = { Tile::pistonStickyBase_Id, true, 0 };
    stringToID["minecraft:web"] = { Tile::web_Id, true, 0 };
    stringToID["minecraft:dead_bush"] = { Tile::tallgrass_Id, true, 0 };
    stringToID["minecraft:grass"] = { Tile::tallgrass_Id, true, 1 };
    stringToID["minecraft:fern"] = { Tile::tallgrass_Id, true, 2 };
    //stringToID["minecraft:dead_bush"] = { Tile::deadBush_Id, true, 0 }; // no clue what this is but you can't place it down so
    stringToID["minecraft:piston"] = { Tile::pistonBase_Id, true, 0 };
    stringToID["minecraft:piston_head"] = { Tile::pistonExtensionPiece_Id, true, 0 };
    stringToID["minecraft:white_wool"] = { Tile::cloth_Id, true, 0 };
    stringToID["minecraft:orange_wool"] = { Tile::cloth_Id, true, 1 };
    stringToID["minecraft:magenta_wool"] = { Tile::cloth_Id, true, 2 };
    stringToID["minecraft:light_blue_wool"] = { Tile::cloth_Id, true, 3 };
    stringToID["minecraft:yellow_wool"] = { Tile::cloth_Id, true, 4 };
    stringToID["minecraft:lime_wool"] = { Tile::cloth_Id, true, 5 };
    stringToID["minecraft:pink_wool"] = { Tile::cloth_Id, true, 6 };
    stringToID["minecraft:gray_wool"] = { Tile::cloth_Id, true, 7 };
    stringToID["minecraft:light_gray_wool"] = { Tile::cloth_Id, true, 8 };
    stringToID["minecraft:cyan_wool"] = { Tile::cloth_Id, true, 9 };
    stringToID["minecraft:purple_wool"] = { Tile::cloth_Id, true, 10 };
    stringToID["minecraft:blue_wool"] = { Tile::cloth_Id, true, 11 };
    stringToID["minecraft:brown_wool"] = { Tile::cloth_Id, true, 12 };
    stringToID["minecraft:green_wool"] = { Tile::cloth_Id, true, 13 };
    stringToID["minecraft:red_wool"] = { Tile::cloth_Id, true, 14 };
    stringToID["minecraft:black_wool"] = { Tile::cloth_Id, true, 15 };
    //stringToID["minecraft:piston_moving_piece"] = { Tile::pistonMovingPiece_Id, true, 0 };
    stringToID["minecraft:yellow_flower"] = { Tile::flower_Id, true, 0 };
    stringToID["minecraft:red_flower"] = { Tile::rose_Id, true, 0 };
    stringToID["minecraft:brown_mushroom"] = { Tile::mushroom1_Id, true, 0 };
    stringToID["minecraft:red_mushroom"] = { Tile::mushroom2_Id, true, 0 };
    stringToID["minecraft:gold_block"] = { Tile::goldBlock_Id, true, 0 };
    stringToID["minecraft:iron_block"] = { Tile::ironBlock_Id, true, 0 };
    stringToID["minecraft:double_stone_slab"] = { Tile::stoneSlab_Id, true, 0 };
    stringToID["minecraft:sandstone_slab"] = { Tile::stoneSlabHalf_Id, true, 1 };
    stringToID["minecraft:cobblestone_slab"] = { Tile::stoneSlabHalf_Id, true, 2 };
    stringToID["minecraft:brick_slab"] = { Tile::stoneSlabHalf_Id, true, 3 };
    stringToID["minecraft:stone_brick_slab"] = { Tile::stoneSlabHalf_Id, true, 4 };
    stringToID["minecraft:nether_brick_slab"] = { Tile::stoneSlabHalf_Id, true, 5 };
    stringToID["minecraft:quartz_slab"] = { Tile::stoneSlabHalf_Id, true, 6 };
    stringToID["minecraft:brick_block"] = { Tile::redBrick_Id, true, 0 };
    stringToID["minecraft:tnt"] = { Tile::tnt_Id, true, 0 };
    stringToID["minecraft:bookshelf"] = { Tile::bookshelf_Id, true, 0 };
    stringToID["minecraft:mossy_cobblestone"] = { Tile::mossStone_Id, true, 0 };
    stringToID["minecraft:obsidian"] = { Tile::obsidian_Id, true, 0 };
    stringToID["minecraft:torch"] = { Tile::torch_Id, true, 0 };
    stringToID["minecraft:fire"] = { Tile::fire_Id, true, 0 };
    stringToID["minecraft:mob_spawner"] = { Tile::mobSpawner_Id, true, 0 };
    stringToID["minecraft:oak_stairs"] = { Tile::stairs_wood_Id, true, 0 };
    stringToID["minecraft:chest"] = { Tile::chest_Id, true, 0 };
    stringToID["minecraft:redstone_wire"] = { Tile::redStoneDust_Id, true, 0 };
    stringToID["minecraft:diamond_ore"] = { Tile::diamondOre_Id, true, 0 };
    stringToID["minecraft:diamond_block"] = { Tile::diamondBlock_Id, true, 0 };
    stringToID["minecraft:crafting_table"] = { Tile::workBench_Id, true, 0 };
    stringToID["minecraft:wheat"] = { Tile::crops_Id, true, 0 };
    stringToID["minecraft:farmland"] = { Tile::farmland_Id, true, 0 };
    stringToID["minecraft:furnace"] = { Tile::furnace_Id, true, 0 };
    stringToID["minecraft:lit_furnace"] = { Tile::furnace_lit_Id, true, 0 };
    stringToID["minecraft:standing_sign"] = { Tile::sign_Id, true, 0 };
    stringToID["minecraft:wooden_door"] = { Tile::door_wood_Id, true, 0 };
    stringToID["minecraft:ladder"] = { Tile::ladder_Id, true, 0 };
    stringToID["minecraft:rail"] = { Tile::rail_Id, true, 0 };
    stringToID["minecraft:stone_stairs"] = { Tile::stairs_stone_Id, true, 0 };
    stringToID["minecraft:wall_sign"] = { Tile::wallSign_Id, true, 0 };
    stringToID["minecraft:lever"] = { Tile::lever_Id, true, 0 };
    stringToID["minecraft:stone_pressure_plate"] = { Tile::pressurePlate_stone_Id, true, 0 };
    stringToID["minecraft:iron_door"] = { Tile::door_iron_Id, true, 0 };
    stringToID["minecraft:wooden_pressure_plate"] = { Tile::pressurePlate_wood_Id, true, 0 };
    stringToID["minecraft:redstone_ore"] = { Tile::redStoneOre_Id, true, 0 };
    stringToID["minecraft:lit_redstone_ore"] = { Tile::redStoneOre_lit_Id, true, 0 };
    stringToID["minecraft:unlit_redstone_torch"] = { Tile::notGate_off_Id, true, 0 };
    stringToID["minecraft:redstone_torch"] = { Tile::notGate_on_Id, true, 0 };
    stringToID["minecraft:stone_button"] = { Tile::button_stone_Id, true, 0 };
    stringToID["minecraft:snow_layer"] = { Tile::topSnow_Id, true, 0 };
    stringToID["minecraft:ice"] = { Tile::ice_Id, true, 0 };
    stringToID["minecraft:snow"] = { Tile::snow_Id, true, 0 };
    stringToID["minecraft:cactus"] = { Tile::cactus_Id, true, 0 };
    stringToID["minecraft:clay"] = { Tile::clay_Id, true, 0 };
    stringToID["minecraft:reeds"] = { Tile::reeds_Id, true, 0 };
    stringToID["minecraft:jukebox"] = { Tile::recordPlayer_Id, true, 0 };
    stringToID["minecraft:fence"] = { Tile::fence_Id, true, 0 };
    stringToID["minecraft:pumpkin"] = { Tile::pumpkin_Id, true, 0 };
    stringToID["minecraft:netherrack"] = { Tile::hellRock_Id, true, 0 };
    stringToID["minecraft:soul_sand"] = { Tile::hellSand_Id, true, 0 };
    stringToID["minecraft:glowstone"] = { Tile::lightGem_Id, true, 0 };
    stringToID["minecraft:portal"] = { Tile::portalTile_Id, true, 0 };
    stringToID["minecraft:lit_pumpkin"] = { Tile::litPumpkin_Id, true, 0 };
    stringToID["minecraft:cake"] = { Tile::cake_Id, true, 0 };
    stringToID["minecraft:unpowered_repeater"] = { Tile::diode_off_Id, true, 0 };
    stringToID["minecraft:powered_repeater"] = { Tile::diode_on_Id, true, 0 };
    stringToID["minecraft:stained_glass"] = { Tile::aprilFoolsJoke_Id, true, 0 };
    stringToID["minecraft:trapdoor"] = { Tile::trapdoor_Id, true, 0 };
    stringToID["minecraft:monster_egg"] = { Tile::monsterStoneEgg_Id, true, 0 };
    stringToID["minecraft:stone_bricks"] = { Tile::stoneBrickSmooth_Id, true, 0 };
    stringToID["minecraft:mossy_stone_bricks"] = { Tile::stoneBrickSmooth_Id, true, 1 };
    stringToID["minecraft:cracked_stone_bricks"] = { Tile::stoneBrickSmooth_Id, true, 2 };
    stringToID["minecraft:chiseled_stone_bricks"] = { Tile::stoneBrickSmooth_Id, true, 3 };
    stringToID["minecraft:brown_mushroom_block"] = { Tile::hugeMushroom1_Id, true, 0 };
    stringToID["minecraft:red_mushroom_block"] = { Tile::hugeMushroom2_Id, true, 0 };
    stringToID["minecraft:iron_bars"] = { Tile::ironFence_Id, true, 0 };
    stringToID["minecraft:glass_pane"] = { Tile::thinGlass_Id, true, 0 };
    stringToID["minecraft:melon_block"] = { Tile::melon_Id, true, 0 };
    stringToID["minecraft:pumpkin_stem"] = { Tile::pumpkinStem_Id, true, 0 };
    stringToID["minecraft:melon_stem"] = { Tile::melonStem_Id, true, 0 };
    stringToID["minecraft:vine"] = { Tile::vine_Id, true, 0 };
    stringToID["minecraft:fence_gate"] = { Tile::fenceGate_Id, true, 0 };
    stringToID["minecraft:brick_stairs"] = { Tile::stairs_bricks_Id, true, 0 };
    stringToID["minecraft:stone_brick_stairs"] = { Tile::stairs_stoneBrickSmooth_Id, true, 0 };
    stringToID["minecraft:mycelium"] = { Tile::mycel_Id, true, 0 };
    stringToID["minecraft:waterlily"] = { Tile::waterLily_Id, true, 0 };
    stringToID["minecraft:nether_brick"] = { Tile::netherBrick_Id, true, 0 };
    stringToID["minecraft:nether_brick_fence"] = { Tile::netherFence_Id, true, 0 };
    stringToID["minecraft:nether_brick_stairs"] = { Tile::stairs_netherBricks_Id, true, 0 };
    stringToID["minecraft:nether_wart"] = { Tile::netherStalk_Id, true, 0 };
    stringToID["minecraft:enchanting_table"] = { Tile::enchantTable_Id, true, 0 };
    stringToID["minecraft:brewing_stand"] = { Tile::brewingStand_Id, true, 0 };
    stringToID["minecraft:cauldron"] = { Tile::cauldron_Id, true, 0 };
    stringToID["minecraft:end_portal"] = { Tile::endPortalTile_Id, true, 0 };
    stringToID["minecraft:end_portal_frame"] = { Tile::endPortalFrameTile_Id, true, 0 };
    stringToID["minecraft:white_stone"] = { Tile::whiteStone_Id, true, 0 };
    stringToID["minecraft:dragon_egg"] = { Tile::dragonEgg_Id, true, 0 };
    stringToID["minecraft:redstone_lamp"] = { Tile::redstoneLight_Id, true, 0 };
    stringToID["minecraft:lit_redstone_lamp"] = { Tile::redstoneLight_lit_Id, true, 0 };
    stringToID["minecraft:double_wooden_slab"] = { Tile::woodSlab_Id, true, 0 };
    stringToID["minecraft:oak_slab"] = { Tile::woodSlabHalf_Id, true, 0 };
    stringToID["minecraft:spruce_slab"] = { Tile::woodSlabHalf_Id, true, 1 };
    stringToID["minecraft:birch_slab"] = { Tile::woodSlabHalf_Id, true, 2 };
    stringToID["minecraft:jungle_slab"] = { Tile::woodSlabHalf_Id, true, 3 };
    stringToID["minecraft:cocoa"] = { Tile::cocoa_Id, true, 0 };
    stringToID["minecraft:sandstone_stairs"] = { Tile::stairs_sandstone_Id, true, 0 };
    stringToID["minecraft:spruce_stairs"] = { Tile::stairs_sprucewood_Id, true, 0 };
    stringToID["minecraft:birch_stairs"] = { Tile::stairs_birchwood_Id, true, 0 };
    stringToID["minecraft:jungle_stairs"] = { Tile::stairs_junglewood_Id, true, 0 };
    stringToID["minecraft:emerald_ore"] = { Tile::emeraldOre_Id, true, 0 };
    stringToID["minecraft:ender_chest"] = { Tile::enderChest_Id, true, 0 };
    stringToID["minecraft:tripwire_hook"] = { Tile::tripWireSource_Id, true, 0 };
    //stringToID["minecraft:tripwire_hook"] = { Tile::tripWire_Id, true, 0 };
    stringToID["minecraft:emerald_block"] = { Tile::emeraldBlock_Id, true, 0 };
    stringToID["minecraft:cobblestone_wall"] = { Tile::cobbleWall_Id, true, 0 };
    stringToID["minecraft:mossy_cobblestone_wall"] = { Tile::cobbleWall_Id, true, 1 };
    stringToID["minecraft:flower_pot"] = { Tile::flowerPot_Id, true, 0 };
    stringToID["minecraft:carrots"] = { Tile::carrots_Id, true, 0 };
    stringToID["minecraft:potatoes"] = { Tile::potatoes_Id, true, 0 };
    stringToID["minecraft:wooden_button"] = { Tile::button_wood_Id, true, 0 };
    //stringToID["minecraft:skull"] = { Tile::skull_Id, true, 0 };
    stringToID["minecraft:anvil"] = { Tile::anvil_Id, true, 0 };
    stringToID["minecraft:quartz_ore"] = { Tile::netherQuartz_Id, true, 0 };
    stringToID["minecraft:quartz_block"] = { Tile::quartzBlock_Id, true, 0 };
    stringToID["minecraft:chiseled_quartz_block"] = { Tile::quartzBlock_Id, true, 1 };
    stringToID["minecraft:quartz_pillar"] = { Tile::quartzBlock_Id, true, 2 };
    stringToID["minecraft:quartz_stairs"] = { Tile::stairs_quartz_Id, true, 0 };
    stringToID["minecraft:white_carpet"] = { Tile::woolCarpet_Id, true, 0 };
    stringToID["minecraft:orange_carpet"] = { Tile::woolCarpet_Id, true, 1 };
    stringToID["minecraft:magenta_carpet"] = { Tile::woolCarpet_Id, true, 2 };
    stringToID["minecraft:light_blue_carpet"] = { Tile::woolCarpet_Id, true, 3 };
    stringToID["minecraft:yellow_carpet"] = { Tile::woolCarpet_Id, true, 4 };
    stringToID["minecraft:lime_carpet"] = { Tile::woolCarpet_Id, true, 5 };
    stringToID["minecraft:pink_carpet"] = { Tile::woolCarpet_Id, true, 6 };
    stringToID["minecraft:gray_carpet"] = { Tile::woolCarpet_Id, true, 7 };
    stringToID["minecraft:light_gray_carpet"] = { Tile::woolCarpet_Id, true, 8 };
    stringToID["minecraft:cyan_carpet"] = { Tile::woolCarpet_Id, true, 9 };
    stringToID["minecraft:purple_carpet"] = { Tile::woolCarpet_Id, true, 10 };
    stringToID["minecraft:blue_carpet"] = { Tile::woolCarpet_Id, true, 11 };
    stringToID["minecraft:brown_carpet"] = { Tile::woolCarpet_Id, true, 12 };
    stringToID["minecraft:green_carpet"] = { Tile::woolCarpet_Id, true, 13 };
    stringToID["minecraft:red_carpet"] = { Tile::woolCarpet_Id, true, 14 };
    stringToID["minecraft:black_carpet"] = { Tile::woolCarpet_Id, true, 15 };

    /* Items */
    stringToID["minecraft:string"] = { Item::string_Id, false, 0 };

    stringToID["minecraft:iron_shovel"] = { Item::shovel_iron_Id, false, 0 };
    stringToID["minecraft:iron_pickaxe"] = { Item::pickAxe_iron_Id, false, 0 };
    stringToID["minecraft:iron_axe"] = { Item::hatchet_iron_Id, false, 0 };
    stringToID["minecraft:flint_and_steel"] = { Item::flintAndSteel_Id, false, 0 };
    stringToID["minecraft:apple"] = { Item::apple_Id, false, 0 };
    stringToID["minecraft:bow"] = { Item::bow_Id, false, 0 };
    stringToID["minecraft:arrow"] = { Item::arrow_Id, false, 0 };
    stringToID["minecraft:coal"] = { Item::coal_Id, false, 0 };
    stringToID["minecraft:charcoal"] = { Item::coal_Id, false, 1 };
    stringToID["minecraft:diamond"] = { Item::diamond_Id, false, 0 };
    stringToID["minecraft:iron_ingot"] = { Item::ironIngot_Id, false, 0 };
    stringToID["minecraft:gold_ingot"] = { Item::goldIngot_Id, false, 0 };

    stringToID["minecraft:iron_sword"] = { Item::sword_iron_Id, false, 0 };
    stringToID["minecraft:wooden_sword"] = { Item::sword_wood_Id, false, 0 };
    stringToID["minecraft:stone_sword"] = { Item::sword_stone_Id, false, 0 };
    stringToID["minecraft:diamond_sword"] = { Item::sword_diamond_Id, false, 0 };
    stringToID["minecraft:golden_sword"] = { Item::sword_gold_Id, false, 0 };

    stringToID["minecraft:wooden_shovel"] = { Item::shovel_wood_Id, false, 0 };
    stringToID["minecraft:wooden_pickaxe"] = { Item::pickAxe_wood_Id, false, 0 };
    stringToID["minecraft:wooden_axe"] = { Item::hatchet_wood_Id, false, 0 };

    stringToID["minecraft:stone_shovel"] = { Item::shovel_stone_Id, false, 0 };
    stringToID["minecraft:stone_pickaxe"] = { Item::pickAxe_stone_Id, false, 0 };
    stringToID["minecraft:stone_axe"] = { Item::hatchet_stone_Id, false, 0 };

    stringToID["minecraft:diamond_shovel"] = { Item::shovel_diamond_Id, false, 0 };
    stringToID["minecraft:diamond_pickaxe"] = { Item::pickAxe_diamond_Id, false, 0 };
    stringToID["minecraft:diamond_axe"] = { Item::hatchet_diamond_Id, false, 0 };

    stringToID["minecraft:stick"] = { Item::stick_Id, false, 0 };
    stringToID["minecraft:bowl"] = { Item::bowl_Id, false, 0 };
    stringToID["minecraft:mushroom_stew"] = { Item::mushroomStew_Id, false, 0 };

    stringToID["minecraft:feather"] = { Item::feather_Id, false, 0 };
    stringToID["minecraft:gunpowder"] = { Item::sulphur_Id, false, 0 };

    stringToID["minecraft:wooden_hoe"] = { Item::hoe_wood_Id, false, 0 };
    stringToID["minecraft:stone_hoe"] = { Item::hoe_stone_Id, false, 0 };
    stringToID["minecraft:iron_hoe"] = { Item::hoe_iron_Id, false, 0 };
    stringToID["minecraft:diamond_hoe"] = { Item::hoe_diamond_Id, false, 0 };
    stringToID["minecraft:golden_hoe"] = { Item::hoe_gold_Id, false, 0 };

    stringToID["minecraft:wheat_seeds"] = { Item::seeds_wheat_Id, false, 0 };
    stringToID["minecraft:wheat"] = { Item::wheat_Id, false, 0 };
    stringToID["minecraft:bread"] = { Item::bread_Id, false, 0 };

    stringToID["minecraft:leather_helmet"] = { Item::helmet_cloth_Id, false, 0 };
    stringToID["minecraft:leather_chestplate"] = { Item::chestplate_cloth_Id, false, 0 };
    stringToID["minecraft:leather_leggings"] = { Item::leggings_cloth_Id, false, 0 };
    stringToID["minecraft:leather_boots"] = { Item::boots_cloth_Id, false, 0 };

    stringToID["minecraft:iron_helmet"] = { Item::helmet_iron_Id, false, 0 };
    stringToID["minecraft:iron_chestplate"] = { Item::chestplate_iron_Id, false, 0 };
    stringToID["minecraft:iron_leggings"] = { Item::leggings_iron_Id, false, 0 };
    stringToID["minecraft:iron_boots"] = { Item::boots_iron_Id, false, 0 };

    stringToID["minecraft:diamond_helmet"] = { Item::helmet_diamond_Id, false, 0 };
    stringToID["minecraft:diamond_chestplate"] = { Item::chestplate_diamond_Id, false, 0 };
    stringToID["minecraft:diamond_leggings"] = { Item::leggings_diamond_Id, false, 0 };
    stringToID["minecraft:diamond_boots"] = { Item::boots_diamond_Id, false, 0 };

    stringToID["minecraft:golden_helmet"] = { Item::helmet_gold_Id, false, 0 };
    stringToID["minecraft:golden_chestplate"] = { Item::chestplate_gold_Id, false, 0 };
    stringToID["minecraft:golden_leggings"] = { Item::leggings_gold_Id, false, 0 };
    stringToID["minecraft:golden_boots"] = { Item::boots_gold_Id, false, 0 };

    stringToID["minecraft:flint"] = { Item::flint_Id, false, 0 };
    stringToID["minecraft:porkchop"] = { Item::porkChop_raw_Id, false, 0 };
    stringToID["minecraft:cooked_porkchop"] = { Item::porkChop_cooked_Id, false, 0 };

    stringToID["minecraft:painting"] = { Item::painting_Id, false, 0 };
    stringToID["minecraft:golden_apple"] = { Item::apple_gold_Id, false, 0 };
    stringToID["minecraft:sign"] = { Item::sign_Id, false, 0 };

    stringToID["minecraft:bucket"] = { Item::bucket_empty_Id, false, 0 };
    stringToID["minecraft:water_bucket"] = { Item::bucket_water_Id, false, 0 };
    stringToID["minecraft:lava_bucket"] = { Item::bucket_lava_Id, false, 0 };

    stringToID["minecraft:minecart"] = { Item::minecart_Id, false, 0 };
    stringToID["minecraft:saddle"] = { Item::saddle_Id, false, 0 };

    stringToID["minecraft:redstone"] = { Item::redStone_Id, false, 0 };
    stringToID["minecraft:snowball"] = { Item::snowBall_Id, false, 0 };
    stringToID["minecraft:boat"] = { Item::boat_Id, false, 0 };

    stringToID["minecraft:leather"] = { Item::leather_Id, false, 0 };
    stringToID["minecraft:milk_bucket"] = { Item::milk_Id, false, 0 };

    stringToID["minecraft:brick"] = { Item::brick_Id, false, 0 };
    stringToID["minecraft:clay_ball"] = { Item::clay_Id, false, 0 };

    stringToID["minecraft:reeds"] = { Item::reeds_Id, false, 0 };
    stringToID["minecraft:paper"] = { Item::paper_Id, false, 0 };
    stringToID["minecraft:book"] = { Item::book_Id, false, 0 };

    stringToID["minecraft:slime_ball"] = { Item::slimeBall_Id, false, 0 };

    stringToID["minecraft:egg"] = { Item::egg_Id, false, 0 };
    stringToID["minecraft:compass"] = { Item::compass_Id, false, 0 };
    stringToID["minecraft:fishing_rod"] = { Item::fishingRod_Id, false, 0 };
    stringToID["minecraft:clock"] = { Item::clock_Id, false, 0 };

    stringToID["minecraft:bone"] = { Item::bone_Id, false, 0 };
    stringToID["minecraft:sugar"] = { Item::sugar_Id, false, 0 };
    stringToID["minecraft:cake"] = { Item::cake_Id, false, 0 };
    stringToID["minecraft:filled_map"] = { Item::bed_Id, false, 0 };

    stringToID["minecraft:cookie"] = { Item::cookie_Id, false, 0 };
    stringToID["minecraft:map"] = { Item::map_Id, false, 0 };

    stringToID["minecraft:shears"] = { Item::shears_Id, false, 0 };

    stringToID["minecraft:melon"] = { Item::melon_Id, false, 0 };
    stringToID["minecraft:pumpkin_seeds"] = { Item::seeds_pumpkin_Id, false, 0 };
    stringToID["minecraft:melon_seeds"] = { Item::seeds_melon_Id, false, 0 };

    stringToID["minecraft:beef"] = { Item::beef_raw_Id, false, 0 };
    stringToID["minecraft:cooked_beef"] = { Item::beef_cooked_Id, false, 0 };

    stringToID["minecraft:chicken"] = { Item::chicken_raw_Id, false, 0 };
    stringToID["minecraft:cooked_chicken"] = { Item::chicken_cooked_Id, false, 0 };

    stringToID["minecraft:rotten_flesh"] = { Item::rotten_flesh_Id, false, 0 };
    stringToID["minecraft:ender_pearl"] = { Item::enderPearl_Id, false, 0 };

    stringToID["minecraft:blaze_rod"] = { Item::blazeRod_Id, false, 0 };
    stringToID["minecraft:ghast_tear"] = { Item::ghastTear_Id, false, 0 };
    stringToID["minecraft:gold_nugget"] = { Item::goldNugget_Id, false, 0 };

    stringToID["minecraft:potion"] = { Item::potion_Id, false, 0 };
    stringToID["minecraft:glass_bottle"] = { Item::glassBottle_Id, false, 0 };

    stringToID["minecraft:spider_eye"] = { Item::spiderEye_Id, false, 0 };
    stringToID["minecraft:blaze_powder"] = { Item::blazePowder_Id, false, 0 };
    stringToID["minecraft:magma_cream"] = { Item::magmaCream_Id, false, 0 };

    stringToID["minecraft:brewing_stand"] = { Item::brewingStand_Id, false, 0 };
    stringToID["minecraft:cauldron"] = { Item::cauldron_Id, false, 0 };

    stringToID["minecraft:ender_eye"] = { Item::eyeOfEnder_Id, false, 0 };

    stringToID["minecraft:experience_bottle"] = { Item::expBottle_Id, false, 0 };

    stringToID["minecraft:emerald"] = { Item::emerald_Id, false, 0 };

    stringToID["minecraft:carrot"] = { Item::carrots_Id, false, 0 };
    stringToID["minecraft:potato"] = { Item::potato_Id, false, 0 };
    stringToID["minecraft:baked_potato"] = { Item::potatoBaked_Id, false, 0 };

    stringToID["minecraft:golden_carrot"] = { Item::carrotGolden_Id, false, 0 };

    stringToID["minecraft:carrot_on_a_stick"] = { Item::carrotOnAStick_Id, false, 0 };
    stringToID["minecraft:pumpkin_pie"] = { Item::pumpkinPie_Id, false, 0 };

    stringToID["minecraft:enchanted_book"] = { Item::enchantedBook_Id, false, 0 };
    stringToID["minecraft:quartz"] = { Item::netherQuartz_Id, false, 0 };

    stringToID["minecraft:chainmail_helmet"] = { Item::helmet_chain_Id, false, 0 };
    stringToID["minecraft:chainmail_chestplate"] = { Item::chestplate_chain_Id, false, 0 };
    stringToID["minecraft:chainmail_leggings"] = { Item::leggings_chain_Id, false, 0 };
    stringToID["minecraft:chainmail_boots"] = { Item::boots_chain_Id, false, 0 };

    stringToID["minecraft:wooden_door"] = { Item::door_wood_Id, false, 0 };
    stringToID["minecraft:iron_door"] = { Item::door_iron_Id, false, 0 };
    stringToID["minecraft:chest_minecart"] = { Item::minecart_chest_Id, false, 0 };
    stringToID["minecraft:furnace_minecart"] = { Item::minecart_furnace_Id, false, 0 };
    stringToID["minecraft:glowstone_dust"] = { Item::yellowDust_Id, false, 0 };
    stringToID["minecraft:fish"] = { Item::fish_raw_Id, false, 0 };
    stringToID["minecraft:cooked_fish"] = { Item::fish_cooked_Id, false, 0 };
    stringToID["minecraft:ink_sac"] = { Item::dye_powder_Id, false, 0 };
    stringToID["minecraft:rose_red"] = { Item::dye_powder_Id, false, 1 };
    stringToID["minecraft:cactus_green"] = { Item::dye_powder_Id, false, 2 };
    stringToID["minecraft:cocoa_beans"] = { Item::dye_powder_Id, false, 3 };
    stringToID["minecraft:lapis_lazuli"] = { Item::dye_powder_Id, false, 4 };
    stringToID["minecraft:purple_dye"] = { Item::dye_powder_Id, false, 5 };
    stringToID["minecraft:cyan_dye"] = { Item::dye_powder_Id, false, 6 };
    stringToID["minecraft:light_gray_dye"] = { Item::dye_powder_Id, false, 7 };
    stringToID["minecraft:gray_dye"] = { Item::dye_powder_Id, false, 8 };
    stringToID["minecraft:pink_dye"] = { Item::dye_powder_Id, false, 9 };
    stringToID["minecraft:lime_dye"] = { Item::dye_powder_Id, false, 10 };
    stringToID["minecraft:dandelion_yellow"] = { Item::dye_powder_Id, false, 11 };
    stringToID["minecraft:light_blue_dye"] = { Item::dye_powder_Id, false, 12 };
    stringToID["minecraft:magenta_dye"] = { Item::dye_powder_Id, false, 13 };
    stringToID["minecraft:orange_dye"] = { Item::dye_powder_Id, false, 14 };
    stringToID["minecraft:bone_meal"] = { Item::dye_powder_Id, false, 15 };
    stringToID["minecraft:nether_wart"] = { Item::netherStalkSeeds_Id, false, 0 };
    stringToID["minecraft:fermented_spider_eye"] = { Item::fermentedSpiderEye_Id, false, 0 };
    stringToID["minecraft:speckled_melon"] = { Item::speckledMelon_Id, false, 0 };
    stringToID["minecraft:spawn_egg"] = { Item::monsterPlacer_Id, false, 0 };
    stringToID["minecraft:skeleton_skull"] = { Item::skull_Id, false, 0 };
    stringToID["minecraft:wither_skeleton_skull"] = { Item::skull_Id, false, 1 };
    stringToID["minecraft:zombie_head"] = { Item::skull_Id, false, 2 };
    stringToID["minecraft:player_head"] = { Item::skull_Id, false, 3 };
    stringToID["minecraft:creeper_head"] = { Item::skull_Id, false, 4 };
    stringToID["minecraft:fire_charge"] = { Item::fireball_Id, false, 0 };
    stringToID["minecraft:item_frame"] = { Item::itemFrame_Id, false, 0 };
    stringToID["minecraft:netherbrick"] = { Item::netherbrick_Id, false, 0 };
    stringToID["minecraft:flower_pot"] = { Item::flowerPot_Id, false, 0 };
    stringToID["minecraft:poisonous_potato"] = { Item::potatoPoisonous_Id, false, 0 };

    stringToID["minecraft:record_13"] = { Item::record_01_Id, false, 0 };
    stringToID["minecraft:record_cat"] = { Item::record_02_Id, false, 0 };
    stringToID["minecraft:record_blocks"] = { Item::record_03_Id, false, 0 };
    stringToID["minecraft:record_chirp"] = { Item::record_04_Id, false, 0 };
    stringToID["minecraft:record_far"] = { Item::record_05_Id, false, 0 };
    stringToID["minecraft:record_mall"] = { Item::record_06_Id, false, 0 };
    stringToID["minecraft:record_mellohi"] = { Item::record_07_Id, false, 0 };
    stringToID["minecraft:record_stal"] = { Item::record_08_Id, false, 0 };
    stringToID["minecraft:record_strad"] = { Item::record_09_Id, false, 0 };
    stringToID["minecraft:record_ward"] = { Item::record_10_Id, false, 0 };
    stringToID["minecraft:record_11"] = { Item::record_11_Id, false, 0 };
    stringToID["minecraft:record_wait"] = { Item::record_12_Id, false, 0 };
}