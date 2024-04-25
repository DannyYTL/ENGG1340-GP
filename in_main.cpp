#include "gaming.h"

// function created by extracting the repetitive lines in main.cpp's two branch - N (new game) and L (load game)
// handles prompting user to input the action and corresponding coordinates, and subsequent processing of game
// input parameters are: pointer to the 2D array of int pointers of game board (a dynamic 2D array); the height of board x and width of board y, both of type int
// no return type, only handles the execution of game
void in_main(int ** initial_board,int x,int y) {
        string temp;
        char mode;
        int input_x=999, input_y=999;
        bool die = 0, valid=0;
    
        cout<<"enter the mode and the coordinates!" << endl;
        cout << "modes: 'e': excavate, 'f': flag, 'q': quit (e.g.: e x-axis y-axis)\n";
        cin.ignore();                                        // avoid the situation in which next getline receives 'nothing' as input
        while(getline(cin,temp)){                            // store whole line of user input to temp
            istringstream iss(temp);                         // create an input string stream using string line in temp
            iss >> mode >> input_x >> input_y;
            if (mode != 'q' && mode != 'e' && mode != 'f'){                // only accepts mode in either of 'q' - quit, 'e' - evacuate, 'f' - flag
                cout<<"Please enter a valid mode"<<endl;
                input_x=999;
                input_y=999;
                continue;
            }
            else if (mode != 'q' && (input_x < 0 || input_x >= y || input_y < 0 || input_y >= x)){             // if user does not quit the game and use mode 'e' or 'f'
                cout<<"Please enter a valid coordinates"<<endl;                                                // valid coordinates within the board size are required
                input_x=999;
                input_y=999;
                continue;
            }
            if(mode=='q'){                                                 // if user quits the game, call save_to_file, current game board is stored in file "Record.txt"
                save_to_file("Record.txt",initial_board,x,y);
                cout << "Bye\n";
                break;
            }
            
            die = processing(initial_board, x, y, mode, input_y, input_x);        // detects whether the game is over 
            if(die !=1 && win(initial_board,x,y)==1){                             // if condition checks whether the player wins
                display(initial_board, x, y, die, win);
                cout << "you win\n";
                break;
            }
            
            if(die){  cout<<"\033[1;31m\n"                                                    // if the user exvacuated a mine, player is considered dead, game over                                                                                                                                                                 
                            "█     █       █    █         ██████            █      █        █     █                                      █      █    █     █  █                   █            \n"        
                            "████████     ███████      █████████████        █████████      ████████            ████████████████         █████████    ███████████████     ████████████████      \n"                      
                            " ████         ███      ████        █████        ████            ███               ████       ███████         ████        ███        ██       ████      ███████    \n"                     
                            "  ████       ██      ████            ████       ████            ███                ███           ████      █ ████        ███         █       ███           ████   \n"                  
                            "   ████     ██      ████              ████      ████            ███                ███            ████       ████        ███                 ███            ████  \n"                 
                            "    ███    ███      ███               ████      ████            ██                 ███             ████      ████        ███       █         ███             ████ \n"                  
                            "     ███   ██      ████                ████     ████            ██                 ███             ████      ████        ███      ██         ███             ████ \n"                  
                            "     ████ ██       ████                ████     ████            ██                 ███              ███      ████        ███████████         ███              ████\n"                  
                            "      █████        ████                ████     ████            ██                 ███             ████      ████        ███████████         ███              ████\n"                  
                            "       ███         ████                ████     ████            ██                 ███             ████      ████        ███      ██         ███             ████ \n"                 
                            "       ███          ████               ███       ███            ██                 ███             ████      ████        ███                 ███             ████ \n"                  
                            "       ███          █████             ████       ███            ██                 ███            ████       ████        ███           █     ███            ████  \n"                  
                            "       ███           █████           ████        ████          ██                  ███           ████        ████        ███          ██     ███           ████   \n"                  
                            "       ████            █████       ████           █████      ████                  ████       ██████         ████        ████        ███     ████        █████    \n"                  
                            "    ██████████           ████████████              ████████████  █              █████████████████         █████████   █████████████████   █████████████████       \n"                 
                            "    ██      █               ██████                     █████                     █      █████              █      █    ██                  █     ██████           \n"<<"\033[0;30m"     
                                                                                                                                                                                                        
                        << "cai jiu duo lian\n";                              // friendly encouragement from the programmers :)
                display(initial_board, x, y, die, 0);
                break;
            }display(initial_board, x, y, die, 0);
            // the current action is ended, ask for user's next action
            cout<<"enter the mode and the coordinates! modes: 'e': excavate, 'f': flag, 'q': quit (e.g.: e x-axis y-axis)\n";       
        }
}
