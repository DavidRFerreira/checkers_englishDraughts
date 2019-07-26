#pragma once
#include "PLAYER.h"

class BOTPLAYER : public PLAYER
{
private:

public:
	BOTPLAYER();
	virtual ~BOTPLAYER();

	void randomPosition(int* x, int* y);

	virtual bool isThisABot(void) { return true; }

	virtual void saveFile(ofstream& os);
};

