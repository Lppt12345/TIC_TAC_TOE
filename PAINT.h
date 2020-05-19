#ifndef PAINT_H_
#define PAINT_H_
#include <SDL.h>
#include "GAME.h"

const SDL_Color WhiteColor = {255,255,255};
const SDL_Color PLAYER1 = {0,128,0};
const SDL_Color PLAYER2 = {128,0,128};
const SDL_Color Draw = {255,165,0};

void RENDER_PLAYER1(SDL_Renderer * render, int hang , int cot, const SDL_Color *Color);
void RENDER_PLAYER2(SDL_Renderer * render, int hang , int cot, const SDL_Color *Color);
void RENDER_HUMAN(SDL_Renderer *render, TIC_TAC_TOE &GAME);
void RENDER_GAME (SDL_Renderer * render,TIC_TAC_TOE &GAME);
void RENDER_WIN_DRAW (SDL_Renderer *render,TIC_TAC_TOE & GAME,const SDL_Color *Color);


#endif // PAINT_H_
