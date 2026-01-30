#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"
#include "dungeon.h"
#include "entity.h"
#include "dungeon.h"
#include <stdio.h>
#include <SDL2/SDL_ttf.h>

SDL_Color fColor;
SDL_Color fBlack;
SDL_Rect fontRect;
TTF_Font* font;
TTF_Font* fontSTART;

void fontInit(){
        TTF_Init();
        font = TTF_OpenFont("font/ARIAL.TTF", 26);
        fontSTART = TTF_OpenFont("font/ARIAL.TTF", 45);
        fColor.r = 255;
        fColor.g = 255;
        fColor.b = 255;
        fBlack.r = 0;
        fBlack.g = 0;
        fBlack.b = 0;
}

void render(SDL_Renderer *renderer, Case *cases, Gamestate gamestate, Player player)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (gamestate==0)
    {
        SDL_Rect startmenu_rect = {
                        10*CASE_SIZE, 5*CASE_SIZE,
                        CASE_SIZE*60, CASE_SIZE*50};
            SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
            SDL_RenderFillRect(renderer, &startmenu_rect);
        
        SDL_Rect startmenu_case = {
                        15*CASE_SIZE, 15*CASE_SIZE,
                        CASE_SIZE*50, CASE_SIZE*5};
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_RenderFillRect(renderer, &startmenu_case);
        
        SDL_Surface* fontSurfaceStart = TTF_RenderText_Solid(fontSTART, "1) START", fBlack);
                if (fontSurfaceStart) {
                    SDL_Texture* fontTextureStart = SDL_CreateTextureFromSurface(renderer, fontSurfaceStart);
                    SDL_Rect fontRectStart = {33*CASE_SIZE, 16*CASE_SIZE, fontSurfaceStart->w, fontSurfaceStart->h};
                    SDL_RenderCopy(renderer, fontTextureStart, NULL, &fontRectStart);
                    SDL_DestroyTexture(fontTextureStart);
                    SDL_FreeSurface(fontSurfaceStart);
                }
        
        
    }
    
    else
    {
        
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
        
        if (gamestate==2){
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

            if(player.armor){
                SDL_Surface* fontSurface_Armor = TTF_RenderText_Solid(font, "TORN_TUNIC", fColor);
                if (fontSurface_Armor) {
                    SDL_Texture* fontTexture_Armor = SDL_CreateTextureFromSurface(renderer, fontSurface_Armor);
                    SDL_Rect fontRect_Armor = {12*CASE_SIZE, 8*CASE_SIZE, fontSurface_Armor->w, fontSurface_Armor->h};
                    SDL_RenderCopy(renderer, fontTexture_Armor, NULL, &fontRect_Armor);
                    SDL_DestroyTexture(fontTexture_Armor);
                    SDL_FreeSurface(fontSurface_Armor);
                }
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