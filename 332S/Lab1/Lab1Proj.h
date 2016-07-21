#ifndef LAB1PROJ_H
#define LAB1PROJ_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum indices { progName, inFile, commArgs};
enum event {success = 0, failToOpen = 1, incorrectCommLineArgs = -1, failedToGetLine = 3, 
	failedToGetBothVals = 4, failedToGetFiveVals = 5, failedToFormPiece = 6, piecesGreaterThanDims = 7};		//assigns values to be returned for success and specific failures

int fileParse(vector<string> &Lines, char * File);	//function to parse file

int usageMessage(const string &progName, const string &describeError);			//function to tell user how to run program

void toLowercase(string &wordToModify);

#endif