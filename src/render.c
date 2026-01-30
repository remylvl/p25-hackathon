#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"
#include "entity.h"
#include <stdio.h>


void render(SDL_Renderer *renderer, Case *cases)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    for (size_t i=0; i<NB_CASE_X; i++){
        for (size_t j=0; j<NB_CASE_Y; j++){
            if(!cases[i + j * NB_CASE_X].is_visible) continue;
            Case_type case_type_actuel = cases[i+j*NB_CASE_X].case_type;
            SDL_Rect case_rect = {
                    i*CASE_SIZE, j*CASE_SIZE,
                    CASE_SIZE, CASE_SIZE};
            
            

            SDL_Surface *s = SDL_LoadBMP("images/inside.bmp");
            SDL_Texture *t = SDL_CreateTextureFromSurface(renderer,s);
            SDL_FreeSurface(s);
            SDL_RenderCopy(renderer,t,NULL,&case_rect);

            SDL_Surface *surface;
            SDL_Texture *texture;

            switch(case_type_actuel){
                case EMPTY :
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(renderer, &case_rect);
                break;
                case PLAYER :                
                surface = SDL_LoadBMP("images/hero.bmp");
                texture = SDL_CreateTextureFromSurface(renderer,surface);
                SDL_FreeSurface(surface);
                SDL_RenderCopy(renderer,texture,NULL,&case_rect);
                break;
                case WALL :                
                surface = SDL_LoadBMP("images/brick.bmp");
                texture = SDL_CreateTextureFromSurface(renderer,surface);
                SDL_FreeSurface(surface);
                SDL_RenderCopy(renderer,texture,NULL,&case_rect);
                break;
                case MONSTER :                
                surface = SDL_LoadBMP("images/vache.bmp");
                texture = SDL_CreateTextureFromSurface(renderer,surface);
                SDL_FreeSurface(surface);
                SDL_RenderCopy(renderer,texture,NULL,&case_rect);
                break;
                case ITEM :                
                surface = SDL_LoadBMP("images/chest.bmp");
                texture = SDL_CreateTextureFromSurface(renderer,surface);
                SDL_FreeSurface(surface);
                SDL_RenderCopy(renderer,texture,NULL,&case_rect);
                break;
                default : break;
            }
            
        }
    }
	

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