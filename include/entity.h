#ifndef ENTITY_H
#define ENTITY_H

enum Weapon {
    RUSTED_DAGGER, //0
    TRAVELER_SHORTSWORD, //1
    IRON_AXE, //2
    STEEL_WAR_SPEAR, //3
    LONGBLADE_OF_VALOR, //4
    RUNEFORGED_WARHAMMER, //5
    HERO_LIFEDRINKER_BLADE, //6
    ANCIENT_KINGSLAYER_SWORD, //7
    GODCLEAVER_RELIC_WEAPON, //8
    WORLDENDER_ARMAMENT, //9
};
typedef enum Weapon Weapon;

enum Armor {
    TORN_TUNIC, //0
    HARDENED_LEATHER_VEST, //1
    REINFORCED_LEATHER_ARMOR, //2
    CHAINMAIL_OF_THE_LEGION, //3
    HEAVY_KNIGHT_PLATE, //4
    RUNIC_GUARDIAN_ARMOR, //5
    HEROIC_BASTION_ARMOR, //6
    LEGENDARY_WARLORD_ARMOR, //7
    MYTHIC_AEGIS_ARMOR, //8
    ABSOLUTE_ETERNITY_ARMOR, //9
};
typedef enum Armor Armor;

enum Direction {
    UP, 
    DOWN, 
    LEFT,
    RIGHT,
    NONE
};
typedef enum Direction Direction;

typedef struct
{
    int x, y;
    int pv;
    Armor armor;
    Weapon weapon;
    Direction d;
} Player;

typedef struct
{
    int x, y;
    int pv;
    int damage;
    int Id;
} Monster;

#endif
