#ifndef GAMEPIECES_H
#define GAMEPIECES_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;


enum pieceColor{Red, Black, White, invalidColor, noColor};

string toLowerCaseColor(pieceColor anyColor);		//returns pieceColor anyColor in lower case string value 

pieceColor colorPieceToString(string color);		//returns a string color's pieceColor value

struct GamePiece{									
	pieceColor someColor;		//color of piece
	string name;				//name
	string display;				//how it should be displayed
	
	GamePiece() : someColor(noColor),
					name("empty name"),
					display(" ")
	{};

	GamePiece(pieceColor aColor, string theName, string dis) : someColor(aColor),
																   name(theName),
																   display(dis)
	{};
};


#endif