#pragma once
#include <iostream>
#include <iomanip>

#include "display.h"
#include "GAME.h"
#include "menus.h"
#include "POINT.h"

using namespace std;

typedef struct pos_board
{
	bool occupied;
	PONTO p;
} position;

class BOARD
{
private:
	position position[8][8];
public:
	BOARD(); 
	virtual ~BOARD();

	void drawBoard(void);


	//faz a ocupa��o das pe�as iniciais (novo jogo).
	void newGameOccupyPos(void);
	//encontra posi��o do quadrado no array atrav�s das suas coordenadas.
	int findNumSquare(int *num_x, int *num_y, int x, int y);
	//verifica se a posi��o est� livre.
	bool isPosFree(int coor_x, int coor_y); 
	//marca posi��o como livre.
	void freePosition(int coor_x, int coor_y); 
	//marca posi��o como ocupada.
	void occupyPosition(int coor_x, int coor_y); 

	void imprime(void);

	void SaveFile(ofstream &os);
	void ReadFile(ifstream &is);
};

