#pragma once
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "PIECE.h"
#include "POINT.h"
#include "display.h"
#include "PLAYER.h"

using namespace std;


class REALPLAYER : public PLAYER
{

private:

public:
	REALPLAYER();
	virtual ~REALPLAYER();

	//ask the player the coordinates of the piece he wants to move.
	void askSourcePosition(int* x, int* y);
	//ask the player to where he wants to move the piece.
	void askDestinationPosition(int* x, int* y);
	//Translates the coordinates inserted, in format "a", to two integer numbers (x - 0 to 7; y - 0 to 7).
	void translateToInt(string coordenada, int* x, int* y);

	virtual bool isThisABot(void) { return false; }

	virtual void saveFile(ofstream& os);
};

