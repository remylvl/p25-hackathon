#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "entity.h"
#include "dungeon.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 928

#define PLAYER_WIDTH 10
#define PLAYER_HEIGHT 16
#define PLAYER_SPEED 200.0f

#define CASE_SIZE 16
#define ROOM_NUMBER 5
#define NB_CASE_X SCREEN_WIDTH / CASE_SIZE
#define NB_CASE_Y (SCREEN_HEIGHT-64) / CASE_SIZE

bool init(SDL_Window **window, SDL_Renderer **renderer);
void handle_input(bool *running, const Uint8 *keys, Player *player, Gamestate *gamestate);
void update(Player *player, Case *cases);
void render(SDL_Renderer *renderer, Case *cases, Gamestate gamestate);
void cleanup(SDL_Window *window, SDL_Renderer *renderer);
void spawn_room(int x, int y, int w, int h, Case* cases);
void spawn_corridor(doublet porte1, doublet porte2, Case* cases);
void create_dungeon(Case* cases);
void spawn_cow_in_room(Room *room, Case *cases);
void spawn_chest_in_room(Room *room, Case *cases);
void spawn_corridorx(doublet porte1, doublet porte2, Case* cases);
void spawn_corridory(doublet porte1, doublet porte2, Case* cases);
void fontInit();
#endif
