#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>

#include "POINT.h"

using namespace std;

class PIECE
{
private:
	PONTO coordinates;
	char symbol; //it can be "X" or "O".
	bool isOnGame; //true for it's on game. false if it was already captured.
	bool isKing; //true for king, false for Man.

public:
	PIECE();
	~PIECE();

	bool getIsKing(void);
	bool getIsOnGame(void);
	char getSymbol(void);
	PONTO getCoordinates(void);

	void setSymbol(char simbolon);
	void setCoordinates(int x, int y);
	void setOnGame(void);
	void setOutGame(void);
	void setKing(void);
	void setNotKing(void);

	//return true if the capture by a man is possible.
	bool manCaptureRight_Up(PIECE* pieceJog1, PIECE* pieceJog2);
	bool manCaptureLeft_Up(PIECE* pieceJog1, PIECE* pieceJog2);
	bool manCaptureRight_Down(PIECE* pieceJog1, PIECE* pieceJog2);
	bool manCaptureLeft_Down(PIECE* pieceJog1, PIECE* pieceJog2);

	//return true if a capture by a king is possible.
	bool kingCaptureRight_Up(PIECE* pieceJog1, PIECE* pieceJog2, int moveSquaresMax, int* distance);
	bool kingCaptureLeft_Up(PIECE* pieceJog1, PIECE* pieceJog2, int moveSquaresMax, int* distance);
	bool kingCaptureRight_Down(PIECE* pieceJog1, PIECE* pieceJog2, int moveSquaresMax, int* distance);
	bool kingCaptureLeft_Down(PIECE* pieceJog1, PIECE* pieceJog2, int moveSquaresMax, int* distance);

	//return the position of the piece with the coordinates(x,y) in the player's pieces array.
	friend int findNumPeca(PIECE *piece, int x, int y); 

	//verifies for a specific piece if it can capture.
	bool doesCaptureExist(PIECE* pieceJog1, PIECE* pieceJog2);
	//verifies if the move choosed by the player captures a piece.
	bool doesItCapture(int xf, int yf, PIECE* pieceJog1, PIECE* pieceJog2, int* numCaptured, int* xCaptured, int* yCaptured);
	//if there is no available capture, verifies if the move is valid.
	bool isMoveValidwithout(int xf, int yf, PIECE* pieceJog1, PIECE* pieceJog2);
	//verifies if a piece reached the end of the board (turning a King).
	bool didItTurnKing(void);

	void piecesSaveFile(ofstream &os);
	void piecesReadFile(ifstream &is);
};

