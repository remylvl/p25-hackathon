#include <SDL2/SDL.h>
#include "game.h"
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

void handle_input(bool *running, const Uint8 *keys, Entity *player)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            *running = false;
    }

    player->vx = 0.0f;
    player->vy = 0.0f;
    if (keys[SDL_SCANCODE_LEFT])
        player->vx = -PLAYER_SPEED;
    if (keys[SDL_SCANCODE_RIGHT])
        player->vx = PLAYER_SPEED;
    if (keys[SDL_SCANCODE_UP])
        player->vy = -PLAYER_SPEED;
    if (keys[SDL_SCANCODE_DOWN])
        player->vy = PLAYER_SPEED;

}

void update(Entity *player, float dt)
{
    player->x += player->vx * dt;
    player->y += player->vy * dt;

    if (player->x < 0)
        player->x = 0;
    if (player->x + player->w > SCREEN_WIDTH)
        player->x = SCREEN_WIDTH - player->w;

    if (player->y < 0)
        player->y = 0;
    if (player->y + player->h > SCREEN_HEIGHT)
        player->y = SCREEN_HEIGHT - player->h;

}

void render(SDL_Renderer *renderer, Entity *player)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect player_rect = {
        (int)player->x, (int)player->y,
        player->w, player->h};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &player_rect);

    SDL_RenderPresent(renderer);
}

void cleanup(SDL_Window *window, SDL_Renderer *renderer)
{
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}
