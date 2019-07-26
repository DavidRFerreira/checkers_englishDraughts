#include "BOTPLAYER.h"

BOTPLAYER::BOTPLAYER()
{
	this->setNameSymbol(1, "BOT");
}


BOTPLAYER::~BOTPLAYER()
{
}

void BOTPLAYER::randomPosition(int* x, int* y)
{
		*x = rand() % (7 - 0 + 1) + 0;
		*y = rand() % (7 - 0 + 1) + 0;	
}

void BOTPLAYER::saveFile(ofstream& os)
{
	int i;

	if (!os)
		return;

	os << "B" << ";";
	os << getName() << "." << endl;

	for (i = 0; i < 12; i++)
		this->getPiece(i).piecesSaveFile(os);
}

