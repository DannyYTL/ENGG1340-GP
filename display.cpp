#include "gaming.h"

// void function, no return type
// input parameters are the pointer to dynamic 2D array of int pointers that stores the game board; x and y which are height and width of board of type integer respectively
// boolean type die that indicates whether the player has died; boolean type win that indicates whether player wins the game
// purpose: output the game board on terminal so let user see the current game status
void display(int ** &board, int x, int y, bool die, bool win){        
    int value, i, j;
    cout << "\n    |"; 
    for (i=0; i<y; i++) cout<<setw(3)<<i;   cout<<"\n  ---"; 
    for (i=0; i<y; i++) cout<<"---";        cout<<endl;
    for (i=0; i<x; ++i){                                   
            cout<<setw(3)<<i<<" |";
            for (j=0; j<y; ++j){ value = board[i][j];
                if (value == 99) cout << " 💀";             // place where player died
                else if (value > 10) {  // 有数字的坑
                // 1：blue，"\033[1;34m" 2： green，"\033[1;32m" 3：red，"\033[1;31m" 4：purple，"\033[1;35m" 5：yellow，"\033[1;33m" 
                // 6：cyan，"\033[0;36m" 7：black，"\033[0;30m" 8：grey，"\033[1;33m"
                    if(value == 11) cout << "\033[1;34m";
                    else if(value == 12) cout << "\033[1;32m";
                    else if(value == 13) cout << "\033[1;31m";
                    else if(value == 14) cout << "\033[1;35m";
                    else if(value == 15) cout << "\033[1;33m";
                    else if(value == 16) cout << "\033[0;36m";
                    else if(value == 17) cout << "\033[0;30m";
                    else if(value == 18) cout << "\033[1;33m";
                    cout<<setw(3)<<value-10 <<"\033[0m";
                    }
                else if(value == 10) cout << "  _";             // elements without number
                else if(die && value == 9) cout << " 💣";
                else if(value < 0){
                    if (die && value!= -1) cout<< ' '<< u8"\U0001F3F4";          // the player died adn wrong flag is placed, black flag
                    else cout << " 🚩";                         // put a flag  
                }
                
                else {
                     if (win!=1)   cout<<"  ∎";                 // elements that have not been exvacuated 
                     else cout<<"  "<<board[i][j];
                }
            }
            cout<<endl;
        }
}
