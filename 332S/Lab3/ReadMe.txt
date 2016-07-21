CSE 332 : Lab 3
By: Elan Miller and Yonatan David

How we split up work:
Elan refactored the code from TicTacToe to the base class
and ensured that the game was able to run through the refactored 
base class successfully and Yonatan built the Gomoku game based 
on the refactored code to ensure that Gomoku could be played in
the final project as well.

Tests:
1.Tried various commandline arguments:
As argv[1], we entered Gomoku, and TicTacToe
and program was successful

2. Program was crashing when we didn't enter an
argument or too many arguments or incorrect arguments.
--We were able to fix this, because initially we weren't 
catching the errors thrown by these cases

3. We tested incorrect/out of bounds inputs in the games
and the program handled them correctly by printing an error
message and reprompting the user