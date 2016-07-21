#ifndef GAMEBASE_H
#define GAMEBASE_H

#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class GameBase{

	//friend ostream &operator<<(ostream &os, const GameBase &derivedGame);

protected:
	vector<GamePiece>XorO;
	int width;
	int height;
	//int GBplayCount;
	int longestDisp = 2;

	int playCount = 1;

	static std::shared_ptr<GameBase> Ptr;

public:
	GameBase();
	GameBase(vector<GamePiece> GameBoard, int Height, int Width);

	static std::shared_ptr<GameBase> instantiate();
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int prompt(unsigned int &xVal, unsigned int &yVal);//Virtual??
	virtual int turn() = 0;
	
	int play();//do I need virtual?
	virtual void print() = 0;

	static void getGame(int argc, char* argv[]);
	
	
};

//ostream &operator<<(ostream &os, const GameBase &derivedGame);

#endif