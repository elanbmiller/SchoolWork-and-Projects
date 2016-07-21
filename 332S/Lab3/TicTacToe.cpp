/*
Author: Elan Miller
Implements the tic tac toes game with functions from the header
*/


#include "stdafx.h"
#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include "GameBase.h"
#include "TicTacToe.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//insertion operator to print out the current state of the game
ostream &operator<<(ostream &os, const TicTacToeGame &ticGame){
	printBoard(ticGame.XorO, ticGame.width, ticGame.height, ticGame.longestDisp);
	return os;
}

void TicTacToeGame::print(){
	//try{
		cout << *this << endl;
	//}
	/*catch (){
		throw;
	}*/
}


TicTacToeGame::TicTacToeGame() : width(5), height(5){
	int i = 0;
	
	while (i < 25){
		XorO.push_back(GamePiece(noColor, "", " "));
		i++;
	}
	
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
		
		if (prompt(xVal, yVal) != quitGame){
			
			XorO.at(5 * yVal + xVal).display = currentPlayer;
			cout << "DISPLAY: " << XorO.at(5 * yVal + xVal).display << endl;
			//print board with ostream operator
			cout << endl;
			//cout << *this;
			print();
			cout << endl;
			if (currentPlayer == player1){
				xMoves += std::to_string(xVal) + "," + std::to_string(yVal) + "; ";
				cout << "Player " << currentPlayer << " : " << xMoves << endl;
			}
			if (currentPlayer == player2){
				oMoves += std::to_string(xVal) + "," + std::to_string(yVal) + "; ";
				cout << "Player " << currentPlayer << " : " << oMoves << endl;
			}
		}
		else{
			return quitGame;
			}
	return success;
}

/*
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
*/


