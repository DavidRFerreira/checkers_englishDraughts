#include "PIECE.h"

PIECE::PIECE()
{
	this->coordinates.setX(-1);
	this->coordinates.setY(-1);
	this->isKing = false;
	this->symbol = 'Z';
	this->isOnGame = false;
}


PIECE::~PIECE()
{
}


bool PIECE::getIsKing(void)
{
	return this->isKing;
}


bool PIECE::getIsOnGame(void)
{
	return this->isOnGame;
}


char PIECE::getSymbol(void)
{
	return this->symbol;
}


PONTO PIECE::getCoordinates(void)
{
	return coordinates;
}


void PIECE::setSymbol(char simbolon)
{
	this->symbol = simbolon;
}


void PIECE::setCoordinates(int x, int y)
{
	this->coordinates.setX(x);
	this->coordinates.setY(y);
}


void PIECE::setOnGame(void)
{
	this->isOnGame = true;
}


void PIECE::setOutGame(void)
{
	this->isOnGame = false;
}


void PIECE::setKing(void)
{
	this->isKing = true;
}


void PIECE::setNotKing(void)
{
	this->isKing = false;
}


bool PIECE::manCaptureRight_Up(PIECE* pieceJog1, PIECE* pieceJog2)
{
	//verifies upper-right capture for man.
	if (findNumPeca(&(*pieceJog2), this->coordinates.getX() + 1, this->coordinates.getY() + 1) != -1)
	{
		if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() + 2, this->coordinates.getY() + 2) == -1)
			&& (findNumPeca(&(*pieceJog2), this->coordinates.getX() + 2, this->coordinates.getY() + 2) == -1))
		{
			if ((0 <= this->coordinates.getX() + 2) && (this->coordinates.getX() + 2 <= 7)
				&& (0 <= this->coordinates.getY() + 2) && (this->coordinates.getY() + 2 <= 7))
				return true;
		}
	}
	return false;
}


bool PIECE::manCaptureLeft_Up(PIECE* pieceJog1, PIECE* pieceJog2)
{
	//verifies upper-left capture for man.
	if (findNumPeca(&(*pieceJog2), this->coordinates.getX() - 1, this->coordinates.getY() + 1) != -1)
	{
		if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() - 2, this->coordinates.getY() + 2) == -1)
			&& (findNumPeca(&(*pieceJog2), this->coordinates.getX() - 2, this->coordinates.getY() + 2) == -1))
		{
			if ((0 <= this->coordinates.getX() - 2) && (this->coordinates.getX() - 2 <= 7)
				&& (0 <= this->coordinates.getY() + 2) && (this->coordinates.getY() + 2 <= 7))
				return true;
		}
	}
	return false;
}


bool PIECE::manCaptureRight_Down(PIECE* pieceJog1, PIECE* pieceJog2)
{
	//verifies under-right capture for man.
	if (findNumPeca(&(*pieceJog2), this->coordinates.getX() + 1, this->coordinates.getY() - 1) >= 0)
	{
		if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() + 2, this->coordinates.getY() - 2) == -1)
			&& (findNumPeca(&(*pieceJog2), this->coordinates.getX() + 2, this->coordinates.getY() - 2) == -1))
		{
			if ((0 <= this->coordinates.getX() + 2) && (this->coordinates.getX() + 2 <= 7)
				&& (0 <= this->coordinates.getY() - 2) && (this->coordinates.getY() - 2 <= 7))
				return true;
		}
	}
	return false;
}


bool PIECE::manCaptureLeft_Down(PIECE* pieceJog1, PIECE* pieceJog2)
{
	//verifies under-left capture for man.
	if (findNumPeca(&(*pieceJog2), this->coordinates.getX() - 1, this->coordinates.getY() - 1) >= 0)
	{
		if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() - 2, this->coordinates.getY() - 2) == -1)
			&& (findNumPeca(&(*pieceJog2), this->coordinates.getX() - 2, this->coordinates.getY() - 2) == -1))
		{
			if ((0 <= this->coordinates.getX() - 2) && (this->coordinates.getX() - 2 <= 7)
				&& (0 <= this->coordinates.getY() - 2) && (this->coordinates.getY() - 2 <= 7))
				return true;
		}
	}
	return false;
}


