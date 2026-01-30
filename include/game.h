#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "entity.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

#define PLAYER_WIDTH 10
#define PLAYER_HEIGHT 15
#define PLAYER_SPEED 200.0f

#define CASE_SIZE 15

bool init(SDL_Window **window, SDL_Renderer **renderer, SDL_Texture *img);
void handle_input(bool *running, const Uint8 *keys, Player *player);
void update(Player *player, float dt);
void render(SDL_Renderer *renderer, Player *player, SDL_Texture *img);
void cleanup(SDL_Window *window, SDL_Renderer *renderer);

#endif
