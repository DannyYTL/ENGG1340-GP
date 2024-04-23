#include "gaming.h"


void in_main(int ** initial_board,int x,int y) {
        string temp;
        char mode;
        int input_x=999, input_y=999;
        bool die = 0, valid=0;
    
        cout<<"enter the mode and the coordinates!" << endl;
        cout << "modes: 'e': excavate, 'f': flag, 'q': quit (e.g.: e x-axis y-axis)\n";
        cin.ignore();
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
                save_to_file("Record.txt",initial_board,x,y);
                cout << "Bye\n";
                break;
            }
            
            die = processing(initial_board, x, y, mode, input_y, input_x);
            if(die !=1 && win(initial_board,x,y)==1){
                display(initial_board, x, y, die, win);
                cout << "you win\n";
                break;
            }
            display(initial_board, x, y, die, 0);
            if(die){                                                                                                                                                                                       
                   cout <<  "█     █       █    █         ██████            █      █        █     █                                      █      █    █     █  █                   █            \n"        
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
                            "    ██      █               ██████                     █████                     █      █████              █      █    ██                  █     ██████           \n";                   
                                                                                                                                                                                                        
                cout << "cai jiu duo lian\n";
                break;
            }
            cout<<"enter the mode and the coordinates! modes: 'e': excavate, 'f': flag, 'q': quit (e.g.: e x-axis y-axis)\n";
        }
        //cout << "end testing"<<endl;
}