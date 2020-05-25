#include <bits/stdc++.h>
#include "Ai.h"
#include "GAME.h"
using namespace std;

void AI_TURN (TIC_TAC_TOE &GAME){
    GAME.Player = AI_NORMAL;
    srand (time (NULL));
    vector <AI> AIturn;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (GAME.BANG[i][j] ==0 ){
                AI temp(i,j);
                AIturn.push_back(temp);
            }
        }
    }
    int ran = rand () % (AIturn.size()-1) +1;
    GAME.BANG[AIturn[ran].hang][AIturn[ran].cot] = AI_NORMAL;
    GAME.State = CheckWin(GAME);
}



