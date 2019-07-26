#include "POINT.h"

PONTO::PONTO()
{
	this->x = 1;
	this->y = 1;
}

PONTO::PONTO(int m_x, int m_y)
{
	this->x = m_x;
	this->y = m_y;
}

PONTO::~PONTO()
{
}

void PONTO::setX(int m_x)
{
	this->x = m_x;
}

void PONTO::setY(int m_y)
{
	this->y = m_y;
}

int PONTO::getX(void) const
{
	return this->x;
}

int PONTO::getY(void) const
{
	return this->y;
}

