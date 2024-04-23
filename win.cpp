#include "gaming.h"


bool win(int **board, int x, int y) {
    for (int i=0; i<x; ++i){
        for (int j=0; j<y; ++j){
            if (board[i][j]==9)
                return 0;
        }
    }
    return 1;
}