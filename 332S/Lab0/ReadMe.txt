Elan Miller

Lab 0

Assignment: you will implement a simple C++ program that can (1) read in and parse command line arguments, (2) open a file and read in strings from it, and (3) parse those strings as the definitions of cards in a standard playing deck for bridge, cribbage, poker, etc. Your program will print out what was read and parsed from the file so you can check easily that it worked correctly.

In subsequent lab assignments you will use these features to generate sets of cards, generate different combinations of the cards in a set, and order the different combinations according to various scoring functions.

Warnings/Errors:
1. Program was crashing when no command line arguments were entered 
(other than the program), and this was occuring because I was returning the usage
message with argv[1] as the parameter, which obviously hadn't been entered

2. In my nested for loops in the main method, I initially didn't specify 
unsigned ints, but when I added size_t, no more warnings

Testing:
I created a txt file (example.txt), and I consistently edited and test it 
and passed it as the command line argument for my program, and the program was 
successfully executed on it

Error Testing:
I also tried testing the program by inputting files that didn't exist,
and the program would, of course, return file not able to be opened
I inputted further command line arguments after example.txt as well as no command line
arguments, and the program returned the user message indicating how to run the 
program


BONUS:
1. [elanbmiller@linuxlab006 ~]$
