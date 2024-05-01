# ENGG1340_GP
Minesweeper game
-------------------
Group Members:

Chen Yiren  - 3036264535

Yao Tianle  - 3036253691

Yu Junye    - 3036269016

Lau Yuyan   - 3036227214

-------------
List of features:
1. The position of the mines on the board is randomly set, it varies in every new game.
2. The board is created using dynamic array, and every movement the players made is recorded on the board.
3. Players can load the previous playing record(board) when executing the code, and the game data will be automatically saved when the player quits.
4. The codes are separated into 7 different files to ensure the "main.cpp" looks tidy and simple.
5. The functions and variables were named properly to allow easy reading and comprehension.

-------------
To play our game, all you need to do is downloading the files from GitHub and then type "make main" under the game directory in your Linux environment.

After "make main", the main executable file will be generated. Execute the file by "./main", then the game will start running

In our game, you can choose from two modes: "N" - new game, "L" - loading the last unfinished game
* Note that if it is the first time you play this game, inputting L may cause an error in the game as there is no previous record :(

If you choose "N" new game:
            the program will ask you for the board's width and height, both values will only be valid if they are between 3 and 300 inclusive
            then it will ask you for your wanted difficulty (1-10, 1 being the easiest and 10 being the hardest), which determines the number of mines in the game board
            then the game board will be shown on your terminal
If you choose "L" loading the last game:
            the game board will be shown on the terminal as it appears when you quit the game last time

The actions the player can choose: "e" - excavate, "f" - flag, "q" -quit the game
* Note that "e" and "f" require the player to also add the coordinates of the element in board they want to manipulate (e.g. "e 0 0")
* Use 'e' to excavate an element in the game board; use 'f' to flag an element that you consider as a mine
* After excavated an element, if a number is shown, it represents the number of mines in the elements that surround it

Winning condition: if all non-mine elements of the game board have been executed and all mines are flagged
Losing condition: if one mine is being evacuated, you lose!

Here is the youtube line for the video we make:             https://youtu.be/6PWCfxH__Ys

Hope you enjoy our game, have fun !!!