bool PIECE::kingCaptureRight_Up(PIECE* pieceJog1, PIECE* pieceJog2, int moveSquaresMax, int *distance)
{
	int l = 1;

	//verifies upper-right capture for king.
	do
	{
		//if the next position is occupied by an opponent's piece.
		if (findNumPeca(&(*pieceJog2), this->coordinates.getX() + (l * 1), this->coordinates.getY() + (l * 1)) != -1)
		{
			//verifies if there is at least a free square next to the opponent's piece (inside the board).
			if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() + ((l+1) * 1), this->coordinates.getY() + ((l+1) * 1)) == -1)
				&& (findNumPeca(&(*pieceJog2), this->coordinates.getX() + ((l+1) * 1), this->coordinates.getY() + ((l+1) * 1)) == -1))
			{
				if (((0 <= this->coordinates.getX() + ((l + 1) * 1)) && (this->coordinates.getX() + ((l + 1) * 1)) <= 7)
					&& ((0 <= this->coordinates.getY() + ((l + 1) * 1)) && (this->coordinates.getY() + ((l + 1) * 1) <= 7)))
				{
					*distance = l;
					return true;
				}
			}
		}

		//if there is a square occupied by a piece from the player playing, it can't proceed more.
		else if (findNumPeca(&(*pieceJog1), this->coordinates.getX() + (l * 1), this->coordinates.getY() + (l * 1)) != -1)
			l = moveSquaresMax - 1;
		
		l++;
	} while (l < moveSquaresMax);

	return false;
}


bool PIECE::kingCaptureLeft_Up(PIECE* pieceJog1, PIECE* pieceJog2, int moveCasasMax, int *distancia)
{
	int l = 1;
	
	//verifies upper-left capture for king.
	do
	{
		if (findNumPeca(&(*pieceJog1), this->coordinates.getX() - (l * 1), this->coordinates.getY() + (l * 1)) != -1)
		{
			if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() - ((l + 1) * 1), this->coordinates.getY() + ((l + 1) * 1)) == -1)
				&& (findNumPeca(&(*pieceJog2), this->coordinates.getX() - ((l + 1) * 1), this->coordinates.getY() + ((l + 1) * 1)) == -1)
				&& ((0 <= this->coordinates.getX() - ((l + 1) * 1)) && (this->coordinates.getX() - ((l + 1) * 1)) <= 7)
				&& ((0 <= this->coordinates.getY() + ((l + 1) * 1)) && (this->coordinates.getY() + ((l + 1) * 1) <= 7)))
			{
				*distancia = l;
				return true;
			}
		}

		else if (findNumPeca(&(*pieceJog1), this->coordinates.getX() - (l * 1), this->coordinates.getY() + (l * 1)) != -1)
			l = moveCasasMax - 1;

		l++;
	} while (l < moveCasasMax);

	return false;
}


bool PIECE::kingCaptureRight_Down(PIECE* pieceJog1, PIECE* pieceJog2, int moveCasasMax, int* distancia)
{
	int l = 1;

	//verifies down-right capture for king.
	do
	{

		if (findNumPeca(&(*pieceJog1), this->coordinates.getX() + (l * 1), this->coordinates.getY() - (l * 1)) != -1)
		{
			if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() + ((l + 1) * 1), this->coordinates.getY() - ((l + 1) * 1)) == -1)
				&& (findNumPeca(&(*pieceJog2), this->coordinates.getX() + ((l + 1) * 1), this->coordinates.getY() - ((l + 1) * 1)) == -1)
				&& ((0 <= this->coordinates.getX() + ((l + 1) * 1)) && (this->coordinates.getX() + ((l + 1) * 1)) <= 7)
				&& ((0 <= this->coordinates.getY() - ((l + 1) * 1)) && (this->coordinates.getY() - ((l + 1) * 1) <= 7)))
			{
				*distancia = l;
				return true;
			}
		}

		else if (findNumPeca(&(*pieceJog1), this->coordinates.getX() + (l * 1), this->coordinates.getY() - (l * 1)) != -1)
			l = moveCasasMax - 1;

		l++;
	} while (l < moveCasasMax);
	
	return false;
}

