/*
Author: Elan Miller
Defines specific enums (and a few functions from lab0)
*/


#ifndef ENUMSANDFUNCTIONS_H
#define ENUMSANDFUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum indices { progName, inFile, commArgs };

//assigns values to be returned for success and specific failures
enum event {
	success = 0, failToOpen = 1, incorrectCommLineArgs = -1, failedToCreateofsFile = 2, 
	failedToGetLine = 3, failedToGetBothVals = 4,
	failedToGetFiveVals = 5, failedToFormPiece = 6, 
	piecesGreaterThanDims = 7, quitGame = 8, exitGame = 9, 
	gameDraw = 10, userQuit = 11, IncorrectTicTacToe = 12, gameIsNull = 13, 
	IncompatibleGame = 14, AnotherGameExists = 15, BadAlloc = 16, lowAsciiVal = 65, 
	highAsciiVal = 90, capitalAscii = 32, failedToExtractSavedVal = 33, noSudokuFile = 99
};		

int fileParse(vector<string> &Lines, char * File);	//function to parse file


int usageMessage(int returnVal, const string &progName, const string &describeError);			//function to tell user how to run program

void toLowercase(string &wordToModify);

#endif