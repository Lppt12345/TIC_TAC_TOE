#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
#include "PAINT.h"
#include "GAME.h"
#include "SDL2.h"
using namespace std;

int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_EVERYTHING )!= 0){
        cout<<"KHONG MO DUOC SDl"<<SDL_GetError();
        return -1;
    }
    SDL_Window *window = NULL;
    window = SDL_CreateWindow("TIC TAC TOE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,CD,CR,SDL_WINDOW_SHOWN);
    if (window == NULL){
        cout<<"KHONG MO DUOC CUA SO"<<SDL_GetError();
        return -1;
    }
    SDL_Renderer * render =NULL;
    render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (render == NULL){
        cout<<"KHONG MO DUOC RENDERER"<<SDL_GetError();
        return -1;
    }
    SDL_Event event;
    SDL_Rect gRect;
    SDL_Texture * gTexture = NULL;
    gTexture = IMG_LoadTexture(render,"anhnen.bmp");
    gRect.x = 0;
    gRect.y = 0;
    gRect.w = CR;
    gRect.h = CD;
    SDL_RenderCopy(render,gTexture,NULL,NULL);
    SDL_RenderPresent(render);
    bool isRun = true;
    while (isRun){
        while (SDL_PollEvent (& event)!=0){
            switch (event.type){
                case SDL_QUIT : {
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                }
                case SDL_KEYDOWN : {
                    switch (event.key.keysym.sym){
                        case SDLK_b :goto START;
                    }
                }
                default : break;
            }
        }

    }

    START:

    TIC_TAC_TOE GAME ;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            GAME.BANG[i][j]=0;
        }
    }
    GAME.NGUOI_CHOI = PLAYER_1;
    GAME.TINH_TRANG = RUNNING ;
    bool GAME_RUN = true;
    while (GAME_RUN == true){
        SDL_SetRenderDrawColor(render,0,0,0,255);
        SDL_RenderClear(render);
        while (SDL_PollEvent (& event)!=0){
            switch (event.type){
                case SDL_QUIT : {
                    goto END;
                }
                case SDL_MOUSEBUTTONDOWN : {
                    int hang, cot ;
                    hang = event.button.y/CD1;
                    cot = event.button.x/CR1;
                    if (GAME.TINH_TRANG == RUNNING){
                        PLAY_HUMAN( hang, cot, GAME );
                    }
                    break;
                }
                case SDL_KEYDOWN : {
                    switch (event.key.keysym.sym){
                        case SDLK_e :goto END;
                        case SDLK_a :goto START;
                    }
                }
                default : break;
            }
        }
        RENDER_HUMAN(render, GAME);
        SDL_RenderPresent(render);
    }

    END:

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

