#include "stdafx.h"
#include "gameBoard.h"
#include "gamePieces.h"
#include "enumsAndFunctions.h"
#include "GomokuGame.h"
#include "GameBase.h"
#include <string>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &os, const GomokuGame &GomGame){
	printGomokuBoard(GomGame.XorO, GomGame.width, GomGame.height, 3);
	return os;
}

GomokuGame::GomokuGame() : GameBase(21,21){
	
	ifstream ifs1(theGame);
	if (!ifs1){
		ofstream ofs(theGame);
		ofs << "NO DATA" << endl;
	}

	ifstream ifs(theGame);
	string data;
	getline(ifs, data);
	if (data == "NO DATA"){
		int i = 0;
		while (i <= 21 * 21){
			XorO.push_back(GamePiece());
			i++;
		}
	}
	else{
		string value;
		getline(ifs, value);
		istringstream iss(value);

		if (!(iss >> width)){
			cout << "FAILED  TO EXTRACT SAVED VALUES" << endl;
			throw failedToExtractSavedVal;
		}

		getline(ifs, value);
		istringstream iss2(value);
		if (!(iss2 >> height)){
			cout << "WIDTH: " << width << endl;
			cout << "Failed Again" << endl;
			throw failedToExtractSavedVal;
		}

		getline(ifs, value);
		istringstream iss3(value);
		if (!(iss3 >> playCount)){
			cout << "Failed 2" << endl;
			throw failedToCreateofsFile;
		}

		getline(ifs, value);
		istringstream iss4(value);
		if (!(iss4 >> longestDisp)){
			cout << "Failed 3" << endl;
			throw failedToExtractSavedVal;
		}
		string pieceVal;
		while (getline(ifs, pieceVal)){
			string color = "";
			GamePiece gp;
			istringstream lastIss(pieceVal);
			lastIss >> color;
			lastIss >> gp.name;
			lastIss >> gp.display;

			gp.someColor = colorPieceToString(color);
			XorO.push_back(gp);

		}
	}

}



