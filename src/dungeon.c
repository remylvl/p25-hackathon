#include <SDL2/SDL.h>
#include <stdbool.h>
#include "entity.h"
#include "game.h"
#include <stdlib.h>
#include "dungeon.h"

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

void create_dungeon(Case* cases){
    Room* rooms = malloc(9*sizeof(Room));
    for (int k = 0 ; k < 9 ; k++){
        rooms[k].w = rand() % 11 + 12;
        rooms[k].h = rand() % 11 + 5;
        rooms[k].x = rand() % 5 + ((k%3) * 26);
        rooms[k].y = rand() % 5 + ((k/3) * 20);
        rooms[k].is_active = false;
        rooms[k].porte_sud.x = 0;
        rooms[k].porte_sud.y = 0;
        rooms[k].porte_nord.x = 0;
        rooms[k].porte_nord.y = 0;
        rooms[k].porte_est.x = 0;
        rooms[k].porte_est.y = 0;
        rooms[k].porte_ouest.x = 0;
        rooms[k].porte_ouest.y = 0;
        spawn_room(rooms[k].x, rooms[k].y, rooms[k].w, rooms[k].h, cases); 
        // une fois les rooms créés on fais les portes
    }
    for (int k = 0 ; k < 9 ; k++){
        if (k>2){
            int xp = rand() % (rooms[k].w - 2) + rooms[k].x + 1;
            cases[xp + rooms[k].y * NB_CASE_X].case_type = PORTE;
        }
        if (k<6){
            int xp = rand() % (rooms[k].w - 2) + rooms[k].x + 1;
            cases[xp + (rooms[k].y+rooms[k].h -1) * NB_CASE_X].case_type = PORTE;
        }
        if (k%3 != 2){
            int yp = rand() % (rooms[k].h - 2) + rooms[k].y + 1;
            cases[(rooms[k].x + rooms[k].w - 1) + yp*NB_CASE_X ].case_type = PORTE;
        }
        if (k%3 != 0){
            int yp = rand() % (rooms[k].h - 2) + rooms[k].y + 1;
            cases[rooms[k].x  + yp*NB_CASE_X ].case_type = PORTE;
        }
    }
}