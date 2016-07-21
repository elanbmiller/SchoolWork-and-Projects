Author: Elan Miller
CSE 332S Lab 1

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
