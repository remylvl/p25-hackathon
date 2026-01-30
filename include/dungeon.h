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
    bool is_visible;
} Case;

typedef struct{
    int x, y;
}doublet;

typedef struct 
{
    int x, y;
    int w, h;
    bool is_active;
    doublet porte_sud;
    doublet porte_nord;
    doublet porte_est;
    doublet porte_ouest;
} Room;

typedef enum {
    GAME,
    INVENTORY,
} Gamestate;

typedef struct{
    int x, y;
}doublet;

#endif