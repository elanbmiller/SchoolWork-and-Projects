#ifndef GOMOKUGAME_H
#define GOMOKUGAME_H

#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include "GameBase.h"
#include <iostream>
#include <string>

using namespace std;

class GomokuGame : public GameBase{

	friend ostream &operator<<(ostream &os, const GomokuGame &GomGame);

private:
	int width = 21;
	int height = 21;

	string bMoves = "";
	string wMoves = "";

public:
	GomokuGame();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print() override;
	virtual int prompt(unsigned int &xVal, unsigned int &yVal) override;
};

ostream &operator<<(ostream &os, const GomokuGame &GomGame);

#endif