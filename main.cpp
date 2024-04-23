#include "gaming.h"

int main() {
    string options;
    string xyl;
    int x=1, y=1, level=0;  
    cout << "what you want to do?\n New Game: N\n Load Game: L\n";
    getline(cin,options);
    while (options != "N" && options != "L") {
        cout << "Invalid option, please choose again ( N - new game; L - continue from last game ): " << endl;
        getline(cin,options);
    }    
    if (options == "N") {
        while( y<3 || y>300 ){
            cout << "The width of the board (3-300): ";
            cin>>xyl;        //get user input of board width
            istringstream iss(xyl);
            iss >> y;
        }
        while( x<3 || x>300 ){
            cout << "The height of the board (3-300): ";
            cin>>xyl;        //get user input of board height
            istringstream iss(xyl);
            iss >> x;
        }
        while ( level<1 || level>10 ){
            cout << "Choose a level (1-10):";
            cin>>xyl;        //get user input of the difficulty of game
            istringstream iss(xyl);
            iss >> level;
        }
        int num_of_mine = 0.1*level*x*y/5;         //set the number of mine according to the input level and size of board
        if (num_of_mine<1){                        //minimum value of mine should be 1
            num_of_mine=1;
        }
    // initialise_board //
        int **initial_board = new int*[x];        // create a dynamic 2D array to represent an empty board
        for ( int i=0; i<x; ++i){
            initial_board[i] = new int[y];
        }
        initialise_board(initial_board, x, y, num_of_mine); // initialise the board
    //                  //
        display(initial_board, x, y, 0, 0);
        in_main(initial_board,x,y);
    }
    else if (options == "L") {
        int ** initial_board;
        int x,y;
        initial_board = read_file("Record.txt",x,y);
        x+=1;
        y+=1;
        display(initial_board, x, y, 0, 0);
        in_main(initial_board,x,y);
    }
    return 0;
}
