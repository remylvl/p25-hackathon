#ifndef ENTITY_H
#define ENTITY_H

enum Weapon {
    STICK, //0
    KNIFE, //1
    SWORD //2
};
typedef enum Weapon Weapon;

enum Armor {
    NOTHING, //0
    METAL //1
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

enum case_type {
    EMPTY,
    WALL,
    PLAYER,
    INSIDE,
    PORTE,
    ITEM,
    MONSTER,
};
typedef enum case_type case_type

typedef struct 
{
    int x, y;
    case_type case_type;
    int Id;
    bool afficher;
} Case;


typedef struct 
{
    int x, y;
    int w, h;
<<<<<<< HEAD
=======
    room_type type;
    bool is_active;
>>>>>>> d9c58174541b4324694150138d1caacf43fbb1d9
} Room;

type def struct
{
    
} CORRIDOR;

typedef struct
{
    int x, y;
    int pv;
    int w, h;
    Armor armor;
    Weapon weapon;
    Direction d;
} Player;


typedef struct
{
    int x, y;
    int pv;
    int damage;
} Monster;



#endif