bool PIECE::kingCaptureLeft_Down(PIECE* pieceJog1, PIECE* pieceJog2, int moveCasasMax, int* distancia)
{
	int l = 1;

	//verifies down-left capture for king.
	do
	{
		if (findNumPeca(&(*pieceJog1), this->coordinates.getX() - (l * 1), this->coordinates.getY() - (l * 1)) != -1)
		{
			if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() - ((l + 1) * 1), this->coordinates.getY() - ((l + 1) * 1)) == -1)
				&& (findNumPeca(&(*pieceJog2), this->coordinates.getX() - ((l + 1) * 1), this->coordinates.getY() - ((l + 1) * 1)) == -1)
				&& ((0 <= this->coordinates.getX() - ((l + 1) * 1)) && (this->coordinates.getX() - ((l + 1) * 1)) <= 7)
				&& ((0 <= this->coordinates.getY() - ((l + 1) * 1)) && (this->coordinates.getY() - ((l + 1) * 1) <= 7)))
			{
				*distancia = l;
				return true;
			}
		}

		else if (findNumPeca(&(*pieceJog1), this->coordinates.getX() - (l * 1), this->coordinates.getY() - (l * 1)) != -1)
			l = moveCasasMax - 1;
		
		l++;
	} while (l < moveCasasMax);

	return false;
}


int findNumPeca(PIECE* piece, int x, int y)
{
	int i;

	for (i = 0; i < 12; i++)
	{
		if ((piece[i].coordinates.getX() == x) &&
			(piece[i].coordinates.getY() == y))
			return i;
	}
	return -1;
}


bool PIECE::doesCaptureExist(PIECE* pieceJog1, PIECE* pieceJog2)
{
	int moveCasasX = 0, moveCasasY = 0, moveCasasMax = 0, l = 1;

	if (this->getIsKing()) //if the piece is king.
	{
		//upper-right move.
		moveCasasX = abs(7 - this->coordinates.getX());
		moveCasasY = abs(7 - this->coordinates.getY());

		if (moveCasasX >= moveCasasY)
			moveCasasMax = moveCasasY;
		else
			moveCasasMax = moveCasasX;

		if (this->kingCaptureRight_Up(&(*pieceJog1), &(*pieceJog2), moveCasasMax, &l))
			return true;


		//upper-left move.
		moveCasasX = abs(0 - this->coordinates.getX());
		moveCasasY = abs(7 - this->coordinates.getY());

		if (moveCasasX >= moveCasasY)
			moveCasasMax = moveCasasY;
		else
			moveCasasMax = moveCasasX;

		if (this->kingCaptureLeft_Up(&(*pieceJog1), &(*pieceJog2), moveCasasMax, &l))
			return true;


		//down-right move.
		moveCasasX = abs(7 - this->coordinates.getX());
		moveCasasY = abs(0 - this->coordinates.getY());

		if (moveCasasX >= moveCasasY)
			moveCasasMax = moveCasasY;
		else
			moveCasasMax = moveCasasX;

		if (this->kingCaptureRight_Down(&(*pieceJog1), &(*pieceJog2), moveCasasMax, &l))
			return true;


		//down-left move.
		moveCasasX = abs(0 - this->coordinates.getX());
		moveCasasY = abs(0 - this->coordinates.getY());

		if (moveCasasX >= moveCasasY)
			moveCasasMax = moveCasasY;
		else
			moveCasasMax = moveCasasX;

		if (this->kingCaptureLeft_Down(&(*pieceJog1), &(*pieceJog2), moveCasasMax, &l))
			return true;

	}
	else //if the piece is a man.
	{

		if (this->getSymbol() == 'O')
		{
			//upper-right capture.
			if (this->manCaptureRight_Up(&(*pieceJog1), &(*pieceJog2)))
				return true;

			//upper-left capture.
			if (this->manCaptureLeft_Up(&(*pieceJog1), &(*pieceJog2)))
				return true;
		}
		else 
		{
			//down-right capture.
			if (this->manCaptureRight_Down(&(*pieceJog1), &(*pieceJog2)))
				return true;

			//down-left capture
			if (this->manCaptureLeft_Down(&(*pieceJog1), &(*pieceJog2)))
				return true;
		}
	}
	return false;
}


