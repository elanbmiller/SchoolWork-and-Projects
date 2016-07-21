Author: Elan Miller
CSE 332S Lab 1

Assignment: you will extend your C++ program from the previous lab so that it can (1) read in and parse files defining the dimensions of a game board, the locations of different pieces on the board, and the symbols used to display the pieces on a game board; (2) recognize badly formatted inputs that the program can handle and then still proceed (e.g., by skipping over a badly formed line in an input file), but have the program exit gracefully if (and only if) it encounters a case it cannot handle (such as not being able to open the input file at all, or not being able to extract dimensions of the game board from the file); and (3) if information gathering from the file succeeded, print out a representation of the game board and the pieces on it.

Errors: Program was returning piecesGreaterThanDims error, but when I fixed
my function for printing my board, I successfully ran my program.

I received some build warinings, but they were simply warnings about unsigned ints
and when I added the unsigned int signature to the respective areas, the warnings
were gone.

Cases:
1. Ran normal file:
		successfully printed board with pieces
2. Ran file with spaces throughout:
		successfully printed board with pieces
3. Ran file with missing parameters to meet each of the error messages:
		correct error messages were reported every time
4. Ran file with some overlapping pieces:
		successfully printed board with pieces replacing the overlapped ones
