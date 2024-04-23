#include "gaming.h"
//Determining whether the game is won or not.

bool win(int **board, int x, int y) {
    for (int i=0; i<x; ++i){
        for (int j=0; j<y; ++j){
            if (board[i][j]==9)
                return 0; // not won if there is remaining mine.
        }
    }
    return 1; // otherwise won.
}