bool PIECE::doesItCapture(int xf, int yf, PIECE* pieceJog1, PIECE* pieceJog2, int* numCaptured, int* xCaptured, int* yCaptured)
{
	int moveCasasMax = 0, l = 0, horizontalSinal = 0, verticalSinal = 0, freeAfter = 1, flag = 0;


	if (this->isKing == false) //if it is a man.
	{
		if (this->getSymbol() == 'O')
		{
			if ((xf == this->coordinates.getX() + 2) && (yf == this->coordinates.getY() + 2))
			{
				if (this->manCaptureRight_Up(&(*pieceJog1), &(*pieceJog2)))
				{
					*xCaptured = this->coordinates.getX() + 1;
					*yCaptured = this->coordinates.getY() + 1;
					*numCaptured = findNumPeca(&(*pieceJog2), this->coordinates.getX() + 1, this->coordinates.getY() + 1);
					return true;
				}
			}

			if ((xf == this->coordinates.getX() - 2) && (yf == this->coordinates.getY() + 2))
			{
				if (this->manCaptureLeft_Up(&(*pieceJog1), &(*pieceJog2)))
				{
					*xCaptured = this->coordinates.getX() - 1;
					*yCaptured = this->coordinates.getY() + 1;
					*numCaptured = findNumPeca(&(*pieceJog2), this->coordinates.getX() - 1, this->coordinates.getY() + 1);
					return true;
				}
			}
		}
		else //if it is a "X" piece playing.
		{

			if ((xf == this->coordinates.getX() + 2) && (yf == this->coordinates.getY() - 2))
			{
				if (this->manCaptureRight_Down(&(*pieceJog1), &(*pieceJog2)))
				{
					*xCaptured = this->coordinates.getX() + 1;
					*yCaptured = this->coordinates.getY() - 1;
					*numCaptured = findNumPeca(&(*pieceJog2), this->coordinates.getX() + 1, this->coordinates.getY() - 1);
					return true;
				}
			}

			if ((xf == this->coordinates.getX() - 2) && (yf == this->coordinates.getY() - 2))
			{
				if (this->manCaptureLeft_Down(&(*pieceJog1), &(*pieceJog2)))
				{
					*xCaptured = this->coordinates.getX() - 1;
					*yCaptured = this->coordinates.getY() - 1;
					*numCaptured = findNumPeca(&(*pieceJog2), this->coordinates.getX() - 1, this->coordinates.getY() - 1);
					return true;
				}
			}
		}
	}
	else //if it is a king.
	{

		horizontalSinal = this->coordinates.getX() - xf;
		verticalSinal = this->coordinates.getY() - yf;

		/*if the number of squares that it moves horizontally and vertically is different, then we are
		certain that the piece doesn't move diagonally (which is invalid)*/
		if (abs(horizontalSinal) != abs(verticalSinal))
			return false;
		else
			moveCasasMax = abs(horizontalSinal);


		if ((horizontalSinal < 0) && (verticalSinal < 0))
		{
			if (this->kingCaptureRight_Up(&(*pieceJog1), &(*pieceJog2), moveCasasMax, &l))
			{
				*xCaptured = this->coordinates.getX() + (l * 1);
				*yCaptured = this->coordinates.getY() + (l * 1);
				*numCaptured = (findNumPeca(&(*pieceJog2), this->coordinates.getX() + (l * 1), this->coordinates.getY() + (l * 1)));

				//verifies if the squares between the captured piece and the destination-position is free.
				do
				{
					if ((findNumPeca(&(*pieceJog1), *xCaptured + freeAfter, *yCaptured + freeAfter) != -1)
						&& (findNumPeca(&(*pieceJog2), *xCaptured + freeAfter, *yCaptured + freeAfter) != -1))
					{
						flag = 1;
						break;
					}
					freeAfter++;
				} while (freeAfter <= (moveCasasMax - l));
			}
		}
		else if ((horizontalSinal > 0) && (verticalSinal < 0))
		{
			if (this->kingCaptureLeft_Up(&(*pieceJog1), &(*pieceJog2), moveCasasMax, &l))
			{
				*xCaptured = this->coordinates.getX() - (l * 1);
				*yCaptured = this->coordinates.getY() + (l * 1);
				*numCaptured = (findNumPeca(&(*pieceJog2), this->coordinates.getX() - (l * 1), this->coordinates.getY() + (l * 1)));

				do
				{
					if ((findNumPeca(&(*pieceJog1), *xCaptured - freeAfter, *yCaptured + freeAfter) != -1)
						&& (findNumPeca(&(*pieceJog2), *xCaptured - freeAfter, *yCaptured + freeAfter) != -1))
					{
						flag = 1;
						break;
					}
					freeAfter++;
				} while (freeAfter <= (moveCasasMax - l));
			}
		}
		else if ((horizontalSinal < 0) && (verticalSinal > 0))
		{
			if (this->kingCaptureRight_Down(&(*pieceJog1), &(*pieceJog2), moveCasasMax, &l))
			{
				*xCaptured = this->coordinates.getX() + (l * 1);
				*yCaptured = this->coordinates.getY() - (l * 1);
				*numCaptured = (findNumPeca(&(*pieceJog2), this->coordinates.getX() + (l * 1), this->coordinates.getY() - (l * 1)));

				do
				{
					if ((findNumPeca(&(*pieceJog1), *xCaptured + freeAfter, *yCaptured - freeAfter) != -1)
						&& (findNumPeca(&(*pieceJog2), *xCaptured + freeAfter, *yCaptured - freeAfter) != -1))
					{
						flag = 1;
						break;
					}
					freeAfter++;
				} while (freeAfter <= (moveCasasMax - l));
			}
		}
		else if ((horizontalSinal > 0) && (verticalSinal > 0))
		{
			if (this->kingCaptureLeft_Down(&(*pieceJog1), &(*pieceJog2), moveCasasMax, &l))
			{
				*xCaptured = this->coordinates.getX() - (l * 1);
				*yCaptured = this->coordinates.getY() - (l * 1);
				*numCaptured = (findNumPeca(&(*pieceJog2), this->coordinates.getX() - (l * 1), this->coordinates.getY() - (l * 1)));

				do
				{
					if ((findNumPeca(&(*pieceJog1), *xCaptured - freeAfter, *yCaptured - freeAfter) != -1)
						&& (findNumPeca(&(*pieceJog2), *xCaptured - freeAfter, *yCaptured - freeAfter) != -1))
					{
						flag = 1;
						break;
					}
					freeAfter++;
				} while (freeAfter <= (moveCasasMax - l));
			}
		}

		if (flag == 0)
			return true;
	}
	return false;
}


