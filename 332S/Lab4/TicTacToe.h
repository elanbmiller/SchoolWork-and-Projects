/*
Author: Elan Miller
Creates the TicTacToeGame object with appropriate functions
*/


#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include "GameBase.h"
#include <iostream>
#include <string>

using namespace std;

class TicTacToeGame : public GameBase{

	friend ostream &operator<<(ostream &os, const TicTacToeGame &ticGame);

private:
	int width = 5;
	int height = 5;
	string xMoves = "";
	string oMoves = "";
public:
	TicTacToeGame();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print() override;
};

ostream &operator<<(ostream &os, const TicTacToeGame &ticGame);


#endif