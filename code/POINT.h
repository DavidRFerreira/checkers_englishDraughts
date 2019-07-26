#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class PONTO
{
private:
	int x;
	int y;

public:
	PONTO();
	PONTO(int m_x, int m_y);
	virtual ~PONTO();

	void setX(int m_x);
	void setY(int m_y);
	int getX(void) const;
	int getY(void) const;
};

