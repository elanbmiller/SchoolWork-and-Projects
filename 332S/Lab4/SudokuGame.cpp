#include "stdafx.h"
#include "SudokuGame.h"
#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include "GameBase.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;


ostream &operator<<(ostream &os, const SudokuGame &sudGame){
	printSudokuBoard(sudGame.XorO, sudGame.width, sudGame.height, sudGame.longestDisp);
	return os;
}

SudokuGame::SudokuGame() : GameBase(9, 9){
	ifstream ifs1(theGame);
	if (!ifs1){
		ofstream ofs(theGame);
		ofs << "NO DATA" << endl;
	}


	ifstream ifs(theGame);
	string data;
	getline(ifs, data);
	if (data == "NO DATA"){
		string display;
		ifstream defaultFile("sudoku0");
		if (defaultFile){
			GamePiece GameP;
			while (getline(defaultFile, display)){
				istringstream Iss(display);
				for (int i = 0; i < 9; ++i){
				Iss >> GameP.display;
				XorO.push_back(GamePiece(Black, "emptyName", GameP.display));
				}
			}
		}
		else{
			throw noSudokuFile;
		}
	}

	else{
		string value;
		getline(ifs, value);
		istringstream iss(value);

		if (!(iss >> width)){
			//cout << "FAILED  TO EXTRACT SAVED VALUES" << endl;
			throw failedToExtractSavedVal;
		}

		getline(ifs, value);
		istringstream iss2(value);
		if (!(iss2 >> height)){
			//cout << "Failed Again" << endl;
			throw failedToExtractSavedVal;
		}

		getline(ifs, value);
		istringstream iss3(value);
		if (!(iss3 >> playCount)){
			//cout << "Failed 2" << endl;
			throw failedToCreateofsFile;
		}

		getline(ifs, value);
		istringstream iss4(value);
		if (!(iss4 >> longestDisp)){
			//cout << "Failed 3" << endl;
			throw failedToExtractSavedVal;
		}
		string pieceVal;
		while (getline(ifs, pieceVal)){
			string color = "";
			GamePiece gp;
			istringstream lastIss(pieceVal);
			lastIss >> color;
			lastIss >> gp.name;
			lastIss >> gp.display;

			gp.someColor = colorPieceToString(color);
			XorO.push_back(gp);

		}
	}
	for (int i = 0; i < 81; ++i){
		if (XorO.at(i).display == "0"){
			XorO.at(i).display = " ";
		}
	}
}

/*
int i = 0;
while (i < 81){
XorO.push_back(GamePiece());
i++;
}

*/


/*
if (data == "NO DATA"){
int i = 0;
while (i < 81){
XorO.push_back(GamePiece());
i++;
}
}
*/

void SudokuGame::print(){
	cout << *this << endl;
}

