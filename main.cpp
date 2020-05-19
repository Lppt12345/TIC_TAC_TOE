#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
#include "PAINT.h"
#include "GAME.h"
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
    TIC_TAC_TOE GAME ;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            GAME.BANG[i][j]=0;
        }
    }
    GAME.NGUOI_CHOI = PLAYER_1;
    GAME.TINH_TRANG = RUNNING ;

    SDL_Event event;
    while (GAME.TINH_TRANG != QUIT){
        SDL_SetRenderDrawColor(render,0,0,0,255);
        SDL_RenderClear(render);
        while (SDL_PollEvent (& event)){
            switch (event.type){
                case SDL_QUIT : {
                    GAME.TINH_TRANG = QUIT;
                    break;
                }
                case SDL_MOUSEBUTTONDOWN : {
                    int hang = event.button.y/CD1;
                    int cot = event.button.x/CR1;
                    PLAY( hang, cot, GAME );
                    break;
                }
                default : break;
            }
        }
        RENDER_HUMAN(render, GAME);
        SDL_RenderPresent(render);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

