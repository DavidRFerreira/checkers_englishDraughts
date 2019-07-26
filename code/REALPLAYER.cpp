#include "REALPLAYER.h"



REALPLAYER::REALPLAYER()
{
}


REALPLAYER::~REALPLAYER()
{
}


void REALPLAYER::askSourcePosition(int* x, int* y)
{
	string coordinate;

	cout << ">Insert the coordinate of the piece you want to move (in the same format as a2): ";
	cin >> coordinate;


	translateToInt(coordinate, &(*x), &(*y));
}


void REALPLAYER::askDestinationPosition(int* x, int* y)
{
	string coordenada;

	cout << ">Insert the coordinate to where you want to move the piece (in the format as a2): ";
	cin >> coordenada;

	translateToInt(coordenada, &(*x), &(*y));
}


void REALPLAYER::translateToInt(string coordinate, int* x, int* y)
{
	if (coordinate == "a1") { *x = 0; *y = 0; }
	else if (coordinate == "a2") { *x = 0; *y = 1; }
	else if (coordinate == "a3") { *x = 0; *y = 2; }
	else if (coordinate == "a4") { *x = 0; *y = 3; }
	else if (coordinate == "a5") { *x = 0; *y = 4; }
	else if (coordinate == "a6") { *x = 0; *y = 5; }
	else if (coordinate == "a7") { *x = 0; *y = 6; }
	else if (coordinate == "a8") { *x = 0; *y = 7; }
	else if (coordinate == "b1") { *x = 1; *y = 0; }
	else if (coordinate == "b2") { *x = 1; *y = 1; }
	else if (coordinate == "b3") { *x = 1; *y = 2; }
	else if (coordinate == "b4") { *x = 1; *y = 3; }
	else if (coordinate == "b5") { *x = 1; *y = 4; }
	else if (coordinate == "b6") { *x = 1; *y = 5; }
	else if (coordinate == "b7") { *x = 1; *y = 6; }
	else if (coordinate == "b8") { *x = 1; *y = 7; }
	else if (coordinate == "c1") { *x = 2; *y = 0; }
	else if (coordinate == "c2") { *x = 2; *y = 1; }
	else if (coordinate == "c3") { *x = 2; *y = 2; }
	else if (coordinate == "c4") { *x = 2; *y = 3; }
	else if (coordinate == "c5") { *x = 2; *y = 4; }
	else if (coordinate == "c6") { *x = 2; *y = 5; }
	else if (coordinate == "c7") { *x = 2; *y = 6; }
	else if (coordinate == "c8") { *x = 2; *y = 7; }
	else if (coordinate == "d1") { *x = 3; *y = 0; }
	else if (coordinate == "d2") { *x = 3; *y = 1; }
	else if (coordinate == "d3") { *x = 3; *y = 2; }
	else if (coordinate == "d4") { *x = 3; *y = 3; }
	else if (coordinate == "d5") { *x = 3; *y = 4; }
	else if (coordinate == "d6") { *x = 3; *y = 5; }
	else if (coordinate == "d7") { *x = 3; *y = 6; }
	else if (coordinate == "d8") { *x = 3; *y = 7; }
	else if (coordinate == "e1") { *x = 4; *y = 0; }
	else if (coordinate == "e2") { *x = 4; *y = 1; }
	else if (coordinate == "e3") { *x = 4; *y = 2; }
	else if (coordinate == "e4") { *x = 4; *y = 3; }
	else if (coordinate == "e5") { *x = 4; *y = 4; }
	else if (coordinate == "e6") { *x = 4; *y = 5; }
	else if (coordinate == "e7") { *x = 4; *y = 6; }
	else if (coordinate == "e8") { *x = 4; *y = 7; }
	else if (coordinate == "f1") { *x = 5; *y = 0; }
	else if (coordinate == "f2") { *x = 5; *y = 1; }
	else if (coordinate == "f3") { *x = 5; *y = 2; }
	else if (coordinate == "f4") { *x = 5; *y = 3; }
	else if (coordinate == "f5") { *x = 5; *y = 4; }
	else if (coordinate == "f6") { *x = 5; *y = 5; }
	else if (coordinate == "f7") { *x = 5; *y = 6; }
	else if (coordinate == "f8") { *x = 5; *y = 7; }
	else if (coordinate == "g1") { *x = 6; *y = 0; }
	else if (coordinate == "g2") { *x = 6; *y = 1; }
	else if (coordinate == "g3") { *x = 6; *y = 2; }
	else if (coordinate == "g4") { *x = 6; *y = 3; }
	else if (coordinate == "g5") { *x = 6; *y = 4; }
	else if (coordinate == "g6") { *x = 6; *y = 5; }
	else if (coordinate == "g7") { *x = 6; *y = 6; }
	else if (coordinate == "g8") { *x = 6; *y = 7; }
	else if (coordinate == "h1") { *x = 7; *y = 0; }
	else if (coordinate == "h2") { *x = 7; *y = 1; }
	else if (coordinate == "h3") { *x = 7; *y = 2; }
	else if (coordinate == "h4") { *x = 7; *y = 3; }
	else if (coordinate == "h5") { *x = 7; *y = 4; }
	else if (coordinate == "h6") { *x = 7; *y = 5; }
	else if (coordinate == "h7") { *x = 7; *y = 6; }
	else if (coordinate == "h8") { *x = 7; *y = 7; }
}

void REALPLAYER::saveFile(ofstream& os)
{
	int i;

	if (!os)
		return;

	os << "R" << ";";
	os << getName() << "." << endl;

	for (i = 0; i < 12; i++)
		this->getPiece(i).piecesSaveFile(os);
}

