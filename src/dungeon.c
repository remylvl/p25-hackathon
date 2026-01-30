#include <SDL2/SDL.h>
#include <stdbool.h>
#include "entity.h"
#include "game.h"

//x et y sont le coin en haut à gauche de la room
void spawn_room(int x, int y, int w, int h, Case* cases){
    for (int k = x ; k < x+w; k++){
        cases[k + NB_CASE_X*y].case_type = WALL;
        cases[k + NB_CASE_X*(y+h-1)].case_type = WALL;
    }
    for (int k = y+1 ; k < y+h-1 ; k++){
        cases[x + NB_CASE_X*k].case_type = WALL;
        cases[x+w-1 + NB_CASE_X*k].case_type = WALL;
    }
    for (int i = x+1 ; i < x+w-1 ; i++){
        for (int j = y+1 ; j < y+h-1 ; j++){
            cases[i + NB_CASE_X*j].case_type = INSIDE;
        }
    }
}