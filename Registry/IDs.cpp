#include "IDs.h"
#include "../Minecraft.World/Items/Item.h"
#include "../Minecraft.World/Blocks/Tile.h"
#include <stdexcept>

std::unordered_map<std::string, IDMapping::MappedItem> IDMapping::stringToID;

void IDMapping::add(std::string ns, std::string name, bool isBlock, int id) {
    std::string n = ns+":"+name;
    stringToID[n] = { id, isBlock };
}

std::pair<bool,int> IDMapping::get(std::string k) {
    try {
        return std::make_pair(true,stringToID.at(k).id);
    } catch (std::out_of_range) {
        return std::make_pair(false,0);
    }
}

/* WARNING!!! Boilerplate HELL!!! Want it reduced? USE A FAWKIN MACRO!!! */

void IDMapping::staticCtor() {
    /* Blocks */
    stringToID["minecraft:stone"] = { Tile::rock_Id, true };
    stringToID["minecraft:grass"] = { Tile::grass_Id, true };
    stringToID["minecraft:dirt"] = { Tile::dirt_Id, true };
    stringToID["minecraft:stone_brick"] = { Tile::stoneBrick_Id, true };
    stringToID["minecraft:wood"] = { Tile::wood_Id, true };
    stringToID["minecraft:sapling"] = { Tile::sapling_Id, true };
    stringToID["minecraft:bedrock"] = { Tile::unbreakable_Id, true };
    stringToID["minecraft:water"] = { Tile::water_Id, true };
    stringToID["minecraft:calm_water"] = { Tile::calmWater_Id, true };
    stringToID["minecraft:lava"] = { Tile::lava_Id, true };
    stringToID["minecraft:calm_lava"] = { Tile::calmLava_Id, true };
    stringToID["minecraft:sand"] = { Tile::sand_Id, true };
    stringToID["minecraft:gravel"] = { Tile::gravel_Id, true };
    stringToID["minecraft:gold_ore"] = { Tile::goldOre_Id, true };
    stringToID["minecraft:iron_ore"] = { Tile::ironOre_Id, true };
    stringToID["minecraft:coal_ore"] = { Tile::coalOre_Id, true };
    stringToID["minecraft:tree_trunk"] = { Tile::treeTrunk_Id, true };
    stringToID["minecraft:leaves"] = { Tile::leaves_Id, true };
    stringToID["minecraft:sponge"] = { Tile::sponge_Id, true };
    stringToID["minecraft:glass"] = { Tile::glass_Id, true };
    stringToID["minecraft:lapis_ore"] = { Tile::lapisOre_Id, true };
    stringToID["minecraft:lapis_block"] = { Tile::lapisBlock_Id, true };
    stringToID["minecraft:dispenser"] = { Tile::dispenser_Id, true };
    stringToID["minecraft:sandstone"] = { Tile::sandStone_Id, true };
    stringToID["minecraft:music_block"] = { Tile::musicBlock_Id, true };
    stringToID["minecraft:bed"] = { Tile::bed_Id, true };
    stringToID["minecraft:golden_rail"] = { Tile::goldenRail_Id, true };
    stringToID["minecraft:detector_rail"] = { Tile::detectorRail_Id, true };
    stringToID["minecraft:piston_sticky_base"] = { Tile::pistonStickyBase_Id, true };
    stringToID["minecraft:web"] = { Tile::web_Id, true };
    stringToID["minecraft:tallgrass"] = { Tile::tallgrass_Id, true };
    stringToID["minecraft:dead_bush"] = { Tile::deadBush_Id, true };
    stringToID["minecraft:piston_base"] = { Tile::pistonBase_Id, true };
    stringToID["minecraft:piston_extension_piece"] = { Tile::pistonExtensionPiece_Id, true };
    stringToID["minecraft:cloth"] = { Tile::cloth_Id, true };
    stringToID["minecraft:piston_moving_piece"] = { Tile::pistonMovingPiece_Id, true };
    stringToID["minecraft:flower"] = { Tile::flower_Id, true };
    stringToID["minecraft:rose"] = { Tile::rose_Id, true };
    stringToID["minecraft:mushroom1"] = { Tile::mushroom1_Id, true };
    stringToID["minecraft:mushroom2"] = { Tile::mushroom2_Id, true };
    stringToID["minecraft:gold_block"] = { Tile::goldBlock_Id, true };
    stringToID["minecraft:iron_block"] = { Tile::ironBlock_Id, true };
    stringToID["minecraft:stone_slab"] = { Tile::stoneSlab_Id, true };
    stringToID["minecraft:stone_slab_half"] = { Tile::stoneSlabHalf_Id, true };
    stringToID["minecraft:red_brick"] = { Tile::redBrick_Id, true };
    stringToID["minecraft:tnt"] = { Tile::tnt_Id, true };
    stringToID["minecraft:bookshelf"] = { Tile::bookshelf_Id, true };
    stringToID["minecraft:moss_stone"] = { Tile::mossStone_Id, true };
    stringToID["minecraft:obsidian"] = { Tile::obsidian_Id, true };
    stringToID["minecraft:torch"] = { Tile::torch_Id, true };
    stringToID["minecraft:fire"] = { Tile::fire_Id, true };
    stringToID["minecraft:mob_spawner"] = { Tile::mobSpawner_Id, true };
    stringToID["minecraft:stairs_wood"] = { Tile::stairs_wood_Id, true };
    stringToID["minecraft:chest"] = { Tile::chest_Id, true };
    stringToID["minecraft:redstone_dust"] = { Tile::redStoneDust_Id, true };
    stringToID["minecraft:diamond_ore"] = { Tile::diamondOre_Id, true };
    stringToID["minecraft:diamond_block"] = { Tile::diamondBlock_Id, true };
    stringToID["minecraft:workbench"] = { Tile::workBench_Id, true };
    stringToID["minecraft:crops"] = { Tile::crops_Id, true };
    stringToID["minecraft:farmland"] = { Tile::farmland_Id, true };
    stringToID["minecraft:furnace"] = { Tile::furnace_Id, true };
    stringToID["minecraft:furnace_lit"] = { Tile::furnace_lit_Id, true };
    stringToID["minecraft:sign"] = { Tile::sign_Id, true };
    stringToID["minecraft:door_wood"] = { Tile::door_wood_Id, true };
    stringToID["minecraft:ladder"] = { Tile::ladder_Id, true };
    stringToID["minecraft:rail"] = { Tile::rail_Id, true };
    stringToID["minecraft:stairs_stone"] = { Tile::stairs_stone_Id, true };
    stringToID["minecraft:wall_sign"] = { Tile::wallSign_Id, true };
    stringToID["minecraft:lever"] = { Tile::lever_Id, true };
    stringToID["minecraft:pressure_plate_stone"] = { Tile::pressurePlate_stone_Id, true };
    stringToID["minecraft:door_iron"] = { Tile::door_iron_Id, true };
    stringToID["minecraft:pressure_plate_wood"] = { Tile::pressurePlate_wood_Id, true };
    stringToID["minecraft:redstone_ore"] = { Tile::redStoneOre_Id, true };
    stringToID["minecraft:redstone_ore_lit"] = { Tile::redStoneOre_lit_Id, true };
    stringToID["minecraft:not_gate_off"] = { Tile::notGate_off_Id, true };
    stringToID["minecraft:not_gate_on"] = { Tile::notGate_on_Id, true };
    stringToID["minecraft:button_stone"] = { Tile::button_stone_Id, true };
    stringToID["minecraft:top_snow"] = { Tile::topSnow_Id, true };
    stringToID["minecraft:ice"] = { Tile::ice_Id, true };
    stringToID["minecraft:snow"] = { Tile::snow_Id, true };
    stringToID["minecraft:cactus"] = { Tile::cactus_Id, true };
    stringToID["minecraft:clay"] = { Tile::clay_Id, true };
    stringToID["minecraft:reeds"] = { Tile::reeds_Id, true };
    stringToID["minecraft:record_player"] = { Tile::recordPlayer_Id, true };
    stringToID["minecraft:fence"] = { Tile::fence_Id, true };
    stringToID["minecraft:pumpkin"] = { Tile::pumpkin_Id, true };
    stringToID["minecraft:hell_rock"] = { Tile::hellRock_Id, true };
    stringToID["minecraft:hell_sand"] = { Tile::hellSand_Id, true };
    stringToID["minecraft:light_gem"] = { Tile::lightGem_Id, true };
    stringToID["minecraft:portal_tile"] = { Tile::portalTile_Id, true };
    stringToID["minecraft:lit_pumpkin"] = { Tile::litPumpkin_Id, true };
    stringToID["minecraft:cake"] = { Tile::cake_Id, true };
    stringToID["minecraft:diode_off"] = { Tile::diode_off_Id, true };
    stringToID["minecraft:diode_on"] = { Tile::diode_on_Id, true };
    stringToID["minecraft:april_fools_joke"] = { Tile::aprilFoolsJoke_Id, true };
    stringToID["minecraft:trapdoor"] = { Tile::trapdoor_Id, true };
    stringToID["minecraft:monster_stone_egg"] = { Tile::monsterStoneEgg_Id, true };
    stringToID["minecraft:stone_brick_smooth"] = { Tile::stoneBrickSmooth_Id, true };
    stringToID["minecraft:huge_mushroom1"] = { Tile::hugeMushroom1_Id, true };
    stringToID["minecraft:huge_mushroom2"] = { Tile::hugeMushroom2_Id, true };
    stringToID["minecraft:iron_fence"] = { Tile::ironFence_Id, true };
    stringToID["minecraft:thin_glass"] = { Tile::thinGlass_Id, true };
    stringToID["minecraft:melon"] = { Tile::melon_Id, true };
    stringToID["minecraft:pumpkin_stem"] = { Tile::pumpkinStem_Id, true };
    stringToID["minecraft:melon_stem"] = { Tile::melonStem_Id, true };
    stringToID["minecraft:vine"] = { Tile::vine_Id, true };
    stringToID["minecraft:fence_gate"] = { Tile::fenceGate_Id, true };
    stringToID["minecraft:stairs_bricks"] = { Tile::stairs_bricks_Id, true };
    stringToID["minecraft:stairs_stone_brick_smooth"] = { Tile::stairs_stoneBrickSmooth_Id, true };
    stringToID["minecraft:mycel"] = { Tile::mycel_Id, true };
    stringToID["minecraft:water_lily"] = { Tile::waterLily_Id, true };
    stringToID["minecraft:nether_brick"] = { Tile::netherBrick_Id, true };
    stringToID["minecraft:nether_fence"] = { Tile::netherFence_Id, true };
    stringToID["minecraft:stairs_nether_bricks"] = { Tile::stairs_netherBricks_Id, true };
    stringToID["minecraft:nether_stalk"] = { Tile::netherStalk_Id, true };
    stringToID["minecraft:enchant_table"] = { Tile::enchantTable_Id, true };
    stringToID["minecraft:brewing_stand"] = { Tile::brewingStand_Id, true };
    stringToID["minecraft:cauldron"] = { Tile::cauldron_Id, true };
    stringToID["minecraft:end_portal_tile"] = { Tile::endPortalTile_Id, true };
    stringToID["minecraft:end_portal_frame_tile"] = { Tile::endPortalFrameTile_Id, true };
    stringToID["minecraft:white_stone"] = { Tile::whiteStone_Id, true };
    stringToID["minecraft:dragon_egg"] = { Tile::dragonEgg_Id, true };
    stringToID["minecraft:redstone_lamp"] = { Tile::redstoneLight_Id, true };
    stringToID["minecraft:redstone_lamp_lit"] = { Tile::redstoneLight_lit_Id, true };
    stringToID["minecraft:wood_slab"] = { Tile::woodSlab_Id, true };
    stringToID["minecraft:wood_slab_half"] = { Tile::woodSlabHalf_Id, true };
    stringToID["minecraft:cocoa"] = { Tile::cocoa_Id, true };
    stringToID["minecraft:stairs_sandstone"] = { Tile::stairs_sandstone_Id, true };
    stringToID["minecraft:stairs_sprucewood"] = { Tile::stairs_sprucewood_Id, true };
    stringToID["minecraft:stairs_birchwood"] = { Tile::stairs_birchwood_Id, true };
    stringToID["minecraft:stairs_junglewood"] = { Tile::stairs_junglewood_Id, true };
    stringToID["minecraft:emerald_ore"] = { Tile::emeraldOre_Id, true };
    stringToID["minecraft:ender_chest"] = { Tile::enderChest_Id, true };
    stringToID["minecraft:tripwire_source"] = { Tile::tripWireSource_Id, true };
    stringToID["minecraft:tripwire"] = { Tile::tripWire_Id, true };
    stringToID["minecraft:emerald_block"] = { Tile::emeraldBlock_Id, true };
    stringToID["minecraft:cobble_wall"] = { Tile::cobbleWall_Id, true };
    stringToID["minecraft:flower_pot"] = { Tile::flowerPot_Id, true };
    stringToID["minecraft:carrots"] = { Tile::carrots_Id, true };
    stringToID["minecraft:potatoes"] = { Tile::potatoes_Id, true };
    stringToID["minecraft:button_wood"] = { Tile::button_wood_Id, true };
    stringToID["minecraft:skull"] = { Tile::skull_Id, true };
    stringToID["minecraft:anvil"] = { Tile::anvil_Id, true };
    stringToID["minecraft:nether_quartz"] = { Tile::netherQuartz_Id, true };
    stringToID["minecraft:quartz_block"] = { Tile::quartzBlock_Id, true };
    stringToID["minecraft:stairs_quartz"] = { Tile::stairs_quartz_Id, true };
    stringToID["minecraft:wool_carpet"] = { Tile::woolCarpet_Id, true };

    /* Items */
    stringToID["minecraft:string"] = { Item::string_Id, false };

    stringToID["minecraft:shovel_iron"] = { Item::shovel_iron_Id, false };
    stringToID["minecraft:pickaxe_iron"] = { Item::pickAxe_iron_Id, false };
    stringToID["minecraft:hatchet_iron"] = { Item::hatchet_iron_Id, false };
    stringToID["minecraft:flint_and_steel"] = { Item::flintAndSteel_Id, false };
    stringToID["minecraft:apple"] = { Item::apple_Id, false };
    stringToID["minecraft:bow"] = { Item::bow_Id, false };
    stringToID["minecraft:arrow"] = { Item::arrow_Id, false };
    stringToID["minecraft:coal"] = { Item::coal_Id, false };
    stringToID["minecraft:diamond"] = { Item::diamond_Id, false };
    stringToID["minecraft:iron_ingot"] = { Item::ironIngot_Id, false };
    stringToID["minecraft:gold_ingot"] = { Item::goldIngot_Id, false };

    stringToID["minecraft:sword_iron"] = { Item::sword_iron_Id, false };
    stringToID["minecraft:sword_wood"] = { Item::sword_wood_Id, false };
    stringToID["minecraft:sword_stone"] = { Item::sword_stone_Id, false };
    stringToID["minecraft:sword_diamond"] = { Item::sword_diamond_Id, false };
    stringToID["minecraft:sword_gold"] = { Item::sword_gold_Id, false };

    stringToID["minecraft:shovel_wood"] = { Item::shovel_wood_Id, false };
    stringToID["minecraft:pickaxe_wood"] = { Item::pickAxe_wood_Id, false };
    stringToID["minecraft:hatchet_wood"] = { Item::hatchet_wood_Id, false };

    stringToID["minecraft:shovel_stone"] = { Item::shovel_stone_Id, false };
    stringToID["minecraft:pickaxe_stone"] = { Item::pickAxe_stone_Id, false };
    stringToID["minecraft:hatchet_stone"] = { Item::hatchet_stone_Id, false };

    stringToID["minecraft:shovel_diamond"] = { Item::shovel_diamond_Id, false };
    stringToID["minecraft:pickaxe_diamond"] = { Item::pickAxe_diamond_Id, false };
    stringToID["minecraft:hatchet_diamond"] = { Item::hatchet_diamond_Id, false };

    stringToID["minecraft:stick"] = { Item::stick_Id, false };
    stringToID["minecraft:bowl"] = { Item::bowl_Id, false };
    stringToID["minecraft:mushroom_stew"] = { Item::mushroomStew_Id, false };

    stringToID["minecraft:feather"] = { Item::feather_Id, false };
    stringToID["minecraft:sulphur"] = { Item::sulphur_Id, false };

    stringToID["minecraft:hoe_wood"] = { Item::hoe_wood_Id, false };
    stringToID["minecraft:hoe_stone"] = { Item::hoe_stone_Id, false };
    stringToID["minecraft:hoe_iron"] = { Item::hoe_iron_Id, false };
    stringToID["minecraft:hoe_diamond"] = { Item::hoe_diamond_Id, false };
    stringToID["minecraft:hoe_gold"] = { Item::hoe_gold_Id, false };

    stringToID["minecraft:seeds_wheat"] = { Item::seeds_wheat_Id, false };
    stringToID["minecraft:wheat"] = { Item::wheat_Id, false };
    stringToID["minecraft:bread"] = { Item::bread_Id, false };

    stringToID["minecraft:helmet_cloth"] = { Item::helmet_cloth_Id, false };
    stringToID["minecraft:chestplate_cloth"] = { Item::chestplate_cloth_Id, false };
    stringToID["minecraft:leggings_cloth"] = { Item::leggings_cloth_Id, false };
    stringToID["minecraft:boots_cloth"] = { Item::boots_cloth_Id, false };

    stringToID["minecraft:helmet_iron"] = { Item::helmet_iron_Id, false };
    stringToID["minecraft:chestplate_iron"] = { Item::chestplate_iron_Id, false };
    stringToID["minecraft:leggings_iron"] = { Item::leggings_iron_Id, false };
    stringToID["minecraft:boots_iron"] = { Item::boots_iron_Id, false };

    stringToID["minecraft:helmet_diamond"] = { Item::helmet_diamond_Id, false };
    stringToID["minecraft:chestplate_diamond"] = { Item::chestplate_diamond_Id, false };
    stringToID["minecraft:leggings_diamond"] = { Item::leggings_diamond_Id, false };
    stringToID["minecraft:boots_diamond"] = { Item::boots_diamond_Id, false };

    stringToID["minecraft:helmet_gold"] = { Item::helmet_gold_Id, false };
    stringToID["minecraft:chestplate_gold"] = { Item::chestplate_gold_Id, false };
    stringToID["minecraft:leggings_gold"] = { Item::leggings_gold_Id, false };
    stringToID["minecraft:boots_gold"] = { Item::boots_gold_Id, false };

    stringToID["minecraft:flint"] = { Item::flint_Id, false };
    stringToID["minecraft:porkchop_raw"] = { Item::porkChop_raw_Id, false };
    stringToID["minecraft:porkchop_cooked"] = { Item::porkChop_cooked_Id, false };

    stringToID["minecraft:painting"] = { Item::painting_Id, false };
    stringToID["minecraft:apple_gold"] = { Item::apple_gold_Id, false };
    stringToID["minecraft:sign"] = { Item::sign_Id, false };

    stringToID["minecraft:bucket"] = { Item::bucket_empty_Id, false };
    stringToID["minecraft:bucket_water"] = { Item::bucket_water_Id, false };
    stringToID["minecraft:bucket_lava"] = { Item::bucket_lava_Id, false };

    stringToID["minecraft:minecart"] = { Item::minecart_Id, false };
    stringToID["minecraft:saddle"] = { Item::saddle_Id, false };

    stringToID["minecraft:redstone"] = { Item::redStone_Id, false };
    stringToID["minecraft:snowball"] = { Item::snowBall_Id, false };
    stringToID["minecraft:boat"] = { Item::boat_Id, false };

    stringToID["minecraft:leather"] = { Item::leather_Id, false };
    stringToID["minecraft:milk"] = { Item::milk_Id, false };

    stringToID["minecraft:brick"] = { Item::brick_Id, false };
    stringToID["minecraft:clay"] = { Item::clay_Id, false };

    stringToID["minecraft:reeds"] = { Item::reeds_Id, false };
    stringToID["minecraft:paper"] = { Item::paper_Id, false };
    stringToID["minecraft:book"] = { Item::book_Id, false };

    stringToID["minecraft:slimeball"] = { Item::slimeBall_Id, false };

    stringToID["minecraft:egg"] = { Item::egg_Id, false };
    stringToID["minecraft:compass"] = { Item::compass_Id, false };
    stringToID["minecraft:fishing_rod"] = { Item::fishingRod_Id, false };
    stringToID["minecraft:clock"] = { Item::clock_Id, false };

    stringToID["minecraft:bone"] = { Item::bone_Id, false };
    stringToID["minecraft:sugar"] = { Item::sugar_Id, false };
    stringToID["minecraft:cake"] = { Item::cake_Id, false };
    stringToID["minecraft:bed"] = { Item::bed_Id, false };

    stringToID["minecraft:cookie"] = { Item::cookie_Id, false };
    stringToID["minecraft:map"] = { Item::map_Id, false };

    stringToID["minecraft:shears"] = { Item::shears_Id, false };

    stringToID["minecraft:melon"] = { Item::melon_Id, false };
    stringToID["minecraft:seeds_pumpkin"] = { Item::seeds_pumpkin_Id, false };
    stringToID["minecraft:seeds_melon"] = { Item::seeds_melon_Id, false };

    stringToID["minecraft:beef_raw"] = { Item::beef_raw_Id, false };
    stringToID["minecraft:beef_cooked"] = { Item::beef_cooked_Id, false };

    stringToID["minecraft:chicken_raw"] = { Item::chicken_raw_Id, false };
    stringToID["minecraft:chicken_cooked"] = { Item::chicken_cooked_Id, false };

    stringToID["minecraft:rotten_flesh"] = { Item::rotten_flesh_Id, false };
    stringToID["minecraft:ender_pearl"] = { Item::enderPearl_Id, false };

    stringToID["minecraft:blaze_rod"] = { Item::blazeRod_Id, false };
    stringToID["minecraft:ghast_tear"] = { Item::ghastTear_Id, false };
    stringToID["minecraft:gold_nugget"] = { Item::goldNugget_Id, false };

    stringToID["minecraft:potion"] = { Item::potion_Id, false };
    stringToID["minecraft:glass_bottle"] = { Item::glassBottle_Id, false };

    stringToID["minecraft:spider_eye"] = { Item::spiderEye_Id, false };
    stringToID["minecraft:blaze_powder"] = { Item::blazePowder_Id, false };
    stringToID["minecraft:magma_cream"] = { Item::magmaCream_Id, false };

    stringToID["minecraft:brewing_stand"] = { Item::brewingStand_Id, false };
    stringToID["minecraft:cauldron"] = { Item::cauldron_Id, false };

    stringToID["minecraft:eye_of_ender"] = { Item::eyeOfEnder_Id, false };

    stringToID["minecraft:exp_bottle"] = { Item::expBottle_Id, false };

    stringToID["minecraft:emerald"] = { Item::emerald_Id, false };

    stringToID["minecraft:carrot"] = { Item::carrots_Id, false };
    stringToID["minecraft:potato"] = { Item::potato_Id, false };
    stringToID["minecraft:baked_potato"] = { Item::potatoBaked_Id, false };

    stringToID["minecraft:carrot_golden"] = { Item::carrotGolden_Id, false };

    stringToID["minecraft:carrot_on_a_stick"] = { Item::carrotOnAStick_Id, false };
    stringToID["minecraft:pumpkin_pie"] = { Item::pumpkinPie_Id, false };

    stringToID["minecraft:enchanted_book"] = { Item::enchantedBook_Id, false };
    stringToID["minecraft:nether_quartz"] = { Item::netherQuartz_Id, false };

    stringToID["minecraft:helmet_chain"] = { Item::helmet_chain_Id, false };
    stringToID["minecraft:chestplate_chain"] = { Item::chestplate_chain_Id, false };
    stringToID["minecraft:leggings_chain"] = { Item::leggings_chain_Id, false };
    stringToID["minecraft:boots_chain"] = { Item::boots_chain_Id, false };

    stringToID["minecraft:door_wood"] = { Item::door_wood_Id, false };
    stringToID["minecraft:door_iron"] = { Item::door_iron_Id, false };
    stringToID["minecraft:minecart_chest"] = { Item::minecart_chest_Id, false };
    stringToID["minecraft:minecart_furnace"] = { Item::minecart_furnace_Id, false };
    stringToID["minecraft:yellow_dust"] = { Item::yellowDust_Id, false };
    stringToID["minecraft:fish_raw"] = { Item::fish_raw_Id, false };
    stringToID["minecraft:fish_cooked"] = { Item::fish_cooked_Id, false };
    stringToID["minecraft:dye_powder"] = { Item::dye_powder_Id, false };
    stringToID["minecraft:diode"] = { Item::diode_Id, false };
    stringToID["minecraft:nether_stalk_seeds"] = { Item::netherStalkSeeds_Id, false };
    stringToID["minecraft:fermented_spider_eye"] = { Item::fermentedSpiderEye_Id, false };
    stringToID["minecraft:speckled_melon"] = { Item::speckledMelon_Id, false };
    stringToID["minecraft:monster_placer"] = { Item::monsterPlacer_Id, false };
    stringToID["minecraft:skull"] = { Item::skull_Id, false };
    stringToID["minecraft:fireball"] = { Item::fireball_Id, false };
    stringToID["minecraft:item_frame"] = { Item::itemFrame_Id, false };
    stringToID["minecraft:netherbrick"] = { Item::netherbrick_Id, false };
    stringToID["minecraft:flower_pot"] = { Item::flowerPot_Id, false };
    stringToID["minecraft:potato_poisonous"] = { Item::potatoPoisonous_Id, false };

    stringToID["minecraft:record_01"] = { Item::record_01_Id, false };
    stringToID["minecraft:record_02"] = { Item::record_02_Id, false };
    stringToID["minecraft:record_03"] = { Item::record_03_Id, false };
    stringToID["minecraft:record_04"] = { Item::record_04_Id, false };
    stringToID["minecraft:record_05"] = { Item::record_05_Id, false };
    stringToID["minecraft:record_06"] = { Item::record_06_Id, false };
    stringToID["minecraft:record_07"] = { Item::record_07_Id, false };
    stringToID["minecraft:record_08"] = { Item::record_08_Id, false };
    stringToID["minecraft:record_09"] = { Item::record_09_Id, false };
    stringToID["minecraft:record_10"] = { Item::record_10_Id, false };
    stringToID["minecraft:record_11"] = { Item::record_11_Id, false };
    stringToID["minecraft:record_12"] = { Item::record_12_Id, false };
}