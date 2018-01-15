#include "stdafx.h"


Asteroid::Asteroid()
{
	movment.x = rand() % 3 - 1.5;
	movment.y = rand() % 2 + 0.7;
	name = "asteroid";
}

void  Asteroid::update()
{
	// warunki utrzymujace asteroidy "na torze"
	this->position.x += movment.x;
	this->position.y += movment.y;
	if (position.x > W) this->position.x = 0;
	else if (position.x < 0) this->position.x = W;
	if (position.y > H) this->life = false;
	if (position.y < 0) this->movment.y = -movment.y;
}

Asteroid::~Asteroid()
{
}
