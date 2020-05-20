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
    SDL_SetRenderDrawColor(render, 0, 0, 255, 255 );
    for (int i =1;i<N;i++){
        for (int j=0;j<DD;j++){
            SDL_RenderDrawLine(render, i * CR1+j, 0 , i * CR1+j, CD);
            SDL_RenderDrawLine(render, 0, i * CD1+j, CR , i * CD1+j);
        }
    }
    if (GAME.TINH_TRANG == RUNNING) {
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (GAME.BANG[i][j]== PLAYER_1) RENDER_PLAYER1(render,i,j,&PLAYER1);
                if (GAME.BANG[i][j]== PLAYER_2) RENDER_PLAYER2(render,i,j,&PLAYER2);
            }
        }
    }
    else {
        if (GAME.TINH_TRANG == DRAW) RENDER_DRAW(render,GAME,&Draw);
        else RENDER_WIN(render,GAME);
    };
}

void RENDER_DRAW (SDL_Renderer *render,TIC_TAC_TOE & GAME,const SDL_Color *Color){
    SDL_Color TEMP= *Color;
    for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (GAME.BANG[i][j]==PLAYER_1) RENDER_PLAYER1(render,i,j,&TEMP);
                if (GAME.BANG[i][j]==PLAYER_2) RENDER_PLAYER2(render,i,j,&TEMP);
            }
    }
}

void RENDER_WIN(SDL_Renderer * render,TIC_TAC_TOE &GAME){
    bool check =false;
    for (int i=0;i<N;i++){
        if (checkWinHang(GAME,i)== GAME.NGUOI_CHOI) {
            check= true;
            RENDER_HANG(render, GAME, i );
            break;
        }
        else if (checkWinCot(GAME,i) == GAME.NGUOI_CHOI){
            check = true;
            RENDER_COT(render, GAME , i);
            break;
        };
    }
    if (check==false){
        if (checkWinCheo1(GAME)== GAME.NGUOI_CHOI) {
            RENDER_CHEO1(render,GAME);
        }
        else if (checkWinCheo2(GAME)== GAME.NGUOI_CHOI){
            RENDER_CHEO2(render,GAME);
        };
    }
}
void RENDER_HANG(SDL_Renderer *render,TIC_TAC_TOE &GAME,int hang){
    RENDER_DRAW (render, GAME, &LOSS);
    for (int j=0 ;j<N;j++){
        if (GAME.BANG[hang][j]==PLAYER_1) RENDER_PLAYER1(render,hang,j,&PLAYER1);
        if (GAME.BANG[hang][j]==PLAYER_2) RENDER_PLAYER2(render,hang,j,&PLAYER2);
    }
}

void RENDER_COT(SDL_Renderer *render,TIC_TAC_TOE &GAME,int cot){
    RENDER_DRAW (render, GAME, &LOSS);
    for (int i=0 ;i<N;i++){
        if (GAME.BANG[i][cot]==PLAYER_1) RENDER_PLAYER1(render,i,cot,&PLAYER1);
        if (GAME.BANG[i][cot]==PLAYER_2) RENDER_PLAYER2(render,i,cot,&PLAYER2);
    }
}

void RENDER_CHEO1(SDL_Renderer *render, TIC_TAC_TOE &GAME){
    RENDER_DRAW (render, GAME, &LOSS);
    for (int i=0;i<N;i++){
        if (GAME.BANG[i][i]==PLAYER_1) RENDER_PLAYER1(render,i,i,&PLAYER1);
        if (GAME.BANG[i][i]==PLAYER_2) RENDER_PLAYER2(render,i,i,&PLAYER2);
    }
}
void RENDER_CHEO2(SDL_Renderer *render, TIC_TAC_TOE &GAME){
    RENDER_DRAW (render, GAME, &LOSS);
    for (int i=0;i<N;i++){
        if (GAME.BANG[i][N-i-1]==PLAYER_1) RENDER_PLAYER1(render,i,N-i-1,&PLAYER1);
        if (GAME.BANG[i][N-i-1]==PLAYER_2) RENDER_PLAYER2(render,i,N-i-1,&PLAYER2);
    }
}

