#include "BOARD.h"

BOARD::BOARD()
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			position[i][j].occupied = false;
			position[i][j].p.setX(0 + (j * 1));
			position[i][j].p.setY(7 - (i * 1));
		}
	}
}

BOARD::~BOARD()
{
}

void BOARD::newGameOccupyPos(void)
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (((i == 0) || ((i % 2) == 0)) && ((i < 3) || (i > 4)))
			{
				if ((j % 2) != 0)
				{
					position[i][j].occupied = true;
				}
			}
			else if (((i % 2) != 0) && ((i < 3) || (i > 4)))
			{
				if ((j == 0) || ((j % 2) == 0))
				{
					position[i][j].occupied = true;
				}
			}
		}
	}
}

void BOARD::drawBoard(void)
{
	int i, squares=3;

	for (i = 0; i < 33; i++)
	{
		gotoxy(12, 2 + i);

		if (squares == 3)
		{
			squares = 0;
			cout << "-----------------------------------------------------------------";
		}
		else
		{
			cout << "|       |       |       |       |       |       |       |       |";
			squares++;
		}
	}

	gotoxy(10, 4);
	cout << "8";
	gotoxy(10, 8);
	cout << "7";
	gotoxy(10, 12);
	cout << "6";
	gotoxy(10, 16);
	cout << "5";
	gotoxy(10, 20);
	cout << "4";
	gotoxy(10, 24);
	cout << "3";
	gotoxy(10, 28);
	cout << "2";
	gotoxy(10, 32);
	cout << "1";
	gotoxy(10, 35);
	cout << "      a       b       c       d       e       f       g       h";
}

int BOARD::findNumSquare(int *num_x, int *num_y, int x, int y)
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((position[i][j].p.getX() == x) && (position[i][j].p.getY() == y))
			{
				*num_x = j;
				*num_y = i;
				return 0;
			}
		}
	}
	return 1;
}

bool BOARD::isPosFree(int coor_x, int coor_y)
{
	if (position[coor_y][coor_x].occupied == false)
		return true;
	else
		return false;
}

void BOARD::freePosition(int coor_x, int coor_y) 
{
	position[coor_y][coor_x].occupied = false;
}

void BOARD::occupyPosition(int coor_x, int coor_y) 
{
	position[coor_y][coor_x].occupied = true;
}

void BOARD::SaveFile(ofstream &os)
{
	int i, j;

	position[0][0].occupied = 0;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			os << i << "-" << j << ":" << position[i][j].occupied << ";" << endl;
	}
}

void BOARD::ReadFile(ifstream &is)
{
	int i=0, j=0;
	char aux[150];
	int occupied;

	if (!is)
		return;

	while (!is.eof())
	{
		is.getline(aux, sizeof(aux), '-');

		is.getline(aux, sizeof(aux), ':');

		is.getline(aux, sizeof(aux), ';');
		occupied = atoi(aux);

		if (occupied == 1)
		{
			position[i][j].occupied = 1;
		}
		else
		{
			position[i][j].occupied = 0;
		}

		j++;

		if (j == 8)
		{
			i++;
			j = 0;
			
			if (i == 8)
				break;
		}
	}
}

void BOARD::imprime(void)
{
	int i, j;

	clear();
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			cout << position[j][i].occupied << endl;
	}
	system("pause");
}