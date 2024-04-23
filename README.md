# ENGG1340-GP
Minesweeper game

To play our game, all you need to do is downloading the files from github, and then type "make main" in your Linux environment.

After make main, the main executable file will be generated. Execute the file by "./main", then the game will start running

In our game, you can choose from two modes: "N" - new game, "L" - loading the last unfinished game
* Note that if it is the first time you play this game, inputting L may cause error in the game as there is no previous record :(

If you choose "N" new game:
            the program will ask you for the board's width and height, both value will only be valid if they are between 3 and 300 inclusive
            then it will ask you for your wanted difficulty (1-10, 1 being the easiest and 10 being the hardest), which determines the number of mines in the game board
            then the game board will be shown on your terminal
If you choose "L" loading last game:
            the game board will be shown on terminal as it appears when you quit the game last time

The actions player can choose: "e" - exvacuate, "f" - flag, "q" -quit the game
* Note that "e" and "f" require player to also add the coordinates of the element in board they want to manipulate (e.g. "e 0 0")

Winning condition: if all non-mine elements of the game board has been exvacuated and all mines are flagged
Losing condition: if one mine is being exvacuated, you lose!


Hope you enjoy our game, have fun !!!
