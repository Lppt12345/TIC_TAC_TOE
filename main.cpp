#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
using namespace std;
const SDL_Color WhiteColor = {255,255,255};
const SDL_Color PLAYER1 = {0,128,0};
const SDL_Color PLAYER2 = {128,0,128};
const SDL_Color Draw = {255,165,0};

int const N = 3;

int const DD = 3;

float const CD = 600;

float const CR = CD;

float const CD1 = CD/N;

float const CR1= CR/N;

float const PLAYER_1 = 1;

float const PLAYER_2 = 2;

float const WINP1 = PLAYER_1;

float const WINP2 = PLAYER_2;

float const DRAW = 0;

float const QUIT = -1;

float const RUNNING = 3;

struct TIC_TAC_TOE{
    int BANG [N][N];
    int NGUOI_CHOI;
    int TINH_TRANG;
};

void reset (TIC_TAC_TOE &GAME){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            GAME.BANG[i][j]=0;
        }
    }
    GAME.NGUOI_CHOI = PLAYER_1;
    GAME.TINH_TRANG = RUNNING ;
}

int checkWinCot(TIC_TAC_TOE &GAME, int cot){
    for (int i=0;i<N;i++){
        if (GAME.BANG[i][cot] != GAME.NGUOI_CHOI) return RUNNING;
    }
    return GAME.NGUOI_CHOI;
}

int checkWinHang(TIC_TAC_TOE &GAME, int hang){
    for (int i=0;i<N;i++){
        if (GAME.BANG[hang][i] != GAME.NGUOI_CHOI) return RUNNING;
    }
    return GAME.NGUOI_CHOI;
}

int checkWinCheo1(TIC_TAC_TOE &GAME){
    for (int i=0;i<N;i++){
        if (GAME.BANG[i][i] != GAME.NGUOI_CHOI) return RUNNING;
    }
    return GAME.NGUOI_CHOI;
}

int checkWinCheo2(TIC_TAC_TOE &GAME){
    for (int i=0;i<N;i++){
        if (GAME.BANG[i][N-i-1]!= GAME.NGUOI_CHOI) return RUNNING;

    }
    return GAME.NGUOI_CHOI;
}

int CheckWin(TIC_TAC_TOE &GAME){
    for (int i=0;i<N;i++){
        if (checkWinHang(GAME,i)== GAME.NGUOI_CHOI) return GAME.NGUOI_CHOI;
        else if (checkWinCot(GAME,i) == GAME.NGUOI_CHOI) return GAME.NGUOI_CHOI;
    }
    if (checkWinCheo1(GAME)==GAME.NGUOI_CHOI or checkWinCheo2(GAME)== GAME.NGUOI_CHOI) return GAME.NGUOI_CHOI;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (GAME.BANG[i][j]==0) return RUNNING;
        }
    }
    return DRAW;
}

void PLAY(int hang, int cot, TIC_TAC_TOE &GAME){
    if (GAME.TINH_TRANG == RUNNING) {
        if (GAME.NGUOI_CHOI == PLAYER_1) GAME.NGUOI_CHOI = PLAYER_2;
        else GAME.NGUOI_CHOI = PLAYER_1;
        if (GAME.BANG[hang][cot]== 0){
            GAME.BANG[hang][cot] = GAME.NGUOI_CHOI;
            GAME.TINH_TRANG = CheckWin(GAME);
        }
    }
    else reset(GAME);
}

void RENDER_BANG(SDL_Renderer * render, const SDL_Color * Color){
    SDL_SetRenderDrawColor(render, Color->r, Color->g, Color->b, 255 );
    for (int i=1;i<N;i++){
        SDL_RenderDrawLine(render, i * CR1, 0 , i * CR1, CD);
        SDL_RenderDrawLine(render, 0, i * CD1, CR , i*CD1);
    }
}
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
void RENDER_WIN_DRAW (SDL_Renderer *render,TIC_TAC_TOE & GAME,const SDL_Color *Color){
    SDL_Color TEMP= *Color;
    for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (GAME.BANG[i][j]==PLAYER_1) RENDER_PLAYER1(render,i,j,&TEMP);
                if (GAME.BANG[i][j]==PLAYER_2) RENDER_PLAYER2(render,i,j,&TEMP);
            }
    }
}
void RENDER_GAME (SDL_Renderer * render,TIC_TAC_TOE &GAME){
    RENDER_BANG(render,&WhiteColor);
    if (GAME.TINH_TRANG == DRAW) RENDER_WIN_DRAW(render,GAME,&Draw);
    else if (GAME.TINH_TRANG==PLAYER_1) RENDER_WIN_DRAW(render,GAME,&PLAYER1);
        else RENDER_WIN_DRAW(render,GAME,&PLAYER2);
}

void RENDER_HUMAN(SDL_Renderer *render, TIC_TAC_TOE &GAME){
    if (GAME.TINH_TRANG == RUNNING) {
        RENDER_BANG(render,&WhiteColor);
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (GAME.BANG[i][j]==PLAYER_1) RENDER_PLAYER1(render,i,j,&PLAYER1);
                if (GAME.BANG[i][j]==PLAYER_2) RENDER_PLAYER2(render,i,j,&PLAYER2);
            }
        }
    }
    else RENDER_GAME(render,GAME);
}


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

