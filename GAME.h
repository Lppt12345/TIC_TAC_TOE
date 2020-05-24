#ifndef GAME_H_
#define GAME_H_

int const N = 3;   // ma tran
int const DD = 3; // so lan ve

float const CD = 500;                       // chieu dai chuong trinh
float const CR = CD;
float const CD1 = CD/N;
float const CR1= CR/N;

int const PLAYER_1 = 1;
int const PLAYER_2 = 2;
int const AI_NORMAL = 4;
int const DRAW = 0;
int const RUNNING = 3;

struct TIC_TAC_TOE{
    float BANG [N][N];
    int Player;
    int State  ;
    void BEGIN( int Begin_player ){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
            BANG[i][j]=0;
            }
        }
        Player = Begin_player;
        State = RUNNING ;
    }
};
void PLAY_HUMAN_GAME(int hang, int cot, TIC_TAC_TOE &GAME);
void PLAY_AI(int hang, int cot, TIC_TAC_TOE &GAME);
int CheckWin(TIC_TAC_TOE &GAME);
int checkWinCot(TIC_TAC_TOE &GAME, int cot);
int checkWinHang(TIC_TAC_TOE &GAME, int hang);
int checkWinCheo1(TIC_TAC_TOE &GAME);
int checkWinCheo2(TIC_TAC_TOE &GAME);

#endif // GAME_H_
