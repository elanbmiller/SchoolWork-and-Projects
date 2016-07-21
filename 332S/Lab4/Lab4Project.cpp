// Lab4Project.cpp : Defines the entry point for the console application.
//

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
		return usageMessage(BadAlloc, argv[progName],
			"Bad allocation occurred, and there is nothing to do except try again!");
	}
	catch (event err){
		if (err == IncompatibleGame){
			return usageMessage(IncompatibleGame, argv[progName],
				"Enter one only one argument after program name (TicTacToe/Gomoku/Sudoku)");
		}
		else if (err == incorrectCommLineArgs){
			return usageMessage(incorrectCommLineArgs, argv[progName],
				"Enter one only one argument after program name (TicTacToe/Gomoku/Sudoku)");
		}
		else if (err == AnotherGameExists){
			return usageMessage(AnotherGameExists, argv[progName],
				"Another Game Exists");
		}
		else if (err == noSudokuFile){
			return usageMessage(noSudokuFile, argv[progName],
				"There is no file sudoku0--add this file to play sudoku");
		}
		else if (err == failedToExtractSavedVal){
			return usageMessage(failedToExtractSavedVal, argv[progName],
				"Values were unable to be extracted, try again");
		}
		else if (err == userQuit){
			return usageMessage(userQuit, argv[progName],
				"User quit and program crashed. Much apologies--try again though!");
		}
		else if (err == gameDraw){
			return usageMessage(gameDraw, argv[progName],
				"The game was a draw and the program crashed. Much apologies--try again though!");
		}
		else if (err == exitGame){
			return usageMessage(exitGame, argv[progName],
				"Game failed to exit correctly. Try again");
		}
		else if (err == quitGame){
			return usageMessage(quitGame, argv[progName],
				"Game didn't let you quit correctly--Sorry :(");
		}
		else if (err == piecesGreaterThanDims){
			return usageMessage(piecesGreaterThanDims, argv[progName],
				"The gameboard couldn't be created correctly because of formatting issues with the size");
		}
		else if (err == failedToFormPiece){
			return usageMessage(failedToFormPiece, argv[progName],
				"Game Pieces couldn't be created. Try again");
		}
		else if (err == failedToGetBothVals){
			return usageMessage(failedToGetBothVals, argv[progName],
				"Values for board/pieces couldn't be read. Try again");
		}
		else if (err == failedToGetFiveVals){
			return usageMessage(failedToGetFiveVals, argv[progName],
				"Values for board/pieces couldn't be read. Try again");
		}
		else if (err == failedToGetLine){
			return usageMessage(failedToGetLine, argv[progName],
				"Saved values for board/pieces couldn't be read. Try again.");
		}
		else if (err == failedToCreateofsFile){
			return usageMessage(failedToCreateofsFile, argv[progName],
				"File couldn't be created to save game. Try again.");
		}
		else if (err == failToOpen){
			return usageMessage(failToOpen, argv[progName],
				"Files couldn't be opened. Try again");
		}

		return err;
	}
	catch (...) {
		return usageMessage(IncorrectTicTacToe, argv[progName],
			"Enter one only one argument after program name (GameName)");
	}

}