bool GomokuGame::done(){

	//test horizontals
	int startFirstRow = 22;
	for (unsigned int j = 0; j < 401; j = j + 21){
		for (unsigned int i = 0; i < 15; ++i){
			if (XorO.at(startFirstRow + i + j).display != " "){
				if ((XorO.at(startFirstRow + i + j).display) == (XorO.at(startFirstRow + i + 1 + j).display) &&
					(XorO.at(startFirstRow + i + j).display) == (XorO.at(startFirstRow + i + 2 + j).display) &&
					(XorO.at(startFirstRow + i + j).display) == (XorO.at(startFirstRow + i + 3 + j).display) &&
					(XorO.at(startFirstRow + i + j).display) == (XorO.at(startFirstRow + i + 4 + j).display)){
					return true;
				}
			}
		}
	}
	//test verticals
	int startFirstCol = 22;
	for (unsigned int j = 0; j < 19; ++j){
		for (unsigned int i = 0; i < 318; i = i + 21){
			if (XorO.at(startFirstCol + i + j).display != " "){
				if ((XorO.at(startFirstCol + i + j).display) == (XorO.at(startFirstCol + i + 21 + j).display) &&
					(XorO.at(startFirstCol + i + j).display) == (XorO.at(startFirstCol + i + 42 + j).display) &&
					(XorO.at(startFirstCol + i + j).display) == (XorO.at(startFirstCol + i + 63 + j).display) &&
					(XorO.at(startFirstCol + i + j).display) == (XorO.at(startFirstCol + i + 84 + j).display)){
					return true;
				}
			}
		}
	}

	/*
	Testing diagonals from left to right for top half of gameboard
	*/

	int startCol = 22;
	for (unsigned int i = 0; i < 295; i = i + 21){
		if (i == 0){
			for (unsigned int j = 0; j < 309; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 21){
			for (unsigned int j = 0; j < 287; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 42){
			for (unsigned int j = 0; j < 265; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 63){
			for (unsigned int j = 0; j < 243; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 84){
			for (unsigned int j = 0; j < 221; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 105){
			for (unsigned int j = 0; j < 199; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 126){
			for (unsigned int j = 0; j < 177; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 147){
			for (unsigned int j = 0; j < 155; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 168){
			for (unsigned int j = 0; j < 133; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 189){
			for (unsigned int j = 0; j < 111; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 210){
			for (unsigned int j = 0; j < 89; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 231){
			for (unsigned int j = 0; j < 67; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}


		else if (i == 252){
			for (unsigned int j = 0; j < 45; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 273){
			for (unsigned int j = 0; j < 23; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 294){
			for (unsigned int j = 0; j < 1; j = j + 22){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
						return true;
					}
				}
			}
		}

	}//end first for loop
		/*
		Done Testing Top half diagonals from left to right
		Now Testing bottom half
		*/

		startCol = 22;
		for (unsigned int i = 0; i < 15; ++i){
			if (i == 0){
				for (unsigned int j = 0; j < 309; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 1){
				for (unsigned int j = 0; j < 287; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 2){
				for (unsigned int j = 0; j < 265; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 3){
				for (unsigned int j = 0; j < 243; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 4){
				for (unsigned int j = 0; j < 221; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 5){
				for (unsigned int j = 0; j < 199; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 6){
				for (unsigned int j = 0; j < 177; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 7){
				for (unsigned int j = 0; j < 155; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 8){
				for (unsigned int j = 0; j < 133; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 9){
				for (unsigned int j = 0; j < 111; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 10){
				for (unsigned int j = 0; j < 89; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 11){
				for (unsigned int j = 0; j < 67; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 12){
				for (unsigned int j = 0; j < 45; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 13){
				for (unsigned int j = 0; j < 23; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}
			else if (i == 14){
				for (unsigned int j = 0; j < 1; j = j + 22){
					if (XorO.at(startCol + i + j).display != " "){
						if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 22 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 44 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 66 + j).display) &&
							(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 88 + j).display)){
							return true;
						}
					}
				}
			}


	}//end for loop

	/*
	Testing Left to right diagonals
	*/

	startCol = 40;
	for (unsigned int i = 0; i < 15; ++i){
		if (i == 0){
			for (unsigned int j = 0; j < 281; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 1){
			for (unsigned int j = 0; j < 261; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 2){
			for (unsigned int j = 0; j < 241; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 3){
			for (unsigned int j = 0; j < 221; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 4){
			for (unsigned int j = 0; j < 201; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 5){
			for (unsigned int j = 0; j < 181; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 6){
			for (unsigned int j = 0; j < 161; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 7){
			for (unsigned int j = 0; j < 141; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 8){
			for (unsigned int j = 0; j < 121; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 9){
			for (unsigned int j = 0; j < 101; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 10){
			for (unsigned int j = 0; j < 81; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 11){
			for (unsigned int j = 0; j < 61; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 12){
			for (unsigned int j = 0; j < 41; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 13){
			for (unsigned int j = 0; j < 21; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}

		else if (i == 14){
			for (unsigned int j = 0; j < 1; j = j + 20){
				if (XorO.at(startCol - i + j).display != " "){
					if ((XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 20 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 40 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 60 + j).display) &&
						(XorO.at(startCol - i + j).display) == (XorO.at(startCol - i + 80 + j).display)){
						return true;
					}
				}
			}
		}
	
	}//end for loop

	//upper bound left to right

	startCol = 40;
	for (unsigned int i = 0; i < 295; i = i + 21){
		if (i == 0){
			for (unsigned int j = 0; j < 281; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 21){
			for (unsigned int j = 0; j < 261; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 42){
			for (unsigned int j = 0; j < 241; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 63){
			for (unsigned int j = 0; j < 221; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 84){
			for (unsigned int j = 0; j < 201; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 105){
			for (unsigned int j = 0; j < 181; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 126){
			for (unsigned int j = 0; j < 161; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 147){
			for (unsigned int j = 0; j < 141; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 168){
			for (unsigned int j = 0; j < 121; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 189){
			for (unsigned int j = 0; j < 101; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 210){
			for (unsigned int j = 0; j < 81; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 231){
			for (unsigned int j = 0; j < 61; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 252){
			for (unsigned int j = 0; j < 41; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 273){
			for (unsigned int j = 0; j < 21; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}
		else if (i == 294){
			for (unsigned int j = 0; j < 1; j = j + 20){
				if (XorO.at(startCol + i + j).display != " "){
					if ((XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 20 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 40 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 60 + j).display) &&
						(XorO.at(startCol + i + j).display) == (XorO.at(startCol + i + 80 + j).display)){
						return true;
					}
				}
			}
		}


	}//end for loop



	return false;
}

bool GomokuGame::draw(){
	
	for (unsigned int i = 22; i < 419; ++i){
	//first test if it equals a value not included in range
		if (i == 41 || i == 42 || i == 62 || i == 63 || i == 83
			|| i == 84 || i == 104 || i == 105 || i == 125 || i == 126
			|| i == 146 || i == 147 || i == 167 || i == 168 || i == 188
			|| i == 189 || i == 209 || i == 210 || i == 230 || i == 231
			|| i == 251 || i == 252 || i == 272 || i == 273 || i == 293
			|| i == 294 || i == 314 || i == 315 || i == 335 || i == 336
			|| i == 356 || i == 357 || i == 377 || i == 378 || i == 398
			|| i == 399){}
		else if (XorO.at(i).display != "B" || XorO.at(i).display != "W"){
			return false;
		}
	}
	return true;
}

void GomokuGame::print(){
	cout << *this << endl;
}

int GomokuGame::prompt(unsigned int &xVal, unsigned int &yVal){
	bool isValidInput = false;		//tells whether we've received valid input

	while (isValidInput == false){
		string input = " ";
		std::cout << "enter coordinates a,b or enter quit (values must be between 1 and 19)" << endl;
		getline(cin, input);

		if (input == "quit"){
			isValidInput = true;
			return quitGame;
		}

		//test if there are spaces/commas
		unsigned int spaces = 0;
		unsigned int commas = 0;
		for (unsigned int i = 0; i < input.length(); ++i){
			if (input[i] == ',')
				commas += 1;
			else if (input[i] == ' ')
				spaces += 1;
		}

		//if there are spaces, remove them
		if (spaces >= 1)
			input.erase(remove(input.begin(), input.end(), ' '), input.end());	//remove spaces

		//make sure there's only one comma
		if (commas == 1){
			//input.replace(input.find(','), 1, " ");	//replace comma with space
			for (unsigned int i = 0; i < input.length(); ++i){
				if (input[i] == ','){
					input[i] = ' ';
				}
			}
		}

		if (input.size() == 3 || input.size() == 4 || input.size() == 5){
			istringstream iss(input);
			if (!((iss >> xVal) && (iss >> yVal))){
				std::cout << "couldn't extract both values" << endl;
				isValidInput = false;
				//return prompt(xVal, yVal);					   //in this case
			}
			else if ((xVal < 1 || xVal > 19) || (yVal < 1 || yVal > 19)){
				std::cout << "values must be in range [1-19]" << endl;
				isValidInput = false;
				//return prompt(xVal, yVal);

			}
			//I MAY NOT USE THIS: TEST IF X OR O VALUE IS ALREADY IN THAT PLACE
			
			else if ((XorO.at(width * yVal + xVal).display == "B" || XorO.at(width * yVal + xVal).display == "W")){

				std::cout << "a value is already in this postion, enter a new position" << endl;
				isValidInput = false;
			}
			else{
				isValidInput = true;
			}
		}
		else{
			std::cout << "Enter either: a,b or quit (values must be between 1 and 19 inclusive)" << endl;
			isValidInput = false;
			//return prompt(xVal, yVal);
		}
	}
	//cout << "Correctly entered coordinates: " << xVal << "," << yVal << endl;
	return success;
}

int GomokuGame::turn(){
	string player1 = "B";
	string player2 = "W";
	string currentPlayer = "";


	unsigned int xVal = 0;
	unsigned int yVal = 0;

	//playCount is a global private variable of TicTacToe

	if (playCount % 2 == 1)
		currentPlayer = player1;
	else
		currentPlayer = player2;

	std::cout << "It is " << currentPlayer << "'s turn." << endl;

	if (prompt(xVal, yVal) != quitGame){

		XorO.at(width * yVal + xVal).display = currentPlayer;
		
		//print board with ostream operator
		std::cout << endl;
		//cout << *this;
		print();
		std::cout << endl;
		if (currentPlayer == player1){
			bMoves += std::to_string(xVal) + "," + std::to_string(yVal) + "; ";
			std::cout << "Player " << currentPlayer << " : " << bMoves << endl;
		}
		if (currentPlayer == player2){
			wMoves += std::to_string(xVal) + "," + std::to_string(yVal) + "; ";
			std::cout << "Player " << currentPlayer << " : " << wMoves << endl;
		}
	}
	else{
		return quitGame;
	}
	return success;
}