#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <sstream>

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
    for (int i=0; i<x; ++i){//print test(to be delete)
        for (int j=0; j<y; ++j){
            cout<<setw(3)<<initial_board[i][j];              
        }
        cout<<endl;
        }//print test(to be delete)

    return 0;
}
///*
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
                     if (win!=1)   cout<<"  ?";        // 平地（没挖过的）
                     else cout<<"  "<<board[i][j];
                }
            }
            cout<<endl;
        }//print test(to be delete)
}
//*/

bool processing(int ** &board, int &x_max, int &y_max, char &mode, int x, int y){  // x: hor, y: ver,
    // mode: 'e': exacavate; 'f': flag; 'q': quit
    int value;
    if(x>=0 && x<x_max && y>=0 && y<y_max){
        value = board[y][x];
        //cout<<"value: "<<value<<endl;  // test///////////
        if(value >= 10){  // wa guo de
            return 0;
        }
        if(mode == 'e'){
            if(value == 9){
                cout<<"Booooooooom!\n";
                board[y][x] = 99; // 葬身之地
                return 1;
            }
            if (value >= 0){    // is a number (less than 10)
                board[y][x]+=10;  // change state
                if (value == 0){
                    for(int i=-1, j; i<=1; i++){
                        for (j=-1; j<=1; j++) if(i!=0 || j!=0) processing(board, x_max, y_max, mode, x+i, y+j); 
                    }
                }
                return 0;
            }// value < 0 
            return 0;
        }if(mode == 'f'){
            if (value>=0) board[y][x] -= 10;  // 插旗子
            else board[y][x] += 10; // 拔旗子
            return 0;
        }
        
    }
    return 0;
}

bool win(int **board, int x, int y) {
    for (int i=0; i<x; ++i){
        for (int j=0; j<y; ++j){
            if (board[i][j]==9)
                return 0;
        }
    }
    return 1;
}


int main() {
// customer input (separate function??) //
    string xyl;
    int x=1, y=1, level=0;    
    while( y<3 || y>300 ){
        cout << "The width of the board (3-300): ";
        cin>>xyl;
        istringstream iss(xyl);
        iss >> y;
    }
    while( x<3 || x>300 ){
        cout << "The height of the board (3-300): ";
        cin>>xyl;
        istringstream iss(xyl);
        iss >> x;
    }
    while ( level<1 || level>10 ){
        cout << "Choose a level (1-10):";
        cin>>xyl;
        istringstream iss(xyl);
        iss >> level;
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

    
    display(initial_board, x, y, 0, 0);

    //test input
    string temp;
    char mode;
    int input_x=999, input_y=999;
    bool die = 0, valid=0;
    //cout<<"max_x: "<<y<<", max_y: "<<x<<endl;
    cout<<"enter the mode and the coordinates! modes: 'e': excavate, 'f': flag, 'q': quit (e.g.: e 12 13)\n";
    while(getline(cin,temp)){
        istringstream iss(temp);
        iss >> mode >> input_x >> input_y;
        if (mode != 'q' && mode != 'e' && mode != 'f'){
            cout<<"Please enter a valid mode"<<endl;
            input_x=999;
            input_y=999;
            continue;
        }
        else if (mode != 'q' && (input_x < 0 || input_x >= y || input_y < 0 || input_y >= x)){
            cout<<"Please enter a valid coordinates"<<endl;
            input_x=999;
            input_y=999;
            continue;
        }
        if(mode=='q'){
            cout << "Bye\n";
            break;
        }
        
        die = processing(initial_board, y, x, mode, input_x, input_y);
        if(die !=1 && win(initial_board,x,y)==1){
            display(initial_board, x, y, die, win);
            cout << "you win\n";
            break;
        }
        display(initial_board, x, y, die, 0);
        if(die){
            cout << "cai jiu duo lian\n";
            break;
        }
        cout<<"enter the mode and the coordinates! modes: 'e': excavate, 'f': flag, 'q': quit (e.g.: e 12 13)\n";
    }
    cout << "end testing"<<endl;
   

    return 0;
}
