#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"
#include "entity.h"
#include <stdio.h>
#include <SDL2/SDL_ttf.h>

SDL_Color fColor;
SDL_Rect fontRect;
TTF_Font* font;

void fontInit(){
        TTF_Init();
        font = TTF_OpenFont("./font/ARIAL.TTF", 20);
        fColor.r = 255;
        fColor.g = 255;
        fColor.b = 255;
}

void render(SDL_Renderer *renderer, Case *cases, Gamestate gamestate)
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
                case PORTE :                
                surface = SDL_LoadBMP("images/door.bmp");
                texture = SDL_CreateTextureFromSurface(renderer,surface);
                SDL_FreeSurface(surface);
                SDL_RenderCopy(renderer,texture,NULL,&case_rect);
                break;
                default : break;
            }
            
        }
    }
	
    if (gamestate==1){
        SDL_Rect inventory_rect1 = {
                    10*CASE_SIZE, 5*CASE_SIZE,
                    CASE_SIZE*60, CASE_SIZE*50};
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderFillRect(renderer, &inventory_rect1);
        
        SDL_Surface* fontSurface = TTF_RenderText_Solid(font, "Inventory", fColor);
        if (fontSurface) {
            SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);
            SDL_Rect fontRect = {38*CASE_SIZE, 6*CASE_SIZE, fontSurface->w, fontSurface->h};
            SDL_RenderCopy(renderer, fontTexture, NULL, &fontRect);
            SDL_DestroyTexture(fontTexture);
            SDL_FreeSurface(fontSurface);
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