bool PIECE::isMoveValidwithout(int xf, int yf, PIECE* pieceJog1, PIECE* pieceJog2)
{
	int moveSquaresX = 0, moveSquaresY = 0, i = 1, verticalSinal = 0, horizontalSinal = 0;

	if (this->isKing == false) //if the piece is a man.
	{
		if (this->getSymbol() == 'O')
		{
			if (((xf == this->coordinates.getX() + 1) || (xf == this->coordinates.getX() - 1)) && (yf == this->coordinates.getY() + 1))
				return true;
		}
		else
		{
			if (((xf == this->coordinates.getX() + 1) || (xf == this->coordinates.getX() - 1)) && (yf == this->coordinates.getY() - 1))
				return true;
		}
	}
	else //se a peça é uma dama.
	{
		/*
			if horizontalSinal > 0, the piece moves to the left. 
			if horizontalSinal < 0, the piece moves to the right.

			Se verticalSinal > 0, the piece moves down.
			Se verticalSinal < 0, the piece moves up.
		*/

		horizontalSinal = this->coordinates.getX() - xf;
		verticalSinal = this->coordinates.getY() - yf;

		//counts how many squares the player wants to move the king (it will be the same in the vertical and in the horizontal).
		moveSquaresX = abs(horizontalSinal);
		moveSquaresY = abs(verticalSinal);

		//if it is a diagonally move, it need to moves as many squares in the horizontal as in the vertical.
		if (moveSquaresX != moveSquaresY)
			return false;

		//verify, square by square, if the squares that the king moves till the destination are free.
		if ((horizontalSinal > 0) && (verticalSinal > 0))
		{
			do
			{
				if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() - (i * 1), this->coordinates.getY() - (i * 1)) != -1)
					|| (findNumPeca(&(*pieceJog2), this->coordinates.getX() - (i * 1), this->coordinates.getY() - (i * 1)) != -1))
					return false;

				i++;
			} while (i < moveSquaresX);
			return true;
		}
		else if ((horizontalSinal < 0) && (verticalSinal > 0))
		{
			do
			{
				if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() + (i * 1), this->coordinates.getY() - (i * 1)) != -1)
					|| (findNumPeca(&(*pieceJog2), this->coordinates.getX() + (i * 1), this->coordinates.getY() - (i * 1)) != -1))
					return false;

				i++;
			} while (i < moveSquaresX);
			return true;
		}
		else if ((horizontalSinal > 0) && (verticalSinal < 0))
		{
			do
			{
				if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() + (i * 1), this->coordinates.getY() + (i * 1)) != -1)
					|| (findNumPeca(&(*pieceJog2), this->coordinates.getX() + (i * 1), this->coordinates.getY() + (i * 1)) != -1))
					return false;

				i++;
			} while (i < moveSquaresX);
			return true;
		}
		else if ((horizontalSinal < 0) && (verticalSinal < 0))
		{
			do
			{
				if ((findNumPeca(&(*pieceJog1), this->coordinates.getX() + (i * 1), this->coordinates.getY() + (i * 1)) != -1)
					|| (findNumPeca(&(*pieceJog2), this->coordinates.getX() + (i * 1), this->coordinates.getY() + (i * 1)) != -1))
					return false;

				i++;
			} while (i < moveSquaresX);
			return true;
		}
	}
	return false;
}


