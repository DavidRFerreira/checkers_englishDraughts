#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "display.h"
#include "menus.h"
#include "PIECE.h"
#include "POINT.h"
#include "BOARD.h"
#include "PLAYER.h"
#include "REALPLAYER.h"
#include "BOTPLAYER.h"

using namespace std;

class GAME
{
private: 
	char symbol;
	int numCurrentPlayer;
	int numNextPlayer;
	int newMatch;
	int bot;

public:
	GAME();
	GAME(int newGame, int botexist);
	virtual ~GAME();
	
	char getRound(void);
	void changeRound(void);
	int getNumCurrentPlayer(void);
	int getNumNextPlayer(void);

	int playMatch(string file_name);
	int playMatchBot(string file_name);

	void saveFile(ofstream &os);
	void readFile(ifstream &is);
};

