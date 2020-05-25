#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
#include "PAINT.h"
#include "GAME.h"
#include "AI.h"

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
    SDL_Texture * anhnen = NULL; // GPU

    TIC_TAC_TOE GAME ;
    bool isRun = true;

    MENU :

    anhnen = IMG_LoadTexture(render,"anhnen.bmp");
    SDL_RenderCopy(render,anhnen,NULL,NULL);
    SDL_RenderPresent(render);
    isRun = true;
    while (isRun){
        while (SDL_PollEvent (& event)!=0){
            switch (event.type){
                case SDL_QUIT : {
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                }
                case SDL_KEYDOWN : {
                    switch (event.key.keysym.sym){
                        case SDLK_h :goto HUMAN_GAME;
                        case SDLK_a :goto AI;
                        case SDLK_e :goto END;
                    }
                }
                default : break;

            }
        }

    }

    HUMAN_GAME:

    GAME.BEGIN(PLAYER_1);
    isRun = true;
    while (isRun == true){
        SDL_SetRenderDrawColor(render,0,0,0,255);     // dat mau den cho background
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
                    if (GAME.State == RUNNING){
                        PLAY_HUMAN_GAME( hang, cot, GAME );
                    }
                    break;
                }
                case SDL_KEYDOWN : {
                    switch (event.key.keysym.sym){
                        case SDLK_e :goto END;
                        case SDLK_h :goto HUMAN_GAME;
                        case SDLK_m :goto MENU;
                    }
                }
                default : break;
            }
        }
        RENDER_GAME(render, GAME);
        SDL_RenderPresent(render);
    }

    AI:

    GAME.BEGIN(PLAYER_1);
    isRun = true;
    while (isRun == true){
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
                    if (GAME.State == RUNNING){
                        if (GAME.BANG[hang][cot] == 0){
                            GAME.Player = PLAYER_1;
                            GAME.BANG[hang][cot] = PLAYER_1;
                            GAME.State = CheckWin(GAME);
                            if (GAME.State == RUNNING){
                                AI_TURN (GAME);
                            }
                        }
                    }
                    break;
                }
                case SDL_KEYDOWN : {
                    switch (event.key.keysym.sym){
                        case SDLK_e :goto END;
                        case SDLK_a :goto AI;
                        case SDLK_m :goto MENU;
                    }
                }
                default : break;
            }
        }
        RENDER_GAME(render, GAME);
        SDL_RenderPresent(render);
    }

    END:

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

