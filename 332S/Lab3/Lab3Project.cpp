
#include "stdafx.h"
#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include "GameBase.h"
#include "GomokuGame.h"
#include "TicTacToe.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[]){

	try{
	GameBase::getGame(argc, argv);
	shared_ptr<GameBase> Ptr;
	Ptr = GameBase::instantiate();
	return (*Ptr).play();
	}
	catch (bad_alloc) {
		cout << "Bad allocation" << endl;
		return BadAlloc;
	}
	catch (int err){
		if (err == IncompatibleGame || err == incorrectCommLineArgs){
			return usageMessage(IncorrectTicTacToe, argv[progName],
				"Enter one only one argument after program name (TicTacToe)");
		}
		else if (err == AnotherGameExists){
			cout << "Another Game Already Is In Existence" << endl;
		}
		return err;
	}
	catch (...) {
		return usageMessage(IncorrectTicTacToe, argv[progName],
			"Enter one only one argument after program name (TicTacToe)");
	}

}







/*if (argc == commArgs){
string theGame = argv[inFile];
if (theGame == "TicTacToe"){
TicTacToeGame tGame = TicTacToeGame();
return tGame.play();
}
else{
return usageMessage(IncorrectTicTacToe, argv[progName],
"Enter one only one argument after program name (TicTacToe)");
}
}
else{
return usageMessage(IncorrectTicTacToe, argv[progName], "Enter one only one argument after program name");
}*/