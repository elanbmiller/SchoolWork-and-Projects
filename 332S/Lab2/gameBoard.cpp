/*
Author: Elan Miller
Implements the visual gameboard
*/


#include "stdafx.h"
#include "gamePieces.h"
#include "gameBoard.h"
#include "enumsAndFunctions.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

int readDimensions(ifstream &file, unsigned int &i, unsigned int &j){
	if (file){		//make sure ifstream has something to read
		string line;
		if (getline(file, line)){
			istringstream iss(line);
			if (!((iss >> i) && (iss >> j))){
				return failedToGetBothVals;
			}
		}
		else{
		return failedToGetLine;
		}
	}
	else{
		return failToOpen;
	}
	return success;
}


//captures values of pieces and locations from a file
int readPieces(ifstream &file, vector<GamePiece> &position, unsigned int width, unsigned int height){
	if (file){
		string line;
		int successfulPiece = 0;
		while (getline(file, line)){
			istringstream iss(line);
			string color, name, display;
			unsigned int pieceWidth, pieceHeight;
			if (!((iss >> color) && (iss >> name) && (iss >> display) && (iss >> pieceWidth) &&
				(iss >> pieceHeight))){}
			else{
				pieceColor somePieceColor = colorPieceToString(color);
				if (!((somePieceColor == invalidColor) || (pieceWidth >= width) || (pieceHeight >= height))){
					successfulPiece = successfulPiece + 1;
					int location = width * pieceHeight + pieceWidth;
					GamePiece thePiece =  GamePiece(somePieceColor, name, display);
					position[location] = thePiece;
				}
			}
		}
		if (successfulPiece > 0)
			return success;
		else
			return failedToFormPiece;
	}
	else
		return failToOpen;
}

//function to print board with border indices
int printBoard(const vector<GamePiece> &pieces, unsigned int x, unsigned int y){
	int endWidth = x - 1;	//adjust width and height to execute for loops correctly
	int endHeight = y - 1;	
	
	if ((pieces.size() <= x*y)){
		for (int i = endHeight; i >= 0; --i){
			for (int j = 0; j <= endWidth; ++j){
				if (j == 0){
					cout << i;
				}
				if (j != endWidth)
					cout << pieces.at(x*i + j).display;
				else
					cout << pieces.at(x*i + j).display << endl;
			}
		}
		cout << " " << 0 << 1 << 2 << 3 << 4 << endl;
		return success;
	}
	else
		return piecesGreaterThanDims;
}