bool SudokuGame::done(){
	//test rows
	int startRow = 0;
	int innerEndOfRow = 8;
	int outerEndofRow = 9;
	int maxColVal = 73;
	int colValIncrease = 9;
	for (int columnVal = startRow; columnVal < maxColVal; columnVal = columnVal + colValIncrease){
		for (int i = startRow; i < innerEndOfRow; ++i){
			if (XorO.at(startRow + i).display != " "){
				for (int j = i + 1; j < outerEndofRow; ++j){
					if (XorO.at(startRow + columnVal).display == XorO.at(j + columnVal).display){
						//cout << "rows are messed up" << endl;
						return false;
					}
				}
			}
		}
	}

	//test columns
	int startCol = 0;
	int endOfRowVal = 9;
	int innerEndOfCol = 64;
	int outerEndofCol = 73;
	int colIncrease = 9;
	for (int rowVal = startCol; rowVal < endOfRowVal; rowVal++){
		for (int i = startCol; i < innerEndOfCol; i = i + colIncrease){
			if (XorO.at(startCol + i).display != " "){
				for (int j = i + colIncrease; j < outerEndofCol; j = j + colIncrease){
					if (XorO.at(startCol + rowVal).display == XorO.at(j + rowVal).display){
						//cout << "cols are messed up" << endl;
						return false;
					}
				}
			}
		}
	}

	//test squares

	//test first box in bottom left
	//-----------------------------------------------------------
	int test = 0;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 8; ++i){
			if (i == test || i == 1){
				if (XorO.at(test).display == XorO.at(i + 1).display){
					cout << "E1" << endl;
					return false;
				}
			}
			else if (i == 2 || i == 3 || i == 4){
				if (XorO.at(test).display == XorO.at(i + 7).display){
					cout << "E1" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 13).display){
					cout << "E1" << endl;
					return false;
				}
			}
		}
	}
	test = 1;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 7; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 2).display){
					cout << "E2" << endl;
					return false;
				}
			}
			else if (i == 1 || i == 2 || i == 3){
				if (XorO.at(test).display == XorO.at(i + 8).display){
					cout << "E2" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 14).display){
					cout << "E2" << endl;
					return false;
				}
			}
		}
	}
	test = 2;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 6; ++i){
			if (i == 0 || i == 1 || i == 2){
				if (XorO.at(test).display == XorO.at(i + 9).display){
					cout << "E3" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 15).display){
					cout << "E3" << endl;
					return false;
				}
			}
		}
	}
	test = 9;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 5; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 10).display){
					cout << "E4" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 16).display){
					cout << "E4" << endl;
					return false;
				}
			}
		}
	}
	test = 10;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 4; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 11).display){
					cout << "E5" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 17).display){
					cout << "E5" << endl;
					return false;
				}
			}
		}
	}
	test = 11;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 3; ++i){
			if (XorO.at(test).display == XorO.at(i + 18).display){
				cout << "E6" << endl;
				return false;
			}
		}
	}
	test = 18;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 2; ++i){
			if (XorO.at(test).display == XorO.at(i + 19).display){
				cout << "E6" << endl;
				return false;
			}
		}
	}
	test = 19;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 1; ++i){
			if (XorO.at(test).display == XorO.at(i + 20).display){
				cout << "E6" << endl;
				return false;
			}
		}
	}//-----------------------------------------------------------

	//-----------------------------------------------------------
	test = 27;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 8; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 28).display){
					cout << "E7A" << endl;
					return false;
				}
			}
			else if (i == 2 || i == 3 || i == 4){
				if (XorO.at(test).display == XorO.at(i + 34).display){
					cout << "E7B" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 40).display){
					cout << "E7C" << endl;
					return false;
				}
			}
		}
	}
	test = 28;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 7; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 29).display){
					cout << "E8a" << endl;
					return false;
				}
			}
			else if (i == 1 || i == 2 || i == 3){
				if (XorO.at(test).display == XorO.at(i + 35).display){
					cout << "E8b" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 41).display){
					cout << "E8c" << endl;
					return false;
				}
			}
		}
	}
	test = 29;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 6; ++i){
			if (i == 0 || i == 1 || i == 2){
				if (XorO.at(test).display == XorO.at(i + 36).display){
					cout << "E9" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 42).display){
					cout << "E9" << endl;
					return false;
				}
			}
		}
	}
	test = 36;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 5; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 37).display){
					cout << "E10" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 43).display){
					cout << "E10" << endl;
					return false;
				}
			}
		}
	}
	test = 37;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 4; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 38).display){
					cout << "E11" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 44).display){
					cout << "E11" << endl;
					return false;
				}
			}
		}
	}
	test = 38;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 3; ++i){
			if (XorO.at(test).display == XorO.at(i + 45).display){
				cout << "E12" << endl;
				return false;
			}
		}
	}
	test = 45;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 2; ++i){
			if (XorO.at(test).display == XorO.at(i + 46).display){
				cout << "E13" << endl;
				return false;
			}
		}
	}
	test = 46;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 1; ++i){
			if (XorO.at(test).display == XorO.at(i + 47).display){
				cout << "E14" << endl;
				return false;
			}
		}
	}//-----------------------------------------------------------


	//-----------------------------------------------------------
	test = 54;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 8; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 55).display){
					cout << "new err" << endl;
					return false;
				}
			}
			else if (i == 2 || i == 3 || i == 4){
				if (XorO.at(test).display == XorO.at(i + 61).display){
					cout << "new err" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 67).display){
					cout << "new err" << endl;
					return false;
				}
			}
		}
	}
	test = 55;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 7; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 56).display){
					cout << "new err2" << endl;
					return false;
				}
			}
			else if (i == 1 || i == 2 || i == 3){
				if (XorO.at(test).display == XorO.at(i + 62).display){
					cout << "new err2" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 68).display){
					cout << "new err2" << endl;
					return false;
				}
			}
		}
	}
	test = 56;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 6; ++i){
			if (i == 0 || i == 1 || i == 2){
				if (XorO.at(test).display == XorO.at(i + 63).display){
					cout << "new err3" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 69).display){
					cout << "new err3" << endl;
					return false;
				}
			}
		}
	}
	test = 63;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 5; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 64).display){
					cout << "new err4" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 70).display){
					cout << "new err4" << endl;
					return false;
				}
			}
		}
	}
	test = 64;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 4; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 65).display){
					cout << "new err5" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 71).display){
					cout << "new err5" << endl;
					return false;
				}
			}
		}
	}
	test = 65;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 3; ++i){
			if (XorO.at(test).display == XorO.at(i + 72).display){
				cout << "new err6" << endl;
				return false;
			}
		}
	}
	test = 72;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 2; ++i){
			if (XorO.at(test).display == XorO.at(i + 73).display){
				cout << "new err7" << endl;
				return false;
			}
		}
	}
	test = 73;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 1; ++i){
			if (XorO.at(test).display == XorO.at(i + 74).display){
				cout << "new err8" << endl;
				return false;
			}
		}
	}//-----------------------------------------------------------

	//-----------------------------------------------------------
	test = 3;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 8; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 4).display){
					cout << "Err9" << endl;
					return false;
				}
			}
			else if (i == 2 || i == 3 || i == 4){
				if (XorO.at(test).display == XorO.at(i + 10).display){
					cout << "Err9" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 16).display){
					cout << "Err9" << endl;
					return false;
				}
			}
		}
	}
	test = 4;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 7; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 5).display){
					cout << "Err10" << endl;
					return false;
				}
			}
			else if (i == 1 || i == 2 || i == 3){
				if (XorO.at(test).display == XorO.at(i + 11).display){
					cout << "Err10" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 17).display){
					cout << "Err10" << endl;
					return false;
				}
			}
		}
	}
	test = 5;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 6; ++i){
			if (i == 0 || i == 1 || i == 2){
				if (XorO.at(test).display == XorO.at(i + 12).display){
					cout << "Err11" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 18).display){
					cout << "Err11" << endl;
					return false;
				}
			}
		}
	}
	test = 12;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 5; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 13).display){
					cout << "Err12" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 19).display){
					cout << "Err12" << endl;
					return false;
				}
			}
		}
	}
	test = 13;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 4; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 14).display){
					cout << "Err12" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 20).display){
					cout << "Err12" << endl;
					return false;
				}
			}
		}
	}
	test = 14;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 3; ++i){
			if (XorO.at(test).display == XorO.at(i + 21).display){
				cout << "Err13" << endl;
				return false;
			}
		}
	}
	test = 21;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 2; ++i){
			if (XorO.at(test).display == XorO.at(i + 22).display){
				cout << "Err13" << endl;
				return false;
			}
		}
	}
	test = 22;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 1; ++i){
			if (XorO.at(test).display == XorO.at(i + 23).display){
				cout << "Err13" << endl;
				return false;
			}
		}
	}//-----------------------------------------------------------

	//-----------------------------------------------------------
	test = 30;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 8; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 31).display){
					cout << "1.0" << endl;
					return false;
				}
			}
			else if (i == 2 || i == 3 || i == 4){
				if (XorO.at(test).display == XorO.at(i + 37).display){
					cout << "1.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 43).display){
					cout << "1.0" << endl;
					return false;
				}
			}
		}
	}
	test = 31;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 7; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 32).display){
					cout << "1.0" << endl;
					return false;
				}
			}
			else if (i == 1 || i == 2 || i == 3){
				if (XorO.at(test).display == XorO.at(i + 38).display){
					cout << "1.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 44).display){
					cout << "1.0" << endl;
					return false;
				}
			}
		}
	}
	test = 32;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 6; ++i){
			if (i == 0 || i == 1 || i == 2){
				if (XorO.at(test).display == XorO.at(i + 39).display){
					cout << "2.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 45).display){
					cout << "2.0" << endl;
					return false;
				}
			}
		}
	}
	test = 39;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 5; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 40).display){
					cout << "2.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 46).display){
					cout << "2.0" << endl;
					return false;
				}
			}
		}
	}
	test = 40;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 4; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 41).display){
					cout << "2.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 47).display){
					cout << "2.0" << endl;
					return false;
				}
			}
		}
	}
	test = 41;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 3; ++i){
			if (XorO.at(test).display == XorO.at(i + 48).display){
				cout << "3.0" << endl;
				return false;
			}
		}
	}
	test = 48;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 2; ++i){
			if (XorO.at(test).display == XorO.at(i + 49).display){
				cout << "3.0" << endl;
				return false;
			}
		}
	}
	test = 49;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 1; ++i){
			if (XorO.at(test).display == XorO.at(i + 50).display){
				cout << "3.0" << endl;
				return false;
			}
		}
	}//-----------------------------------------------------------

	//-----------------------------------------------------------
	test = 57;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 8; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 58).display){
					cout << "4.0" << endl;
					return false;
				}
			}
			else if (i == 2 || i == 3 || i == 4){
				if (XorO.at(test).display == XorO.at(i + 64).display){
					cout << "4.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 70).display){
					cout << "4.0" << endl;
					return false;
				}
			}
		}
	}
	test = 58;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 7; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 59).display){
					cout << "5.0" << endl;
					return false;
				}
			}
			else if (i == 1 || i == 2 || i == 3){
				if (XorO.at(test).display == XorO.at(i + 65).display){
					cout << "5.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 71).display){
					cout << "5.0" << endl;
					return false;
				}
			}
		}
	}
	test = 59;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 6; ++i){
			if (i == 0 || i == 1 || i == 2){
				if (XorO.at(test).display == XorO.at(i + 66).display){
					cout << "6.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 72).display){
					cout << "6.0" << endl;
					return false;
				}
			}
		}
	}
	test = 66;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 5; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 67).display){
					cout << "7.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 73).display){
					cout << "7.0" << endl;
					return false;
				}
			}
		}
	}
	test = 67;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 4; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 68).display){
					cout << "8.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 74).display){
					cout << "8.0" << endl;
					return false;
				}
			}
		}
	}
	test = 68;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 3; ++i){
			if (XorO.at(test).display == XorO.at(i + 75).display){
				cout << "8.0" << endl;
				return false;
			}
		}
	}
	test = 75;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 2; ++i){
			if (XorO.at(test).display == XorO.at(i + 76).display){
				cout << "8.0" << endl;
				return false;
			}
		}
	}
	test = 76;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 1; ++i){
			if (XorO.at(test).display == XorO.at(i + 77).display){
				cout << "8.0" << endl;
				return false;
			}
		}
	}//-----------------------------------------------------------

	//-----------------------------------------------------------
	test = 6;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 8; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 7).display){
					cout << "9.0" << endl;
					return false;
				}
			}
			else if (i == 2 || i == 3 || i == 4){
				if (XorO.at(test).display == XorO.at(i + 13).display){
					cout << "9.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 19).display){
					cout << "9.0" << endl;
					return false;
				}
			}
		}
	}
	test = 7;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 7; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 8).display){
					cout << "9.0" << endl;
					return false;
				}
			}
			else if (i == 1 || i == 2 || i == 3){
				if (XorO.at(test).display == XorO.at(i + 14).display){
					cout << "9.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 20).display){
					cout << "9.0" << endl;
					return false;
				}
			}
		}
	}
	test = 8;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 6; ++i){
			if (i == 0 || i == 1 || i == 2){
				if (XorO.at(test).display == XorO.at(i + 15).display){
					cout << "11.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 21).display){
					cout << "11.0" << endl;
					return false;
				}
			}
		}
	}
	test = 15;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 5; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 16).display){
					cout << "11.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 22).display){
					cout << "11.0" << endl;
					return false;
				}
			}
		}
	}
	test = 16;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 4; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 17).display){
					cout << "12.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 23).display){
					cout << "12.0" << endl;
					return false;
				}
			}
		}
	}
	test = 17;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 3; ++i){
			if (XorO.at(test).display == XorO.at(i + 24).display){
				cout << "12.0" << endl;
				return false;
			}
		}
	}
	test = 24;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 2; ++i){
			if (XorO.at(test).display == XorO.at(i + 25).display){
				cout << "12.0" << endl;
				return false;
			}
		}
	}
	test = 25;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 1; ++i){
			if (XorO.at(test).display == XorO.at(i + 26).display){
				cout << "12.0" << endl;
				return false;
			}
		}
	}//-----------------------------------------------------------

	//-----------------------------------------------------------
	test = 33;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 8; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 34).display){
					cout << "13.0a" << endl;
					return false;
				}
			}
			else if (i == 2 || i == 3 || i == 4){
				if (XorO.at(test).display == XorO.at(i + 40).display){
					cout << "13.0b" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 46).display){
					cout << "i : " << i << " 13.0c" << endl;
					return false;
				}
			}
		}
	}
	test = 34;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 7; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 35).display){
					cout << "13.0d" << endl;
					return false;
				}
			}
			else if (i == 1 || i == 2 || i == 3){
				if (XorO.at(test).display == XorO.at(i + 41).display){
					cout << "13.0e" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 47).display){
					cout << "13.0f" << endl;
					return false;
				}
			}
		}
	}
	test = 35;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 6; ++i){
			if (i == 0 || i == 1 || i == 2){
				if (XorO.at(test).display == XorO.at(i + 42).display){
					cout << "14.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 48).display){
					cout << "14.0" << endl;
					return false;
				}
			}
		}
	}
	test = 42;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 5; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 43).display){
					cout << "14.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 49).display){
					cout << "14.0" << endl;
					return false;
				}
			}
		}
	}
	test = 43;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 4; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 44).display){
					cout << "15.0" << endl;
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 50).display){
					cout << "15.0" << endl;
					return false;
				}
			}
		}
	}
	test = 44;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 3; ++i){
			if (XorO.at(test).display == XorO.at(i + 51).display){
				cout << "16.0" << endl;
				return false;
			}
		}
	}
	test = 51;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 2; ++i){
			if (XorO.at(test).display == XorO.at(i + 52).display){
				cout << "16.0" << endl;
				return false;
			}
		}
	}
	test = 52;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 1; ++i){
			if (XorO.at(test).display == XorO.at(i + 53).display){
				cout << "16.0" << endl;
				return false;
			}
		}
	}//-----------------------------------------------------------

	//-----------------------------------------------------------
	test = 60;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 8; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 61).display){
					return false;
				}
			}
			else if (i == 2 || i == 3 || i == 4){
				if (XorO.at(test).display == XorO.at(i + 67).display){
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 73).display){
					return false;
				}
			}
		}
	}
	test = 61;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 7; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 62).display){
					return false;
				}
			}
			else if (i == 1 || i == 2 || i == 3){
				if (XorO.at(test).display == XorO.at(i + 68).display){
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 74).display){
					return false;
				}
			}
		}
	}
	test = 62;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 6; ++i){
			if (i == 0 || i == 1 || i == 2){
				if (XorO.at(test).display == XorO.at(i + 69).display){
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 75).display){
					return false;
				}
			}
		}
	}
	test = 69;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 5; ++i){
			if (i == 0 || i == 1){
				if (XorO.at(test).display == XorO.at(i + 70).display){
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 76).display){
					return false;
				}
			}
		}
	}
	test = 70;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 4; ++i){
			if (i == 0){
				if (XorO.at(test).display == XorO.at(i + 71).display){
					return false;
				}
			}
			else{
				if (XorO.at(test).display == XorO.at(i + 77).display){
					return false;
				}
			}
		}
	}
	test = 71;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 3; ++i){
			if (XorO.at(test).display == XorO.at(i + 78).display){
				return false;
			}
		}
	}
	test = 78;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 2; ++i){
			if (XorO.at(test).display == XorO.at(i + 79).display){
				return false;
			}
		}
	}
	test = 79;
	if (XorO.at(test).display != " "){
		for (int i = 0; i < 1; ++i){
			if (XorO.at(test).display == XorO.at(i + 80).display){
				return false;
			}
		}
	}//-----------------------------------------------------------

	//test if XorO vector is full
	/*
	int startVector = 0;
	int endVector = 81;
	for (int i = startVector; i < endVector; ++i){
	if (XorO.at(i).display == " ")
	return false;
	}
	//otherwise gameBoard is filled out and every piece is correct
	return true;
	*/
	return noSpacesAreLeft();
}

