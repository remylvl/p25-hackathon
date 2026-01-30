#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"
#include <stdio.h>


void render(SDL_Renderer *renderer, Player *player, Case *cases)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (size_t i=0; i<NB_CASE_X; i++){
        for (size_t j=0; j<NB_CASE_Y; i++){
            
        }
    }
	SDL_Surface *surface=SDL_LoadBMP("images/hero.bmp");
    SDL_Texture *texture=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect = {player->x,player->y,player->w,player->h};
    SDL_RenderCopy(renderer,texture,NULL,&rect);

    SDL_RenderPresent(renderer);
}

void cleanup(SDL_Window *window, SDL_Renderer *renderer)
{
    if (renderer){
        SDL_DestroyRenderer(renderer);
        }
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}