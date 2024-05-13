# Reversi Game Manual

## Task
The program implements the game of Reversi. The game is designed for two players and is played on an 8x8 board. The program checks the possibility of each move made by the users.

## Options
1. Two-player game:
   - Players take turns entering their nicknames, for which text files are created, storing the game result, the number of points, and the time of data saving to the file on a single line. Each line represents one game. Players take turns making moves (if each move is made correctly; otherwise, the user has the right to reload the move). The game continues until all fields are filled, or if a player has no possible moves (entering -1 in any of the coordinates indicates that the player does not see a valid piece position on the board), the game ends, and the points are counted.
   
2. Single-player game:
   - Player plays against the computer, whose moves are randomly selected each time. If the computer fails to select a correct position on the board for 150 moves, parameters -1, -1 are set, indicating that the player does not see a move and loses their turn. The game continues until all fields are filled, or if the player has no possible moves, the game ends, and the points are counted.
   
3. End game:
   - The program ends its execution.

Only an integer from 1 to 3 can be selected. If a letter or another number is entered, the program asks the user to correct the error.

## Unusual Behaviors
Sometimes incorrectly capturing positions diagonally near the edges of the board (e.g., positions like (0,7)). Occasionally, capturing opponent positions may occur when it should not.

## Inconsistencies with the Task Description
Inconsistencies:
1. The program itself does not detect whether a move is possible. If a player does not see a possible move, they enter -1 in one of the coordinates when entering data. In this way, the move is passed to the opposing player. If player X enters -1 in one of the coordinates, and immediately after, player Y also enters -1, the game ends, points are counted, and based on them, a verdict is issued on which player won.
2. Sometimes incorrect capturing of opponent's fields occurs, usually near the edges of the board.
3. If the user enters a different number than what is said when loading whether they want to display records assigned to a player (whose nickname is provided after loading 1), it will need to be loaded twice.

## New Options
1. There are two gameplay modes - single or two-player.

## Input and Output Data Syntax
File structure, data types stored in each field of the file.

Reversi game is divided into 6 .cpp files and 5 .hpp files. Header files contain declarations of classes necessary for the correct operation of the program, while .cpp files contain definitions of methods contained in individual classes.

- main.cpp: Displays options for the player to choose, a loop in which the game is played and the order of players' movements is checked, as well as the correctness of piece placements on the board (through a method in the BaseClass). There is a limit for player Y, who in single-player mode is the computer, which can draw a move 150 times. If this happens, it means that the computer did not find a correct place to place its piece, and the coordinates -1 are written as the coordinates, and the move is passed to the opposing player.
- BaseClass.cpp: Contains the game board, sets the initial parameters for the correct start of the game, checks the correctness of players' moves, counts players' points, and checks when the game ends. If the method checking the player's move receives -1 as an argument, it assumes that the move is correct, does not insert any field into the board, and the move is passed to the opposing player. If both players enter -1 in a row, the game ends, points are counted, and based on them, a verdict is issued on which player won.
- File.cpp: Saves to a file the number of points obtained, the game result, and the time of data saving by a player with the entered nickname at the beginning of the game.
- Player_Y.cpp: This class inherits from the abstract class Player_Y_abstr. It has fields x and y (coordinates) that the player enters in the console and confirms only if the move is correct (i.e., in the range from -1 to 7, inclusive). The class has set and get methods for the coordinates x and y.
- Player_Y1p.cpp: This class inherits from the base class Player_Y. The setX and setY methods work by randomly selecting any move. The BaseClass checks if such a move is possible. If not, another one is drawn until it is correct.
- Player_Y_abstr.cpp: A virtual class that has virtual set and get methods for the coordinates x and y for player Y.

## Directory Structure
All files (.cpp, .hpp) and the .vscxproj file should be placed in one folder for the program to compile correctly.

## Code Description
List of files with source code included in the program:
- main.cpp
- BaseClass.cpp
- Player_Y.cpp
- Player_Y_abstr.cpp
- Player_Y1p.cpp
- File.cpp
- BaseClass.hpp
- Player_Y.hpp
- Player_Y_abstr.cpp
- Player_Y1p.hpp
- File.hpp

## Class Diagram
![image](https://github.com/olek2303/reversi_game/assets/60818165/83738c11-d39d-45c7-911c-5c6613eeca67)

