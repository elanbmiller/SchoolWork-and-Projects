By: Elan Miller
332: Lab 4

Assignment: To implement this lab, you will extend your C++ program from the previous lab so that it in addition to playing the TicTacToe and Gomoku games from the previous lab assignment, it also can play a new game Sudoku. You will also modify your gamebase class and your main program so that (1) a single instance of the current game is accessed through a single static method, and (2) if a player quits a game they will have the option of saving (and later resuming) the state of the game.

I didn't use any of these features in my classes.
	
	copy constructor--I had no need for a copy constructor given that the compiler creates one implicitly.
	Also, none of my classes had pointers that needed a deep copy which could be done by using a copy constructor.
	
	move constructor--Similarly, I had no need to define a way to transfer the implementation of any 
	of the objects.
	
	copy-assignment operator--Again, there was no need for me to use this as I had no need to reset my objects
	values as I did this alternatively with my code.
	
	move-assignment operator--Again, there was no need for me to use this as I had no need to reset my objects
	values as I did this alternatively with my code
		
	destructor--Lastly, I didn't define a destructor as I was able to rely on the compiler generated destructors
	to deallocate my classes after use as none of my derived classes contained dynamically stored objects


How I saved:
I added a string to keep track of the game in play and we made a save function in the base class which wrote
the name of the game to a file, the width, height, number of turns completed, and the width of the pieces
to be displayed. Then we wrote the pieces to the file (including, display and color and name).
Then, in the derived classes, I first tested if there was a file with the name of that game, if not,
I created one with "no data", then I tested the file. If there was "no data" I created an initial game, if
not, I read in the data from the created file in the order that I wrote it to the file in the base class.

Errors (which were fixed):
--Ran into a few logical errors with testing when the sudoku board was complete, which were easily remedied
by correcting the algorithm to test for completion.

--Also, I was having an error when saving the game 2 times--the game would print the pieces incorrectly
after that. This was remedied by changing the way I Was saving the data from the game.
