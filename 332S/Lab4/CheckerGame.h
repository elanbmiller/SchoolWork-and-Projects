#ifndef CHECKERGAME_H
#define CHECKERGAME_H


#include "GameBase.h"
#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;


class CheckerGame : public GameBase {

	friend ostream &operator<<(ostream &os, const CheckerGame &Checkers);

private:
	int width = 8;
	int height = 8;

public:
	CheckerGame();
	//bool redOnBoard();	//indicates if red pieces are left
	//bool blackOnBoard();	//indicates if black pieces are left
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual int prompt(unsigned int &xVal, unsigned int &yVal, unsigned int &tileVal1, unsigned int &tileVal2);
	virtual void print() override;
};

ostream &operator<<(ostream &os, const CheckerGame &Checkers);

#endif