bool SudokuGame::noSpacesAreLeft(){
	//test if XorO vector is full
	int startVector = 0;
	int endVector = 81;
	for (int i = startVector; i < endVector; ++i){
		if (XorO.at(i).display == " ")
			return false;
	}
	return true;
}

bool SudokuGame::draw(){
	return false;
}

string SudokuGame::numberToString(unsigned int &number){
	stringstream ss;
	ss << number;
	return ss.str();
}

int SudokuGame::turn(){
	string player1 = "You";
	string player2 = "You";
	string currentPlayer = "";


	unsigned int xVal = 0;
	unsigned int yVal = 0;
	unsigned int tileVal = 0;

	//playCount is a global private variable of TicTacToe



	if (prompt(xVal, yVal, tileVal) != quitGame){

		string printableTileVal = numberToString(tileVal);


		XorO.at(9 * yVal + xVal).display = printableTileVal;
		cout << endl;
		cout << endl;
		cout << "DISPLAY: " << XorO.at(9 * yVal + xVal).display << endl;

		cout << endl;
		print();
		cout << endl;
		Moves += std::to_string(xVal) + "," + std::to_string(yVal) + "," + to_string(tileVal) + ";";
		cout << "Your Moves: " << Moves << endl;
	}
	else{
		return quitGame;
	}
	return success;
}

