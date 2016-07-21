By: Elan Miller and Yonatan David
332: Lab 4

Yonatan David wrote the code to save and open the games correctly and Elan Miller created the Sudoku game
implementation.

How I used:

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


How we saved:
We added a string to keep track of the game in play and we made a save function in the base class which wrote
the name of the game to a file, the width, height, number of turns completed, and the width of the pieces
to be displayed. Then we wrote the pieces to the file (including, display and color and name).
Then, in the derived classes, we first tested if there was a file with the name of that game, if not,
we created one with "no data", then we tested the file. If there was "no data" we created an initial game, if
not, we read in the data from the created file in the order that we wrote it to the file in the base class.

Errors (which were fixed):
--Ran into a few logical errors with testing when the sudoku board was complete, which were easily remedied
by correcting the algorithm to test for completion.

--Also, we were having an error when saving the game 2 times--the game would print the pieces incorrectly
after that. This was remedied by changing the way we were saving the data from the game.