#ifndef GAME_H_
#define GAME_H_

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
float const RUNNING = 3;

struct TIC_TAC_TOE{
    int BANG [N][N];
    int NGUOI_CHOI;
    int TINH_TRANG;
};
void PLAY_HUMAN(int hang, int cot, TIC_TAC_TOE &GAME);
int CheckWin(TIC_TAC_TOE &GAME);
int checkWinCot(TIC_TAC_TOE &GAME, int cot);
int checkWinHang(TIC_TAC_TOE &GAME, int hang);
int checkWinCheo1(TIC_TAC_TOE &GAME);
int checkWinCheo2(TIC_TAC_TOE &GAME);

#endif // GAME_H_
