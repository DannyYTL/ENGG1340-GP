#include "gaming.h"
//Determining whether the game is won or not.
//input parameters are: pointer to a 2D-array, int x and y representing the size of board.
//return boolean type true or false.
bool win(int **board, int x, int y) {
    for (int i=0; i<x; ++i){
        for (int j=0; j<y; ++j){
            if (board[i][j]==9)
                return 0; // not won if there is remaining mine.
        }
    }
    return 1; // otherwise won.
}
