#include "gaming.h"

// function for saving the current game board to an external file when user choose to quit ('q') the game before game ends
// input parameters: the filename of external file to be used, string type; a pointer to a 2D array of int pointers, stores the content of game board (dynamic memory management)
//                  int x is the height of game board, int y is the width of game board
// no return type, this function just stores the game board
void save_to_file(string filename,int ** board,int x,int y) 
    ofstream fout;                                // create a file output stream
    fout.open(filename);
    if (fout.fail()) {                            // in case error in opening external file occurs, prompt the player and jump to fout.close()
        cout << "Error in file opening" << endl;
    }
    else {                                        // otherwises save the current game board
        for (int i=0;i<x;i++) {
            for (int j=0;j<y;j++) {
                if (j != y-1) {
                    fout << board[i][j] << " ";
                }
                else {
                    if (i != x-1) {
                        fout << board[i][j] << endl;
                    }
                    else {
                        fout << board[i][j];
                    }
                }
            }
        }
    }
    fout.close();                                // close the file output stream
    return;
}


// function for reading the game board of last game from an external file if user choose mode Load ("L")
// input parameters: file name of the external file, string type; int x pass and int y both passed by reference, counts the height and width of board respectively
//                                                                the value of x and y are directly changed in the L branch of main function
// return a pointer to the dynamic array of int pointers, this is the pointer to container of game board
int ** read_file(string filename,int &x,int &y) {
        ifstream fin;                            // create a file input stream
        string thisline,thisnum;
        x=-1;
        y=-1;
        int count=0;
        int ** board = new int*[300];           // create a pointer to dynamic array which stores game board later
        for (int i=0; i<300; ++i){
            board[i] = new int[300];
        }
        fin.open(filename);
        if (fin.fail()) {                       // if file reading from external file fails, prompt the player and jump to fin.close()
            cout << "Error in file opening." << endl;
        }
        else {                                  // otherwises use while loop to read the content of game board to dynamic array created above
            while (getline(fin,thisline)) {
                //cout << count << "  " << thisline<< endl;
                //count += 1;
                istringstream iss(thisline);
                x += 1;
                y = -1;
                while (iss >> thisnum) {
                    y += 1;
                    board[x][y] = stoi(thisnum);
                }
            }
            fin.close();                        // close the file input stream
        }
        return board;                           // return the pointer to game board to main function
}
