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
#include <iomanip>

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
int printBoard(const vector<GamePiece> &pieces, unsigned int x, unsigned int y, int space){
	int endWidth = x - 1;	//adjust width and height to execute for loops correctly
	int endHeight = y - 1;
	if ((pieces.size() <= 10000)){
		for (int i = endHeight; i >= 0; --i){
			for (int j = 0; j <= endWidth; ++j){
				if (j == 0){
						cout << i;
					
				}
				if (j != endWidth)
					cout << setw(space) << pieces.at(x*i + j).display;
				else{
					cout << setw(space) << pieces.at(x*i + j).display << endl;
					//cout << "\n";
				}
			}
		}
		//cout << setw(space) << " " << 0 << setw(space) << 1 << setw(space) << 2 << setw(space) << 3 << setw(space) << 4 << endl;
		cout << setw(space) << "  ";
		for (unsigned int i = 0; i < x; ++i){
			if (i == x - 1){
				cout << i << endl;
			}
			else{
				cout << i << setw(space);
			}
		}
		return success;
	}
	else
		return piecesGreaterThanDims;
}

int printGomokuBoard(const vector<GamePiece> &pieces, unsigned int x, unsigned int y, int space){
	int endWidth = x - 1;	//adjust width and height to execute for loops correctly
	int endHeight = y - 1;
	if ((pieces.size() <= 10000)){
		for (int i = endHeight; i >= 0; --i){
			for (int j = 0; j <= endWidth; ++j){
				if (j == 0){
					if (i < 10){
						cout << i << " ";
					}
					else{
						cout << i;
					}

				}
				if (j != endWidth)
					cout << setw(space) << pieces.at(x*i + j).display;
				else{
					cout << setw(space) << pieces.at(x*i + j).display << endl;
					//cout << "\n";
				}
			}
		}
		//cout << setw(space) << " " << 0 << setw(space) << 1 << setw(space) << 2 << setw(space) << 3 << setw(space) << 4 << endl;
		cout << setw(space) << "  "<<" ";
		for (unsigned int i = 0; i < x; ++i){
			if (i == x - 1){
				cout << i << endl;
			}
			else{
				cout << i << setw(space);
			}
		}
		return success;
	}
	else
		return piecesGreaterThanDims;
}