bool PIECE::didItTurnKing(void)
{
	if (this->getSymbol() == 'O')
	{
		if (this->coordinates.getY() == 7)
		{
			this->setKing();
			return true;
		}
	}
	else
	{
		if (this->coordinates.getY() == 0)
		{
			this->setKing();
			return true;
		}
	}
	return false;
}


void PIECE::piecesSaveFile(ofstream &os)
{
	int i;

	if (!os)
		return;

	os << this->coordinates.getX() << "," << this->coordinates.getY() << ";" << this->getIsOnGame() << ";" << this->getIsKing() << ";";
	os << endl;
}


void PIECE::piecesReadFile(ifstream &is)
{
	char aux[100];
	int coor_x, coor_y, isongame, isqueen;

	is.getline(aux, sizeof(aux), ',');
	coor_x = atoi(aux);
	this->coordinates.setX(coor_x);
		
	is.getline(aux, sizeof(aux), ';');
	coor_y = atoi(aux);
	this->coordinates.setY(coor_y);

	is.getline(aux, sizeof(aux), ';');
	isongame = atoi(aux);
	if (isongame == 0)
		this->setOutGame();
	else
		this->setOnGame();

	is.getline(aux, sizeof(aux), ';');
	isqueen = atoi(aux);
	if (isqueen == 1)
		this->setKing();
	else
		this->setNotKing();
}
