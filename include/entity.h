#ifndef ENTITY_H
#define ENTITY_H

enum Weapon {
    STICK, //0
    KNIFE, //1
    SWORD //2
};
typedef enum Weapon Weapon;

enum Direction {
    UP, 
    DOWN, 
    LEFT,
    RIGHT,
    NONE
};
typedef enum Direction Direction;

enum Armor {
    NOTHING, //0
    METAL //1
};
typedef enum Armor Armor;

typedef enum {
    ROOM,
    CORRIDOR,
} room_type;

typedef enum {
    EMPTY,
    WALL,
    ITEM,
    PLAYER,
    MONSTER,
    INSIDE,
} case_type;

typedef struct {
    int x, y;
    int w, h;
    room_type type;
} Room;

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

} Monster;



#endif
