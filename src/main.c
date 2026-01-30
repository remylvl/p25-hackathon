#include <SDL2/SDL.h>
#include <stdbool.h>
#include "entity.h"
#include "game.h"
#include "dungeon.h"


int main(void)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!init(&window, &renderer))
    {
        return 1;
    }

    Gamestate gamestate = GAME;

    bool running = true;
    Uint32 last_ticks = SDL_GetTicks();

    Case *cases = malloc(NB_CASE_X*NB_CASE_Y*sizeof(Case));
    for (size_t i=0; i < NB_CASE_X; i++){
        for (size_t j=0; j<NB_CASE_Y; j++){
            cases[i+NB_CASE_X*j].case_type = EMPTY;
            cases[i+NB_CASE_X*j].is_visible = true;
        }
    }
    fontInit();
    Player player = {
        .x = 7,
        .y = 7,
        .pv = 10,
        .weapon = 0,
        .armor = 0,
        .d = NONE};
    
    cases[player.x + player.y * NB_CASE_X].case_type = PLAYER;

    create_dungeon(cases);

    while (running)
    {
        Uint32 ticks = SDL_GetTicks();
        float dt = (ticks - last_ticks) / 1000.0f;
        if (dt < 0.05f)
            continue;
        last_ticks = ticks;

        SDL_PumpEvents();
        const Uint8 *keys = SDL_GetKeyboardState(NULL);
        handle_input(&running, keys, &player, &gamestate);
        update(&player, cases);
        render(renderer, cases, gamestate);
    }

    cleanup(window, renderer);
    free(cases);
    return 0;
}
