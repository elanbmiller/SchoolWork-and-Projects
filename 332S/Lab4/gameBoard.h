/*
Author: Elan Miller
Methods for gameBoard.cpp
*/


#ifndef GAMEBOARD_H
#define GAMEBOARD_H


#include "gamePieces.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>


int readDimensions(ifstream &ifs, unsigned int &i, unsigned int &j);

int readPieces(ifstream &file, vector<GamePiece> &position, unsigned int width, unsigned int height);

int printBoard(const vector<GamePiece> &pieces, unsigned int x, unsigned int y, int space);//Print TicTacToe

int printGomokuBoard(const vector<GamePiece> &pieces, unsigned int x, unsigned int y, int space);

int printSudokuBoard(const vector<GamePiece> &pieces, unsigned int x, unsigned int y, int space);

#endif