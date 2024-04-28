#include "gaming.h"                             // necessary header file

int main() {                                    // the main function of this game
    string options;
    string xyl;
    int x=1, y=1, level=0;  
    cout << "what you want to do?\n New Game: N\n Load Game: L\n";
    getline(cin,options);                                                // user input the mode, either 'N' or 'L'
    while (options != "N") {                           // otherwises keep prompting the user for valid input mode
        if (options == "L"){
            ifstream fin;
            fin.open("Record.txt");
            if (fin.fail()) {                       // if file reading from external file fails, prompt the player and jump to fin.close()
                cout << "No record";
            }else break;

        }
        else cout << "Invalid option";
        cout << ", please choose again ( N - new game; L - continue from last game ): " << endl;
        getline(cin,options);
    }    
    if (options == "N") {                                                // new game branch
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
        initialise_board(initial_board, x, y, num_of_mine);   // initialise the board
    //                  //
        display(initial_board, x, y, 0, 0);
        cin.ignore();
        in_main(initial_board,x,y);                           // call in_main to start the game
    }
    else if (options == "L") {                                // Load last game branch
        int ** initial_board;
        int x,y;
        initial_board = read_file("Record.txt",x,y);          // read the last game board from "Record.txt"
        x+=1;
        y+=1;
        display(initial_board, x, y, 0, 0);
        in_main(initial_board,x,y);                           // call in_main to start the game
    }
    return 0;
}
