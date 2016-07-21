#include "stdafx.h"
#include "GameBase.h"
#include "gameBoard.h"
#include "gamePieces.h"
#include "GomokuGame.h"
#include "SudokuGame.h"
#include "enumsAndFunctions.h"
#include "TicTacToe.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>


using namespace std;

string GameBase::theGame = "";//keeps track of the game in play


GameBase::GameBase(int height, int width)
	:height(height), width(width), XorO(vector<GamePiece>())
{}
GameBase::GameBase() : width(width), height(height){
	/*int i = 0;
	while (i < 400){
		XorO.push_back(GamePiece(noColor, "", " "));
		i++;
	}*/

}


int GameBase::prompt(unsigned int &xVal, unsigned int &yVal){
	bool isValidInput = false;		//tells whether we've received valid input

	while (isValidInput == false){
		string input = " ";
		cout << "enter coordinates a,b or enter quit (values must be between 1 and 3)" << endl;
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
		if (commas == 1)
			input.replace(input.find(','), 1, " ");	//replace comma with space


		if (input.find(" ") == 1 && input.size() == 3){
			istringstream iss(input);
			if (!((iss >> xVal) && (iss >> yVal))){
				cout << "couldn't extract both values" << endl;
				isValidInput = false;
				//return prompt(xVal, yVal);					   //in this case
			}
			else if ((xVal < 1 || xVal > 3) || (yVal < 1 || yVal > 3)){
				cout << "values must be 1, 2 or 3" << endl;
				isValidInput = false;
				//return prompt(xVal, yVal);
			}
			//I MAY NOT USE THIS: TEST IF X OR O VALUE IS ALREADY IN THAT PLACE
			
			else if ((XorO.at(5 * yVal + xVal).display == "X" || XorO.at(5 * yVal + xVal).display == "O")){
				cout << "a value is already in this postion, enter a new position" << endl;
				isValidInput = false;
			}
			
			else{
				isValidInput = true;
			}
		}
		else{
			cout << "Enter either: a,b or quit (values must be between 1 and 3)" << endl;
			isValidInput = false;
			//return prompt(xVal, yVal);
		}
	}
	//cout << "Correctly entered coordinates: " << xVal << "," << yVal << endl;
	return success;
}


int GameBase::play(){
	print();
while (!done() && !draw()){
	if (turn() != quitGame){
		cout << "Current Game: " << theGame << " -- ";
		playCount++;
	}
	else{
		save();
		cout << playCount - 1 << " Turns were played and a user quit" << endl;
		return userQuit;
	}
}

if (done()){
	
	if (playCount % 2 == 1)
		cout << "Player 2 was Victorious (O or W or SudokuPlayer)" << endl;//ie player 2 is victorious
	else
		cout << "Player 1 was Victorious (X or B or SudokuPlayer)" << endl;//ie player 1 is victorious
	
	ofstream ofs(theGame);
	ofs << "NO DATA" << endl;
	
	return success;
}

else if (draw()){
	cout << playCount - 1 << " Turns were played and the game ended in a draw" << endl;

	ofstream ofs(theGame);
	ofs << "NO DATA" << endl;

	return gameDraw;
}
return success;
}


shared_ptr<GameBase> GameBase::Ptr = nullptr;

shared_ptr<GameBase> GameBase::instantiate(){
	if (GameBase::Ptr != nullptr){
		return GameBase::Ptr;
	}
	else{
		throw(gameIsNull);
	}
}


void GameBase::getGame(int argc, char* argv[]){
	if (argc == commArgs){
		if (GameBase::Ptr == nullptr){
				theGame = argv[1];
			if (theGame == "TicTacToe"){
				GameBase::Ptr = shared_ptr<GameBase>(new TicTacToeGame());
				return;
			}
			else if (theGame == "Gomoku"){
				GameBase::Ptr = shared_ptr<GameBase>(new GomokuGame());
				return;
			}
			else if (theGame == "Sudoku"){
				GameBase::Ptr = shared_ptr<GameBase>(new SudokuGame());
				return;
			}
			
			else{
				throw(IncompatibleGame);
			}
		}
		else{
			throw(AnotherGameExists);
		}
	}
	else{
		throw(incorrectCommLineArgs);
	}
}


void GameBase::save(){
	string input;
	ofstream ofs(theGame);
	
	while (true){
	
	cout << "Save?" << endl;
	cin >> input;
	if (input == "yes" || input == "Yes"){
		ofs << theGame << endl;

		ofs << width << endl;
		ofs << height << endl;
		ofs << playCount << endl;
		ofs << longestDisp << endl;//don't know if I need this bc it's a value of 2 always

		for (GamePiece gp : XorO)
			ofs << toLowerCaseColor(gp.someColor) << " " << gp.name << " " << gp.display << endl;
		return;
	}
	else if (input == "no" || input == "No"){
		ofs << "NO DATA" << endl;
		return;
	}
	else{
		cout << "Please enter yes or Yes or enter no or No" << endl;
	}
	}
	
}