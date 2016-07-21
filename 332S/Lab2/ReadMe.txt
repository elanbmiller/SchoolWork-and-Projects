Elan Miller
CSE 332 - Lab 2

Assignment: you will develop a C++ program with a game class that can (1) repeatedly display the current state of a game (2) prompt the user and receive input for the next move in the game, (3) check whether or not each input move is valid, and if it is update the game state; and (4) detect the following three conditions: successful completion of the game, if the game has reached a point where no further valid moves are possible, or if there are still remaining valid moves available.

Errors:
Ran into a few unsigned int errors, which were easily remedied

Tests:
1. Tested correct input, and program ran successfully
2. Left out command line arg "TicTacToe", usage message was returned
3. Gave incorrect command line args, and successful error was reported
4. Gave incorrect name for TicTacToe, and error message was returned
5. Program was tested and can handle valid/invalid moves, quit, and does
indeed say when the game is over or no moves are left
