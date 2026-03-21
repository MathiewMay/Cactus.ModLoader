#pragma once

#include "includes/sol/sol.hpp"
#include "../../Minecraft.World/Items/Item.h"
#include "../../Minecraft.World/Items/FoodItem.h"
#include "../../Minecraft.World/Items/HoeItem.h"
#include "../../Minecraft.World/Items/WeaponItem.h"
#include "../../Minecraft.World/Items/PickaxeItem.h"
#include "../../Minecraft.World/Items/HatchetItem.h"

enum EBaseItem {
    Default,
    Food,
    Hoe,
    Weapon,
    // Note: Segfault when using DiggerItems
    Pickaxe,
    Hatchet,

};

struct ItemDefinition {
    EBaseItem type;

    // Food Items
    int nutrition = 0;
    float saturationMod = 0.0;
    bool isMeat = false;

    // Tool Items
    const Item::Tier* tier = Item::Tier::WOOD;

    ItemDefinition(sol::table items) {
        type = items["base"].get<EBaseItem>();
        sol::optional<int> n = items["nutrition"];
        sol::optional<float> s = items["saturationMod"];
        sol::optional<bool> meat = items["isMeat"];
        sol::optional<Item::Tier*> t = items["tier"];

        if (n) nutrition = n.value();
        if (s) saturationMod = s.value();
        if (meat) isMeat = meat.value();
        if (t) tier = t.value();
    }
};

class ItemFactory {
public:
    static Item* create(const ItemDefinition& def, int id) {
        switch (def.type) {
            case EBaseItem::Hatchet:
                return (new HatchetItem(id,def.tier));
            case EBaseItem::Pickaxe:
                return (new PickaxeItem(id,def.tier));
            case EBaseItem::Weapon:
                return (new WeaponItem(id,def.tier));
            case EBaseItem::Hoe:
                return (new HoeItem(id,def.tier));
            case EBaseItem::Food:
                return (new FoodItem(id,def.nutrition,def.saturationMod,def.isMeat));
            case EBaseItem::Default:
            default:
                return (new Item(id));
        }
    }
};