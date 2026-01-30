#include <SDL2/SDL.h>
#include <stdbool.h>
#include "entity.h"
#include "game.h"

int main(void)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!init(&window, &renderer))
    {
        return 1;
    }

    bool running = true;
    Uint32 last_ticks = SDL_GetTicks();

    Case *cases = malloc(NB_CASE_X*NB_CASE_Y*sizeof(Case));
    for (size_t i=0; i < NB_CASE_X; i++){
        for (size_t j=0; j<NB_CASE_Y; j++){
            cases[i+NB_CASE_X*j].case_type = EMPTY;
        }
    }

    Player player = {
        .x = CASE_SIZE * 20,
        .y = CASE_SIZE * 20,
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT,
        .d = NONE};

    while (running)
    {
        Uint32 ticks = SDL_GetTicks();
        float dt = (ticks - last_ticks) / 1000.0f;
        SDL_PumpEvents();
        const Uint8 *keys = SDL_GetKeyboardState(NULL);
        handle_input(&running, keys, &player);
        if (dt < 0.1f)
            continue;
        last_ticks = ticks;

        
        update(&player);
        render(renderer, &player);
    }

    cleanup(window, renderer);
    return 0;
    free(cases);
}
