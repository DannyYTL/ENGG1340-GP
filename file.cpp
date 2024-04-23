#include "gaming.h"


void save_to_file(string filename,int ** board,int x,int y) {
    ofstream fout;
    fout.open(filename);
    if (fout.fail()) {
        cout << "Error in file opening" << endl;
    }
    else {
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
    fout.close();
    return;
}

int ** read_file(string filename,int &x,int &y) {
        ifstream fin;
        string thisline,thisnum;
        x=-1;
        y=-1;
        int count=0;
        int ** board = new int*[300];
        for (int i=0; i<300; ++i){
            board[i] = new int[300];
        }
        fin.open(filename);
        if (fin.fail()) {
            cout << "Error in file opening." << endl;
        }
        else {
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
            fin.close();
        }
        return board;
}