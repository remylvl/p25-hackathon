#include <SDL2/SDL.h>
#include <stdbool.h>
#include "entity.h"
#include "game.h"

Room spawn_room(int *x, int *y, int *w, int *h){
    Room room = {
        .x = *x,
        .y = *y,
        .w = *w,
        .h = *h
    };
    return room;
}