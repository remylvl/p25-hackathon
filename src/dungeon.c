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

void spawn_corridor(Case porte1, Case porte2, Case* cases){
    int x1 = porte1.x;
    int y1 = porte1.y;
    int x2 = porte2.x;
    int y2 = porte2.y;
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;
    int ix = 0;
    if (x1<x2){
        xmin = x1;
        xmax = x2;
        ix = 1;
    }
    if (x2 <= x1){
        xmin = x2;
        xmax = x1;
        ix = 2;
    }
    if (y1<y2){
        ymin = y1;
        ymax = y2;
    }
    if (y2 <= y1){
        ymin = y2;
        ymax = y1;
    }
    if (ix == 1){
        for (int k = xmin + 1; k < xmax ; k++){
            cases[k + y1*NB_CASE_X].case_type = INSIDE;
        }
    }
    if (ix == 2){
        for (int k = xmin + 1; k < xmax ; k++){
            cases[k + y2*NB_CASE_X].case_type = INSIDE;
        }
    }
    for (int k = ymin + 1; k < ymax ; k++){
        cases[xmax - 1 + k*NB_CASE_X].case_type = INSIDE;
    }   
}