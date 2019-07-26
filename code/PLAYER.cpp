#include "PLAYER.h"

PLAYER::PLAYER()
{
	this->symbol = 'Z';
	this->bot = false;
}


PLAYER::~PLAYER()
{
}


string PLAYER::getName(void)
{
	return this->name;
}


char PLAYER::getSymbol(void)
{
	return this->symbol;
}


PIECE PLAYER::getPiece(int num)
{
	return this->pieces[num];
}


PIECE* PLAYER::getPieces(void)
{
	return this->pieces;
}

void PLAYER::setName(string n)
{
	this->name = n;
}

void PLAYER::setSymbol(char simbol)
{
	this->symbol = simbol;
}

void PLAYER::setNameSymbol(int num_player, string name_ad)
{
	this->name = name_ad;

	if (num_player == 0)
		this->symbol = 'O';
	else
		this->symbol = 'X';
}


void PLAYER::definePieces(void)
{
	int i;

	if (this->getSymbol() == 'O')
	{
		for (i = 0; i < 12; i++)
		{
			this->pieces[i].setSymbol('O');
			this->pieces[i].setOnGame();
			this->pieces[i].setNotKing();

			if (i < 4)
				this->pieces[i].setCoordinates(1 + (i * 2), 0);
			else if (i < 8)
				this->pieces[i].setCoordinates(0 + ((i - 4) * 2), 1);
			else if (i < 12)
				this->pieces[i].setCoordinates(1 + ((i - 8) * 2), 2);
		}
	}
	else
	{
		for (i = 0; i < 12; i++)
		{
			this->pieces[i].setSymbol('X');
			this->pieces[i].setOnGame();
			this->pieces[i].setNotKing();

			if (i < 4)
				this->pieces[i].setCoordinates(0 + (i * 2), 5);
			else if (i < 8)
				this->pieces[i].setCoordinates(1 + ((i - 4) * 2), 6);
			else if (i < 12)
				this->pieces[i].setCoordinates(0 + ((i - 8) * 2), 7);
		}
	}
}


void PLAYER::drawPieces(void)
{
	int i;
	int coor_x, coor_y;

	for (i = 0; i < 12; i++)
	{
		if (this->getPiece(i).getIsOnGame())
		{
			coor_x = this->getPiece(i).getCoordinates().getX();
			coor_y = this->getPiece(i).getCoordinates().getY();

			coor_x = 16 + (this->getPiece(i).getCoordinates().getX() * 8);
			coor_y = 32 - (this->getPiece(i).getCoordinates().getY() * 4);

			gotoxy(coor_x, coor_y);

			if (this->getPiece(i).getIsKing())
				cout << this->getPiece(i).getSymbol() << this->getPiece(i).getSymbol();
			else
				cout << this->getPiece(i).getSymbol();

		}
	}
}

bool PLAYER::doesPlayerOwnIt(int x, int y)
{
	int i;

	for (i = 0; i < 12; i++)
	{
		if ((this->getPiece(i).getCoordinates().getX() == x)
			&& (this->getPiece(i).getCoordinates().getY() == y))
			return true;
	}

	return false;
}


bool PLAYER::canPlayerCapture(int num, PIECE* piecesPlayer2)
{
	int i;

	if (num != -1)
	{
		if (this->pieces[num].doesCaptureExist(this->getPieces(), &(*piecesPlayer2)))
			return true;
	}
	else
	{
		for (i = 0; i < 12; i++)
		{
			if (this->getPiece(i).doesCaptureExist(this->getPieces(), &(*piecesPlayer2)))
				return true;
		}
	}
	return false;
}


bool PLAYER::doesPlayerMoveCapture(int num, int xf, int yf, PIECE* piecesPlayer2, int* numCaptured, int* xCaptured, int* yCaptured)
{
	if (this->pieces[num].doesItCapture(xf, yf, this->getPieces(), &(*piecesPlayer2), &(*numCaptured), &(*xCaptured), &(*yCaptured)))
		return true;
	
	return false;
}


void PLAYER::movePiece(int num, int x, int y)
{
	this->pieces[num].setCoordinates(x, y);
}


void PLAYER::deletePiece(int num)
{
	this->pieces[num].setCoordinates(-1, -1);
	this->pieces[num].setOutGame();
}


bool PLAYER::didPlayerTurnQueen(int num)
{
	if (this->pieces[num].didItTurnKing())
		return true;
	
	return false;
}


bool PLAYER::checkIfPlayerHasNoPieces(void)
{
	int i;
	bool flag = true;

	for (i = 0; i < 12; i++)
	{
		if (this->getPiece(i).getIsOnGame())
		{
			flag = false;
			break;
		}
	}
	return flag;
}

void PLAYER::readFile(ifstream& is, int num_jogador)
{
	char aux[50], simbol = ' ';
	int i = 0;
	string nome_n;

	if (!is)
		return;

	is.getline(aux, sizeof(aux), ';');

	//save the player's name in the first line.
	is.getline(aux, sizeof(aux), '.');
	nome_n = aux;
	this->name = nome_n;

	//define the player's symbol.
	if (num_jogador == 0)
	{
		symbol = 'O';
		simbol = 'O';
	}
	else
	{
		symbol = 'X';
		simbol = 'X';
	}

	//save the 12 pieces and assigns a symbol.
	for (i = 0; i < 12; i++)
	{
		pieces[i].piecesReadFile(is);
		pieces[i].setSymbol(simbol);
	}
}