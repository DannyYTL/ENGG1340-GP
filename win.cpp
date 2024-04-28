#include "gaming.h"
//Determining whether the game is won or not.
//input parameters are: pointer to a 2D-array, int x and y representing the size of board.
//return boolean type true or false.
bool win(int **board, int x, int y) {
    for (int i=0, j, value; i<x; ++i){    // loop to search in board.
        for (j=0; j<y; ++j){
            value = board[i][j];
            if (value>=1 && value<=9)
                return 0; // not won if there is remaining mine.
        }
    }
    return 1; // otherwise won.
}
