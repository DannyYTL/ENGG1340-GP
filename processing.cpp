#include "gaming.h"


bool processing(int ** &board, int &x_max, int &y_max, char &mode, int x, int y){  // x: hor, y: ver,
    // mode: 'e': exacavate; 'f': flag; 'q': quit
    int value;
    if(x>=0 && x<x_max && y>=0 && y<y_max){
        value = board[x][y];
        //cout<<"value: "<<value<<endl;  // test///////////
        if(value >= 10){  // excavated
            return 0;
        }
        if(mode == 'e'){
            if(value == 9){
                cout<<"Booooooooom!\n";
                board[x][y] = 99; // 葬身之地
                return 1;
            }
            if (value >= 0){    // is a number (less than 10)
                board[x][y]+=10;  // change state
                if (value == 0){
                    for(int i=-1, j; i<=1; i++){
                        for (j=-1; j<=1; j++) if(i!=0 || j!=0) processing(board, x_max, y_max, mode, x+i, y+j); 
                    }
                }
                return 0;
            }// value < 0 
            return 0;
        }if(mode == 'f'){
            if (value>=0) board[x][y] -= 10;  // 插旗子
            else board[x][y] += 10; // 拔旗子
            return 0;
        }
    }
    return 0;
}