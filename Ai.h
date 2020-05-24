#ifndef AI_H_
#define AI_H_
#include "GAME.h"

struct AI{
    int hang;
    int cot;
    AI(int _hang, int _cot){
        hang = _hang;
        cot  = _cot;
    }
};

void AI_TURN(TIC_TAC_TOE &GAME);

#endif // AI_H_
