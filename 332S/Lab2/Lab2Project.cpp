/*
Author: Elan Miller
Main method for tic tac toe game (Lab 2)
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

int main(int argc, char * argv[]){
	
	string theGame = argv[1];

	if (argc == commArgs && theGame == "TicTacToe"){
		TicTacToeGame tGame = TicTacToeGame();
		return tGame.play();
	}
	
	else{
		return usageMessage(IncorrectTicTacToe, argv[progName], "Enter one only one argument after program name");
	}
	
	
	/*string value;
	istringstream iss;
	iss >> value >> xVal >> yVal;
	value = iss.str();
	cout <<"value: " << value << endl;*/
}