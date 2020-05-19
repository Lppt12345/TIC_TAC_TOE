#include <bits/stdc++.h>
#include "GAME.h"
using namespace std;

void PLAY_HUMAN(int hang, int cot, TIC_TAC_TOE &GAME){
    if (GAME.TINH_TRANG == RUNNING){
        if (GAME.BANG[hang][cot] != PLAYER_1 and GAME.BANG[hang][cot] !=PLAYER_2) {
            if (GAME.NGUOI_CHOI == PLAYER_1) GAME.NGUOI_CHOI = PLAYER_2;
            else GAME.NGUOI_CHOI = PLAYER_1;
            GAME.BANG[hang][cot]=GAME.NGUOI_CHOI;
            GAME.TINH_TRANG = CheckWin(GAME);
        }
    }
    else {
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                GAME.BANG[i][j]=0;
            }
        }
        GAME.NGUOI_CHOI = PLAYER_1;
        GAME.TINH_TRANG = RUNNING ;
    }
};

int CheckWin(TIC_TAC_TOE &GAME){
    for (int i=0;i<N;i++){
        if (checkWinHang(GAME,i)== GAME.NGUOI_CHOI) return GAME.NGUOI_CHOI;
        else if (checkWinCot(GAME,i) == GAME.NGUOI_CHOI) return GAME.NGUOI_CHOI;
    }
    if (checkWinCheo1(GAME)== GAME.NGUOI_CHOI or checkWinCheo2(GAME)== GAME.NGUOI_CHOI) return GAME.NGUOI_CHOI;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (GAME.BANG[i][j]==0) return RUNNING;
        }
    }
    return DRAW;
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







