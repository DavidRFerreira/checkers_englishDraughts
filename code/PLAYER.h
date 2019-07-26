#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "PIECE.h"
#include "POINT.h"
#include "display.h"

using namespace std;

class PLAYER
{
private:
	PIECE pieces[12];
	string name;
	char symbol;
	bool bot;

public:
	PLAYER();
	virtual ~PLAYER();

	string getName(void);
	char getSymbol(void);
	PIECE getPiece(int num);
	PIECE* getPieces(void);
	void setName(string n);
	void setSymbol(char simbol);

	void setNameSymbol(int num_player, string name_ad);
	void definePieces(void);
	void drawPieces(void);

	//verify if the piece the player wants to move belongs to him.
	bool doesPlayerOwnIt(int x, int y);
	//verify if there is any capture available (it is mandatory).
	bool canPlayerCapture(int num, PIECE* piecesPlayer2);
	//verify if the player's move capture.
	bool doesPlayerMoveCapture(int num, int xf, int yf, PIECE* piecesPlayer2, int* numCaptured, int* xCaptured, int* yCaptured);

	//change a piece's coordinates.
	void movePiece(int num, int x, int y);
	//change a piece's coordinate as -1 and takes it off the game.
	void deletePiece(int num);
	//verify if the piece reached the end of the board.
	bool didPlayerTurnQueen(int num);

	//verify if the player has no piece left on the game.
	bool checkIfPlayerHasNoPieces(void);

	virtual bool isThisABot(void) = 0;

	virtual void saveFile(ofstream &os) = 0;
	void readFile(ifstream &is, int player_num);
};

