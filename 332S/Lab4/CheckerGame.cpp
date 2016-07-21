#include "stdafx.h"
#include "CheckerGame.h"
#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include "GameBase.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>


ostream &operator<<(ostream &os, const CheckerGame &Checkers){
	printCheckerBoard(Checkers.XorO, Checkers.width, Checkers.height, Checkers.longestDisp);
	return os;
}

CheckerGame::CheckerGame() : GameBase(8,8) {
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
		ifstream defaultFile("checker0");
		if (defaultFile){
			GamePiece GameP;
			while (getline(defaultFile, display)){
				istringstream Iss(display);
				for (int i = 0; i < 8; ++i){
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
			cout << "FAILED  TO EXTRACT SAVED VALUES" << endl;
			throw failedToExtractSavedVal;
		}

		getline(ifs, value);
		istringstream iss2(value);
		if (!(iss2 >> height)){
			cout << "Failed Again" << endl;
			throw failedToExtractSavedVal;
		}

		getline(ifs, value);
		istringstream iss3(value);
		if (!(iss3 >> playCount)){
			cout << "Failed 2" << endl;
			throw failedToCreateofsFile;
		}

		getline(ifs, value);
		istringstream iss4(value);
		if (!(iss4 >> longestDisp)){
			cout << "Failed 3" << endl;
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
	for (int i = 0; i < 64; ++i){
		if (XorO.at(i).display == "0"){
			XorO.at(i).display = " ";
		}
	}
}

void CheckerGame::print(){
	cout << *this << endl;
}

bool CheckerGame::draw(){
	return false;
}

bool CheckerGame::done(){
	for (int i = 0; i < 64; ++i){
		if (XorO.at(i).display != "b" && XorO.at(i).display != "B" && XorO.at(i).display != "r"
			&& XorO.at(i).display != "R"){
			return false;
		}
	}
	return true;
}

int CheckerGame::turn(){
	string player1 = "B";
	string player2 = "R";
	string currentPlayer = "";


	unsigned int xVal = 0;
	unsigned int yVal = 0;
	unsigned int tileVal1 = 0;
	unsigned int tileVal2 = 0;

	//playCount is a global private variable of TicTacToe

	if (playCount % 2 == 1)
		currentPlayer = player1;
	else
		currentPlayer = player2;

	cout << "It is " << currentPlayer << "'s turn." << endl;

	if (prompt(xVal, yVal, tileVal1, tileVal2) != quitGame){

		XorO.at(width * yVal + xVal).display = ' ';//set place where piece was to clear now
		XorO.at(width * tileVal2 + tileVal1).display = currentPlayer;

		if (tileVal2 > yVal && tileVal1 > xVal){
			XorO.at(width * (tileVal2 - 1) + (tileVal1 - 1)).display = currentPlayer;
		}
		else if (tileVal2 > yVal && tileVal1 < xVal){
			XorO.at(width * (tileVal2 - 1) + (tileVal1 + 1)).display = currentPlayer;
		}
		else if (tileVal2 > yVal && tileVal1 == xVal){
			XorO.at(width * (tileVal2 - 1) + (tileVal1)).display = currentPlayer;
		}
		//================================Testing Going Down
		else if (tileVal2 < yVal && tileVal1 == xVal){
			XorO.at(width * (tileVal2 + 1) + (tileVal1)).display = currentPlayer;
		}
		else if (tileVal2 < yVal && tileVal1 < xVal){
			XorO.at(width * (tileVal2 + 1) + (tileVal1 + 1)).display = currentPlayer;
		}
		else if (tileVal2 < yVal && tileVal1 > xVal){
			XorO.at(width * (tileVal2 + 1) + (tileVal1 - 1)).display = currentPlayer;
		}

		//print board with ostream operator
		std::cout << endl;
		//cout << *this;
		print();
		std::cout << endl;
		/*if (currentPlayer == player1){
			bMoves += std::to_string(xVal) + "," + std::to_string(yVal) + "; ";
			std::cout << "Player " << currentPlayer << " : " << bMoves << endl;
		}
		if (currentPlayer == player2){
			wMoves += std::to_string(xVal) + "," + std::to_string(yVal) + "; ";
			std::cout << "Player " << currentPlayer << " : " << wMoves << endl;
		}*/
	}
	else{
		return quitGame;
	}
	return success;
}

int CheckerGame::prompt(unsigned int &xVal, unsigned int &yVal, unsigned int &tileVal1, unsigned int &tileVal2){
	bool isValidInput = false;		//tells whether we've received valid input

	while (isValidInput == false){
		string input = " ";
		cout << "enter coordinates x, y, x2, y2 or enter quit (values must be between 1 and 8)" << endl;
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

		//make sure there's three commas
		if (commas == 3){
			//input.replace(input.find(','), 1, " ");	//replace comma with space
			for (unsigned int i = 0; i < input.length(); ++i){
				if (input[i] == ','){
					input[i] = ' ';
				}
			}
		}

		if (input.size() == 7){
			istringstream iss(input);
			if (!((iss >> xVal) && (iss >> yVal)) || !((iss >> tileVal1) && (iss >> tileVal2))){
				cout << "couldn't extract all 3 values" << endl;
				isValidInput = false;
			}
			else if ((xVal < 0 || xVal > 7) || (yVal < 0 || yVal > 7) || (tileVal1 < 0 || tileVal1 > 7) ||
				(tileVal2 < 0 || tileVal2 > 7)){
				cout << "values must be in range [0-7]" << endl;
				isValidInput = false;
			}

			else if ((XorO.at(width * yVal + xVal).display != "B" && XorO.at(width *
				yVal + xVal).display != "R")){
				cout << "there's no piece to move in this position, enter a new position" << endl;
				isValidInput = false;
			}

			else if ((XorO.at(width * tileVal2 + tileVal1).display == "B" || XorO.at(width * 
				tileVal2 + tileVal1).display == "R")){
				cout << "a value is already in the postion you are trying to move to, enter a new position"<< endl;
				isValidInput = false;
			}
			


			/**else if (((xVal + 2) != tileVal1 && (xVal - 2) != tileVal1) && 
				((yVal + 2) != tileVal2 && (yVal - 2) != tileVal2)){
				if (((xVal + 1) != tileVal1 && (xVal - 1) != tileVal1) 
					&& ((yVal + 1) != tileVal2 && (yVal - 1) != tileVal2)){

					cout << "tileVal1: " << tileVal1 << " tileVal2: " << tileVal2 <<
						" xVal: "<< xVal << " yVal: " << yVal <<endl;

					cout << "xVal + 2: " << xVal + 2 << " xVal - 2: " << xVal - 2 <<
						" xVal + 1: " << xVal + 1 << " xVal - 1: " << xVal - 1 << endl;

					cout << "yVal + 2: " << yVal + 2 << " yVal - 2: " << yVal - 2 <<
						" yVal + 1: " << yVal + 1 << " yVal - 1: " << yVal - 1 << endl;

					cout << "Illegal jump! Try again" << endl;
					isValidInput = false;
				}
				else{
					isValidInput = true;
				}
			}**/
			else{
				isValidInput = true;
			}
		}
		else{
			cout << "Enter either: a,b,c,d or quit (values must be between 0 and 7 inclusive)" << endl;
			isValidInput = false;
		}
	}
	return success;
}