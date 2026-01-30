#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "entity.h"

#define SCREEN_WIDTH 1260
#define SCREEN_HEIGHT 960

#define PLAYER_WIDTH 10
#define PLAYER_HEIGHT 16
#define PLAYER_SPEED 200.0f

#define CASE_SIZE 16
#define ROOM_NUMBER 5
#define NB_CASE_X SCREEN_WIDTH / CASE_SIZE
#define NB_CASE_Y SCREEN_HEIGHT / CASE_SIZE

bool init(SDL_Window **window, SDL_Renderer **renderer);
void handle_input(bool *running, const Uint8 *keys, Player *player);
<<<<<<< HEAD
void update(Player *player, Case *cases);
void render(SDL_Renderer *renderer, Player *player);
=======
void update(Player *player);
void render(SDL_Renderer *renderer, Player *player, Case *cases);
>>>>>>> 0d25ba7080839353a37d1758d93df6b4916e5862
void cleanup(SDL_Window *window, SDL_Renderer *renderer);
Room spawn_room(int *x, int *y, int *w, int *h);

#endif
