#ifndef SUDOKUGAME_H
#define SUDOKUGAME_H


#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include "GameBase.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

class SudokuGame: public GameBase{

	friend ostream &operator<<(ostream &os, const SudokuGame &sudGame);

private:
	int width = 9;
	int height = 9;
	string Moves = "";

public:
	SudokuGame();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual int prompt(unsigned int &xVal, unsigned int &yVal, unsigned int &tileVal);
	virtual void print() override;

	bool noSpacesAreLeft();
	string numberToString(unsigned int &number);
};

ostream &operator<<(ostream &os, const SudokuGame &sudGame);

#endif