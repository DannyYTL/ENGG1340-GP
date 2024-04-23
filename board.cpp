#include "gaming.h"

//generate a hidden board contain mine and numbers.
//input parameters are: pointer to the 2D array, size of the board (int x and y), number of mine in the board (int num_of_mine)
//void function, no return type
void initialise_board(int **initial_board, int x, int y, int num_of_mine) {

        for ( int i=0; i<x; ++i){  // fill the board with -1.
        for ( int j=0; j<y; ++j){
            initial_board[i][j] = -1; 
        }
    }

    int **random_pos = new int*[num_of_mine];        // generate a dynamic 2D array to put random coordinates for mines
    for ( int i=0; i<num_of_mine; ++i){
        random_pos[i] = new int[2];
    }
    int min_xnum = 0, max_xnum = x-1, min_ynum = 0, max_ynum = y-1; //define range
    random_device seed;
    mt19937 engine(seed());
    for (int i=0; i<num_of_mine; ++i){        // select random positions in a column, number of position = number of mine
        uniform_int_distribution<> distrib(min_xnum, max_xnum); // set range,evenly distributed
        int random = distrib(engine);        //generate random number
        random_pos[i][0]=random;                // fill into 2D array
    }
    for (int i=0; i<num_of_mine; ++i){        // select random positions in a row, number of position = number of mine
        uniform_int_distribution<> distrib(min_ynum, max_ynum); // set range,evenly distributed
        int random = distrib(engine);        //generate random number
        random_pos[i][1]=random;                // fill into 2D array
    }
    for (int i=0; i<num_of_mine; ++i){        // fill the random positions with mines
        initial_board[random_pos[i][0]][random_pos[i][1]] = 9; // mine defined as 9
    }

      //generate numbers represent the surrounding mines.
    for ( int i=0; i<x; ++i){
        for ( int j=0; j<y; ++j){
            if(initial_board[i][j]==-1){        // search every space without mine and calculate the surrouding mine number
                int surround_mine = 0;        
                if (i-1>=0 && initial_board[i-1][j]==9)
                    surround_mine ++ ;
                if (i-1>=0 && j-1>=0 && initial_board[i-1][j-1]==9)
                    surround_mine ++ ;
                if (i-1>=0 && j+1<=y-1 && initial_board[i-1][j+1]==9)
                    surround_mine ++ ;
                if (j-1>=0 && initial_board[i][j-1]==9)
                    surround_mine ++ ;
                if (j+1<=y-1 && initial_board[i][j+1]==9)
                    surround_mine ++ ;
                if (i+1<=x-1 && initial_board[i+1][j]==9)
                    surround_mine ++ ;
                if (i+1<=x-1 && j-1>=0 && initial_board[i+1][j-1]==9)
                    surround_mine ++ ;
                if (i+1<=x-1 && j+1<=y-1 && initial_board[i+1][j+1]==9)
                    surround_mine ++ ;
                initial_board[i][j] = surround_mine;        // put the calculated number into the position
            }
        }
    }
}
