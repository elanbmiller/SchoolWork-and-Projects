/*
Author: Elan Miller
Functions for gamePieces from lab1
*/


#include "stdafx.h"
#include "gamePieces.h"
#include "gameBoard.h"
#include "enumsAndFunctions.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>



string toLowerCaseColor(pieceColor anyColor){		//&?
	
	if (anyColor == Red)
		return "red";
	else if (anyColor == Black)
		return "black";
	else if (anyColor == White)
		return "white";
	else if (anyColor == noColor)
		return "no color";
	else
		return  "invalid color";
}

pieceColor colorPieceToString(string color){		//why can't I use a switch statement!! also, &?
	
	toLowercase(color);
	if (color == "red")return Red;
	else if (color == "black")return Black;
	else if (color == "white")return White;
	else if ((color == "no color") || (color == "") || (color == " ") || (color == "  ") || (color == "	"))
		return noColor;
	else
		return invalidColor;
}