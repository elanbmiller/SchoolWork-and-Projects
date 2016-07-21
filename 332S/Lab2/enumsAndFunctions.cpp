/*
Author: Elan Miller
defines a  few functions from lab0, and usageMessage function which is used frequently
*/


#include "stdafx.h"
//#include "Lab1Proj.h"
#include "gamePieces.h"
#include "gameBoard.h"
#include "enumsAndFunctions.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

void toLowercase(string &wordToModify){
	for (auto c = wordToModify.begin(); c != wordToModify.end(); ++c){
		if (*c >= 65 && *c <= 90)
			*c += 32;
	}
}



int usageMessage(int returnVal, const string &progName, const string &describeError){
	cout << "Usage: " << progName << " <InputFile>" << endl;
	cout << describeError << endl;
	return returnVal;
}


/*
From Lab0 -- Not referenced, but including just in case (rewriteen in gamePiece or gameBoard(?))
Function that takes a vector and a file and stores all the strings from the file into the vector
otherwise, returns appropriate error
*/
int fileParse(vector<string> &Lines, char * File){
	ifstream ifs(File);
	if (ifs){				//make sure file is open
		string line, line2;
		while (getline(ifs, line)){

			istringstream lineStream(line);		//bind line to lineStream

			while (lineStream >> line2){
				Lines.push_back(line2);
			}
		}
	}
	else{
		cout << "File didn't open" << endl;
		cerr << failToOpen << endl;
	}
	return success;
}

