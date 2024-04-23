#include "gaming.h"


void display(int ** &board, int x, int y, bool die, bool win){
    int value, i, j;
    cout << "\n    |"; 
    for (i=0; i<y; i++) cout<<setw(3)<<i;   cout<<"\n  ---"; 
    for (i=0; i<y; i++) cout<<"---";        cout<<endl;
    for (i=0; i<x; ++i){//print test(to be delete)e
            cout<<setw(3)<<i<<" |";
            for (j=0; j<y; ++j){ value = board[i][j];
                if (value == 99) cout << " 💀"; // 葬身之地
                else if (value > 10) {  // 有数字的坑
                /*1：蓝色，"\033[1;34m" 2：绿色，"\033[1;32m" 3：红色，"\033[1;31m" 4：紫色，"\033[1;35m" 5：黄色，"\033[1;33m" 6：青色，"\033[0;36m" 7：黑色，"\033[0;30m" 8：灰色，"\033[1;33m"
                */
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
                else if(value == 10) cout << "  _"; // 没数字的坑
                else if(die && value == 9) cout << " 💣";
                else if(value < 0){
                    if (die && value!= -1) cout<< ' '<< u8"\U0001F3F4";  //死了之后并且旗子插错了，黑旗
                    else cout << " 🚩";  // 插旗子
                }
                
                else {
                     if (win!=1)   cout<<"  ∎";        // 平地（没挖过的）
                     else cout<<"  "<<board[i][j];
                }
            }
            cout<<endl;
        }//print test(to be delete)
}