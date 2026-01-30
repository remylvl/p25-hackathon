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
        if (dt < 0.25f)
            continue;
        last_ticks = ticks;

        SDL_PumpEvents();
        const Uint8 *keys = SDL_GetKeyboardState(NULL);
        handle_input(&running, keys, &player);
        update(&player, dt);
        render(renderer, &player);
    }

    cleanup(window, renderer);
    return 0;
}
