// Lab1Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lab1Proj.h"
#include "gamePieces.h"
#include "gameBoard.h"

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



int main(int argc, char* argv[]){

	if (argc != commArgs)			//Check to make sure correct number of command line arguments is entered
		return usageMessage(incorrectCommLineArgs, argv[progName], "must enter one input file name");
	

	ifstream ifs(argv[inFile]);
	if (!ifs)
		return usageMessage(failToOpen, argv[progName], "file could not be opened");
	

		unsigned int boardW, boardH;
		int boardResult = readDimensions(ifs, boardW, boardH);

		//keep iterating until values are collected
		while(boardResult == failedToGetLine)
			boardResult = readDimensions(ifs, boardW, boardH);

		//if line can't be gotten
		while (boardResult != success){
			if (boardResult == failedToGetBothVals){
				boardResult = readDimensions(ifs, boardW, boardH);
			}
			else{
				return usageMessage(boardResult, argv[progName], "getline function failed or file couldn't be accessed (check enumeration value for error)");
			}
		}

		if (boardResult == success){
			vector<GamePiece> pieces;
			int positions = boardW*boardH;		//board dimensions = Height * Width;
			
			//create an a vector with empty pieces
			for (int i = 0; i < positions; ++i)
				pieces.push_back(GamePiece());

			//store values from file into the pieces
			int pieceReadResult = readPieces(ifs, pieces, boardW, boardH);
			if (pieceReadResult != success)
				return usageMessage(pieceReadResult, argv[progName], "pieceReadResult failure: check enumeration value");

				
				int finalResult = printBoard(pieces, boardW, boardH);

				if (finalResult != success){
					return usageMessage(finalResult, argv[progName], "Failed to display board -- pieces > dimensions");
				}
				else
					return success;
		}
}