int SudokuGame::prompt(unsigned int &xVal, unsigned int &yVal, unsigned int &tileVal){

	bool isValidInput = false;		//tells whether we've received valid input

	//test if board is full and let user know
		cout << "Hello, you are playing sudoku" << endl;
		cout << "Fill in the correct values to win!" << endl;
		cout << endl;

	while (isValidInput == false){
		string input = " ";
		std::cout << "Enter coordinates a,b and a tile value or enter quit (Coordinates:[0-8], Tile Value: [1,9])" << endl;
		getline(cin, input);

		if (input == "quit"){
			isValidInput = true;
			return quitGame;
		}

		//test if there are spaces/commas
		unsigned int spaces = 0;
		unsigned int commas = 0;
		for (unsigned int i = 0; i < input.length(); ++i){
			if (input[i] == ',')
				commas += 1;
			else if (input[i] == ' ')
				spaces += 1;
		}

		//if there are spaces, remove them
		if (spaces >= 1)
			input.erase(remove(input.begin(), input.end(), ' '), input.end());	//remove spaces

		//make sure there's only one comma
		if (commas == 2){
			//input.replace(input.find(','), 1, " ");	//replace comma with space
			for (unsigned int i = 0; i < input.length(); ++i){
				if (input[i] == ','){
					input[i] = ' ';
				}
			}
		}

		if (input.size() == 5){
			istringstream iss(input);
			if (!((iss >> xVal) && (iss >> yVal)) || !(iss >> tileVal)){
				cout << "couldn't extract all values" << endl;
				isValidInput = false;
			}
			else if ((xVal < 0 || xVal > 8) || (yVal < 0 || yVal > 8)){
				cout << "coordinates must be in range [0-8]" << endl;
				isValidInput = false;
			}
			else if (tileVal < 1 || tileVal > 9){
				cout << "tile value must be in range [1,9]" << endl;
				isValidInput = false;
			}

			else{
				isValidInput = true;
			}
		}
		else{
			std::cout << "Enter either: a,b,c or quit (a,b:[0,8] and c:[1,9])" << endl;
			isValidInput = false;
		}
	}
	return success;
}