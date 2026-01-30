#include <SDL2/SDL.h>
#include <stdbool.h>
#include "entity.h"
#include "game.h"
#include <stdlib.h>


void spawn_chest_in_room(Room *room, Case *cases){
    int x = rand() % (room->w - 2) + room->x + 1;
    int y = rand() % (room->h - 2) + room->y + 1;
    cases[x + NB_CASE_X * y].case_type = ITEM;
}