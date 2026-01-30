#ifndef ENTITY_H
#define ENTITY_H

enum weapon {
    stick, //0
    knife, //1
    sword //2
};
typedef enum weapon weapon;


enum armor {
    nothing, //0
    metal //1
};
typedef enum armor armor;


typedef struct
{
    int x, y;
    int pv;
    armor armor;
    weapon weapon;
    
} player;


typedef struct
{

} monster;



#endif


