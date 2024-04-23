#include "gaming.h"

//generate a hidden board contain mine and numbers.
void initialise_board(int **initial_board, int x, int y, int num_of_mine) {

        for ( int i=0; i<x; ++i){
        for ( int j=0; j<y; ++j){
            initial_board[i][j] = -1; // empty space defined as -1.
        }
    }

    int **random_pos = new int*[num_of_mine];
    for ( int i=0; i<num_of_mine; ++i){
        random_pos[i] = new int[2];
    }
    int min_xnum = 0, max_xnum = x-1, min_ynum = 0, max_ynum = y-1; //define range
    random_device seed;
    mt19937 engine(seed());
    for (int i=0; i<num_of_mine; ++i){
        uniform_int_distribution<> distrib(min_xnum, max_xnum); // set range,evenly distributed
        int random = distrib(engine);
        random_pos[i][0]=random;
    }
    for (int i=0; i<num_of_mine; ++i){
        uniform_int_distribution<> distrib(min_ynum, max_ynum); // set range,evenly distributed
        int random = distrib(engine);
        random_pos[i][1]=random;
    }
    for (int i=0; i<num_of_mine; ++i){
        initial_board[random_pos[i][0]][random_pos[i][1]] = 9; //地雷定义为9
        //cout<<'\n';
    }

    //generate 数字
    for ( int i=0; i<x; ++i){
        for ( int j=0; j<y; ++j){
            if(initial_board[i][j]==-1){
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
                initial_board[i][j] = surround_mine;
            }
        }
    }
}
