#include <iostream>
#include <iomanip>
#include <string>
#include <random>

using namespace std;

int initialise_board(int **initial_board, int x, int y, int num_of_mine) {

        for ( int i=0; i<x; ++i){
        for ( int j=0; j<y; ++j){
            initial_board[i][j] = -1;//空格定义为-1
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
        initial_board[random_pos[i][0]][random_pos[i][1]] = -9; //地雷定义为-9
        cout<<'\n';
    }

    //generate 数字
    for ( int i=0; i<x; ++i){
        for ( int j=0; j<y; ++j){
            if(initial_board[i][j]==-1){
                int surround_mine = 0;
                if (i-1>=0 && initial_board[i-1][j]==-9)
                    surround_mine ++ ;
                if (i-1>=0 && j-1>=0 && initial_board[i-1][j-1]==-9)
                    surround_mine ++ ;
                if (i-1>=0 && j+1<=y-1 && initial_board[i-1][j+1]==-9)
                    surround_mine ++ ;
                if (j-1>=0 && initial_board[i][j-1]==-9)
                    surround_mine ++ ;
                if (j+1<=y-1 && initial_board[i][j+1]==-9)
                    surround_mine ++ ;
                if (i+1<=x-1 && initial_board[i+1][j]==-9)
                    surround_mine ++ ;
                if (i+1<=x-1 && j-1>=0 && initial_board[i+1][j-1]==-9)
                    surround_mine ++ ;
                if (i+1<=x-1 && j+1<=y-1 && initial_board[i+1][j+1]==-9)
                    surround_mine ++ ;
                initial_board[i][j] = surround_mine;
            }
        }
    }


    for ( int i=0; i<x; ++i){//print test(to be delete)
        for ( int j=0; j<y; ++j){
            cout<<initial_board[i][j]<<setw(3);
        }
        cout<<endl;
    }//print test(to be delete)

    return 0;

}

int main() {
// customer input (separate function??) //
    int x=1, y=1, level=0;

    while( y<3 || y>300 ){
        cout << "The width of the board (3-300): ";
        cin >> y;
    }
    while( x<3 || x>300 ){
        cout << "The height of the board (3-300): ";
        cin >> x;
    }
    while ( level<1 || level>10 ){
        cout << "Choose a level (1-10):";
        cin >> level;
    }
    int num_of_mine = 0.1*level*x*y/5; //set 地雷 value
    if (num_of_mine<1){ //set minimum 地雷 value
        num_of_mine=1;
    }
// //
// initialise_board //
    int **initial_board = new int*[x];
    for ( int i=0; i<x; ++i){
        initial_board[i] = new int[y];
    }

    initialise_board(initial_board, x, y, num_of_mine);
//  //
    
    return 0;
}
