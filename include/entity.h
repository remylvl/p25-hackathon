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
