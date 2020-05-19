#include <bits/stdc++.h>
#include "PAINT.h"
#include <SDL.h>
#include <SDL_image.h>


void RENDER_PLAYER1(SDL_Renderer * render, int hang , int cot, const SDL_Color *Color){
    float quater_small_box = CD1/4;
    float X = cot * CR1;
    float Y = hang *CD1;
    float x1 = 2 * quater_small_box + X;
    float y1 = quater_small_box + Y;
    float x2 = quater_small_box + X;
    float y2 = 3 * quater_small_box +Y;
    float x3 = 3 * quater_small_box +X;
    float y3 = y2;
    SDL_SetRenderDrawColor(render,Color->r,Color->g,Color->b,255);
    for (int i = 0; i<=DD ;i++){
        SDL_RenderDrawLine(render,x1-i,y1,x2-i,y2);
        SDL_RenderDrawLine(render,x2,y2-i,x3,y3-i);
        SDL_RenderDrawLine(render,x1+i,y1,x3+i,y3);
    }
}

void RENDER_PLAYER2(SDL_Renderer * render, int hang , int cot, const SDL_Color *Color){
    float quater_small_box = CD1/4;
    float X = cot * CR1;
    float Y = hang *CD1;
    float x1 = quater_small_box + X;
    float y1 = quater_small_box + Y;
    float x2 = 3 * quater_small_box + X;
    float y2 = 3 * quater_small_box + Y;
    float x3 = x2;
    float y3 = y1;
    float x4 = x1;
    float y4 = y2;
    SDL_SetRenderDrawColor(render,Color->r,Color->g,Color->b,255);
    for (int i= 0; i<= DD ; i++){
        SDL_RenderDrawLine(render,x1+i,y1,x2+i,y2);
        SDL_RenderDrawLine(render,x3+i,y3,x4+i,y4);
    }
}

void RENDER_HUMAN(SDL_Renderer *render, TIC_TAC_TOE &GAME){
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255 );
    for (int i=1;i<N;i++){
        SDL_RenderDrawLine(render, i * CR1, 0 , i * CR1, CD);
        SDL_RenderDrawLine(render, 0, i * CD1, CR , i*CD1);
    }
    if (GAME.TINH_TRANG == RUNNING) {
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (GAME.BANG[i][j]==PLAYER_1) RENDER_PLAYER1(render,i,j,&PLAYER1);
                if (GAME.BANG[i][j]==PLAYER_2) RENDER_PLAYER2(render,i,j,&PLAYER2);
            }
        }
    }
    else RENDER_GAME(render,GAME);
}

void RENDER_GAME (SDL_Renderer * render,TIC_TAC_TOE &GAME){
    if (GAME.TINH_TRANG == DRAW) RENDER_WIN_DRAW(render,GAME,&Draw);
    else if (GAME.TINH_TRANG==PLAYER_1) RENDER_WIN_DRAW(render,GAME,&PLAYER1);
        else RENDER_WIN_DRAW(render,GAME,&PLAYER2);
}

void RENDER_WIN_DRAW (SDL_Renderer *render,TIC_TAC_TOE & GAME,const SDL_Color *Color){
    SDL_Color TEMP= *Color;
    for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (GAME.BANG[i][j]==PLAYER_1) RENDER_PLAYER1(render,i,j,&TEMP);
                if (GAME.BANG[i][j]==PLAYER_2) RENDER_PLAYER2(render,i,j,&TEMP);
            }
    }
}

