CSE 332 : Lab 3
By: Elan Miller 

Assignment: To implement this lab, you will extend your C++ program from the previous lab so that, in addition to playing the TicTacToe Game from lab2, it also can (1)display and play Gomoku game in a larger board to get 5 stones in a row; and (2) detects successful completion of the game or a draw.
In this lab, you will need to refactor your lab 2 implementation so that the code and data structures from both the TicTacToe game(which you implemented in the previous lab) and a new Gomoku game (which you will implement in this lab), form a cohesive class inheritance hierarchy, supporting a non-trivial degree of re-use of the data structures and code that are common to both games.

Tests:
1.Tried various commandline arguments:
As argv[1], I entered Gomoku, and TicTacToe
and program was successful

2. Program was crashing when I didn't enter an
argument or too many arguments or incorrect arguments.
--I was able to fix this, because initially I wasn't 
catching the errors thrown by these cases

3. tested incorrect/out of bounds inputs in the games
and the program handled them correctly by printing an error
message and reprompting the user
