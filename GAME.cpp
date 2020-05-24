#include <bits/stdc++.h>
#include "GAME.h"

using namespace std;

void PLAY_HUMAN_GAME(int hang, int cot, TIC_TAC_TOE &GAME){
    if (GAME.BANG[hang][cot] == 0 ) {
        if (GAME.Player == PLAYER_1) GAME.Player = PLAYER_2;
        else GAME.Player = PLAYER_1;
        GAME.BANG[hang][cot]= GAME.Player;
        GAME.State = CheckWin(GAME);
    }
}

int CheckWin(TIC_TAC_TOE &GAME){
    for (int i=0;i<N;i++){
        if (checkWinHang(GAME,i)== GAME.Player) return GAME.Player;
        else if (checkWinCot(GAME,i) == GAME.Player) return GAME.Player;
    }
    if (checkWinCheo1(GAME)== GAME.Player or checkWinCheo2(GAME)== GAME.Player) return GAME.Player;
    for (int i = 0;i<N;i++){
        for (int j = 0;j<N;j++){
            if (GAME.BANG[i][j] == 0) return RUNNING;
        }
    }
    return DRAW;
}

int checkWinCot(TIC_TAC_TOE &GAME, int cot){
    for (int i=0;i<N;i++){
        if (GAME.BANG[i][cot] != GAME.Player) return RUNNING;
    }
    return GAME.Player;
}

int checkWinHang(TIC_TAC_TOE &GAME, int hang){
    for (int i=0;i<N;i++){
        if (GAME.BANG[hang][i] != GAME.Player) return RUNNING;
    }
    return GAME.Player;
}

int checkWinCheo1(TIC_TAC_TOE &GAME){
    for (int i=0;i<N;i++){
        if (GAME.BANG[i][i] != GAME.Player) return RUNNING;
    }
    return GAME.Player;
}

int checkWinCheo2(TIC_TAC_TOE &GAME){
    for (int i=0;i<N;i++){
        if (GAME.BANG[i][N-i-1]!= GAME.Player) return RUNNING;
    }
    return GAME.Player;
}







