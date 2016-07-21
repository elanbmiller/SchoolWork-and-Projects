/*
Author: Elan Miller
Implements the tic tac toes game with functions from the header
*/


#include "stdafx.h"
#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include "TicTacToe.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//insertion operator to print out the current state of the game
ostream &operator<<(ostream &os, const TicTacToeGame &ticGame){
	printBoard(ticGame.XorO, ticGame.width, ticGame.height);
	return os;
}

TicTacToeGame::TicTacToeGame() : width(5), height(5){
	int i = 0;
	
	while (i < 25){
		XorO.push_back(GamePiece(noColor, "", " "));
		i++;
	}
	/*
	XorO.at(16) = GamePiece(noColor, "", "O");
	XorO.at(7) = GamePiece(noColor, "", "O");
	XorO.at(13) = GamePiece(noColor, "", "O");
	XorO.at(12) = GamePiece(noColor, "", "O");
	*/
	for (int i = 0; i < 21; i += 5){
		XorO.at(i) = GamePiece(noColor, "", " ");	//make the 0th column empty
		XorO.at(i + 4) = GamePiece(noColor, "", " ");	//make the 4th column empty
	}
	for (int i = 0; i < 5; ++i){
		XorO.at(i) = GamePiece(noColor, "", " ");	//make the 0th row empty
		XorO.at(i + 20) = GamePiece(noColor, "", " ");	//make the 4th row empty
	}
	//printBoard(XorO, 5, 5);
}


//tells whether we've reached a game-triggering situation by having 3 adjacent x's or o's
bool TicTacToeGame::done(){
	//first test horizontal
	
	
	for (int i = 3; i > 0; --i){
		if (XorO.at(width*i + 1).display != " "){
		if ((XorO.at(width*i + 1).display) == (XorO.at(width*i + 2).display) &&
			(XorO.at(width*i + 2).display) == (XorO.at(width*i + 3).display)){
			return true;
			}
		}
		//test vertical
		for (int i = 1; i < 4; ++i){
			if (XorO.at(width * 3 + i).display != " "){
				if ((XorO.at(width * 3 + i).display) == (XorO.at(width * 3 + i - 5).display) &&
					(XorO.at(width * 3 + i - 5).display) == (XorO.at(width * 3 + i - 10).display))
					return true;
			}
		}
		//test diagonals
		if (XorO.at(6).display != " "){
		if (((XorO.at(6).display) == (XorO.at(12).display)) && ((XorO.at(12).display) == (XorO.at(18).display))){
		return true;
			}
		}
		
		if (XorO.at(16).display != " "){
			if (((XorO.at(16).display) == (XorO.at(12).display)) && ((XorO.at(12).display) == (XorO.at(8).display))){
				return true;
			}
		}
	}
	return false;
}

//
//if there are moves remaining in the game or the done method returns true, this returns false
bool TicTacToeGame::draw(){
	if (done() == true){
		return false;
	}
	//test if gamboard is complete (ie board is full)
	for (unsigned int xVal = 1; xVal < 4; ++xVal){
		for (unsigned int yVal = 1; yVal < 4; ++yVal){
			if (XorO.at(5 * yVal + xVal).display == " "){
				return false;
			}
		}
	}
	return true;
}

int TicTacToeGame::prompt(unsigned int &xVal, unsigned int &yVal){
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
			cout << "couldn't extract both values" << endl;//Not Sure
			cerr << "couldn't extract both values" << endl;//what to do 
			isValidInput = false;
			//return prompt(xVal, yVal);					   //in this case
		}
		else if((xVal < 1 || xVal > 3) || (yVal < 1 || yVal > 3)){
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

//Prompts current user to 
int TicTacToeGame::turn(){
	string player1 = "X";
	string player2 = "O";
	string currentPlayer = "";


	unsigned int xVal = 0;
	unsigned int yVal = 0;

	//playCount is a global private variable of TicTacToe

		if (playCount % 2 == 1)
			currentPlayer = player1;
		else
			currentPlayer = player2;

		cout << "It is " << currentPlayer << "'s turn." << endl;
		//int promptResult = prompt(xVal, yVal);
		
		if (prompt(xVal, yVal) != quitGame){
			XorO.at(5 * yVal + xVal).display = currentPlayer;
			//print board with ostream operator
			cout << endl;
			cout << *this;
			cout << endl;

			if (currentPlayer == player1){
				xMoves += std::to_string(xVal) + "," + std::to_string(yVal) + "; ";
				cout << "Player " << currentPlayer << " : " << xMoves << endl;
			}
			if (currentPlayer == player2){
				oMoves += std::to_string(xVal) + "," + std::to_string(yVal) + "; ";
				cout << "Player " << currentPlayer << " : " << oMoves << endl;
			}
			//cout << "Player " << currentPlayer << " : " << xVal << "," << yVal << endl;
			//cout << "Player " << currentPlayer << " : " << xMoves << endl;
		}
		else{
			return quitGame;
			}
	return success;
}


int TicTacToeGame::play(){
	cout << *this << endl;
	
	while (!done() && !draw() ){
		if (turn() != quitGame){
		playCount++;
		}
		else{
			cout << playCount - 1 << " Turns were played and a user quit" << endl;
			return userQuit;
		}
	}
	
	if (done()){
		if (playCount % 2 == 1)
			cout << "O was Victorious" << endl;
		else
			cout << "X was Victorious" << endl;
		return success;
	}
	
	else if (draw()){
		cout << playCount - 1 << " Turns were played and the game ended in a draw" << endl;
		return gameDraw;
	}

	return success;
}


//int TicTacToeGame::auto_play(){
//	for (int boardPiece = 1; boardPiece < 10; ++boardPiece){
//		XorO[5*]
//	}
//}



