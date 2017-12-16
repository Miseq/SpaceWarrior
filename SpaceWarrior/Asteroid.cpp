#include "stdafx.h"


Asteroid::Asteroid()
{
	dx = rand() % 8 - 4;
	dy = rand() % 2 + 1;
	name = "asteroid";
}

void  Asteroid::update()
{
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
