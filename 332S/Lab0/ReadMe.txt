Elan Miller

Lab 0

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
