#ifndef DUNGEON_H
#define DUNGEON_H

enum Case_type {
    EMPTY,
    WALL,
    PLAYER,
    INSIDE,
    PORTE,
    ITEM,
    MONSTER,
};
typedef enum Case_type Case_type;

typedef struct 
{
    int x, y;
    Case_type case_type;
    int Id;
    bool afficher;
} Case;

typedef struct 
{
    int x, y;
    int w, h;
    bool is_active;
} Room;

typedef enum {
    GAME,
    INVENTORY,
} Gamestate;

#endif