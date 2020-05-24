#ifndef PAINT_H_
#define PAINT_H_
#include <SDL.h>
#include "GAME.h"

const SDL_Color BlueColor = {0,0,255};
const SDL_Color OrageColor = {255,165,0};
const SDL_Color PurpleColor = {128,0,128};
const SDL_Color LucLam = {0,255,255};
const SDL_Color YellowColor = {255,255,0};
const SDL_Color RedColor = {255,0,0};
const SDL_Color BlackColor = {0,0,0};
const SDL_Color GreenColor = {0,128,0};
const SDL_Color WhiteColor = {255,255,255};

const SDL_Color PLAYER1 = {0,128,0};
const SDL_Color PLAYER2 = {128,0,128};
const SDL_Color AI_Color = {255,0,0};
const SDL_Color LOSS ={80,80,80};
const SDL_Color WIN = {200,0,0};
const SDL_Color Draw = {255,165,0};

void RENDER_PLAYER1(SDL_Renderer * render, int hang , int cot, const SDL_Color *Color);
void RENDER_PLAYER2(SDL_Renderer * render, int hang , int cot, const SDL_Color *Color);
void RENDER_AI(SDL_Renderer * render, int hang , int cot, const SDL_Color *Color);
void RENDER_GAME(SDL_Renderer *render, TIC_TAC_TOE &GAME);
void RENDER_DRAW (SDL_Renderer *render,TIC_TAC_TOE & GAME,const SDL_Color *Color);
void RENDER_WIN(SDL_Renderer * render,TIC_TAC_TOE &GAME);
void RENDER_HANG(SDL_Renderer *render,TIC_TAC_TOE &GAME,int hang);
void RENDER_COT(SDL_Renderer *render,TIC_TAC_TOE &GAME,int cot);
void RENDER_CHEO1(SDL_Renderer *render, TIC_TAC_TOE &GAME);
void RENDER_CHEO2(SDL_Renderer *render, TIC_TAC_TOE &GAME);


#endif // PAINT_H_
