#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"
#include "dungeon.h"
#include <stdio.h>

bool init(SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Erreur SDL_Init: %s", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("Space Invaders (SDL)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!*window)
    {
        SDL_Log("Erreur SDL_CreateWindow: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!*renderer)
    {
        SDL_Log("Erreur SDL_CreateRenderer: %s", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }
    

    return true;
}

void handle_input(bool *running, const Uint8 *keys, Player *player, Gamestate *gamestate)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            *running = false;
    }

    if(*gamestate==0)
    {
        player->d = NONE;
        if (keys[SDL_SCANCODE_LEFT])
            player->d = LEFT;
        if (keys[SDL_SCANCODE_RIGHT])
            player->d = RIGHT;
        if (keys[SDL_SCANCODE_UP])
            player->d = UP;
        if (keys[SDL_SCANCODE_DOWN])
            player->d = DOWN;
        if (keys[SDL_SCANCODE_I])
            *gamestate = 1;
    }

}

void update(Player *player, Case *cases)
{
    switch(player->d){
        case UP: 
        if(cases[player->x + NB_CASE_X * (player->y-1)].case_type != EMPTY && cases[player->x + NB_CASE_X * (player->y-1)].case_type != WALL){        
        cases[player->x + NB_CASE_X * (player->y-1)].case_type = PLAYER;
        cases[player->x + NB_CASE_X * player->y].case_type = INSIDE;
        player->y -= 1;
        }
        break;
        case DOWN: 
        if(cases[player->x + NB_CASE_X * (player->y+1)].case_type != EMPTY && cases[player->x + NB_CASE_X * (player->y+1)].case_type != WALL){        
        cases[player->x + NB_CASE_X * (player->y+1)].case_type = PLAYER;
        cases[player->x + NB_CASE_X * player->y].case_type = INSIDE;
        player->y += 1;
        }
        break;
        case LEFT:
        if(cases[player->x + NB_CASE_X * player->y - 1].case_type != EMPTY && cases[player->x + NB_CASE_X * player->y - 1].case_type != WALL){        
        cases[player->x + NB_CASE_X * player->y - 1].case_type = PLAYER;
        cases[player->x + NB_CASE_X * player->y].case_type = INSIDE;
        player->x -= 1;
        }
        break;
        case RIGHT: 
        if(cases[player->x + NB_CASE_X * player->y + 1].case_type != EMPTY && cases[player->x + NB_CASE_X * player->y + 1].case_type != WALL){        
        cases[player->x + NB_CASE_X * player->y + 1].case_type = PLAYER;
        cases[player->x + NB_CASE_X * player->y].case_type = INSIDE;
        player->x += 1;
        }
        break;
        default: break;
    }


}
