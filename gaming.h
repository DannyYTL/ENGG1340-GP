#ifndef _GAMING_H
#define _GAMING_H
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <random>
#include <fstream>
using namespace std;

void initialise_board(int **initial_board, int x, int y, int num_of_mine);
void display(int ** &board, int x, int y, bool die, bool win);
bool processing(int ** &board, int &x_max, int &y_max, string &mode, int x, int y);
bool win(int **board, int x, int y);
void save_to_file(string filename,int ** board,int x,int y);
int ** read_file(string filename,int &x,int &y);
void in_main(int ** initial_board,int x,int y);

#endif
