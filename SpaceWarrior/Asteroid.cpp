#include "stdafx.h"


Asteroid::Asteroid()
{
	// dx - szybkosc poruszania w poziomie + prawo - lewo
	// dy - szybkosc porusznia w pionie, dodatnia w dol(numeracja pikseli rosnie w dol ekranu
	dx = rand() % 3 - 1.5;
	dy = rand() % 2 + 0.7;
	name = "asteroid";
}

void  Asteroid::update()
{
	// warunki utrzymujace asteroidy "na torze"
	this->x += dx;
	this->y += dy;
	if (x > W) this->x = 0;
	else if (x < 0) this->x = W;
	if (y > H) this->life = false;
	if (y < 0) this->dy = -dy;
}

Asteroid::~Asteroid()
{
}
