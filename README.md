# TicTacToe

TicTacToe C++ Project to be played in console.

How to Play
___

Type ‘c’ to play against the computer
Use the coordinate system labelled across the board to input moves (A/B/C, 1/2/3) Example "A1".
Once the player has inputted a valid move, it becomes the other player's turn. First player to get 3 in a row wins!

![tictactoe](https://cloud.githubusercontent.com/assets/24818991/22197122/9b04b914-e11e-11e6-8517-fef287873fc8.png)

Structure
___
The code was organized with 2 main classes; Board and Player. Board encapsulates all the functionality of a standard TicTicToe board such as getting 3 in a row, cat’s game, and preventing moves from being overwritten. Player assigns the markers, nature (Human or Computer) and records the inputs of each player. 
The player and the board classes have very low coupling; the player has no information about the board, while the board only needs to interact with the player through its public API without worrying about implementation details.
The main function instantiates a board object and 2 player objects, as well as initializes the user interface.

Challenges
___
Handling user input can lead to many unpredictable and unplanned uses of your code. This was the most challenging part of TicTacToe since a multitude of test cases had to be checked to ensure the game runs smoothly under all conditions. 


