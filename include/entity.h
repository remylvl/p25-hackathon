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

typedef enum {
    ROOM,
    CORRIDOR,
} room_type;

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
} Player;


typedef struct
{

} Monster;



#endif


