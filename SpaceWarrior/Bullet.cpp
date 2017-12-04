#include "stdafx.h"


Bullet::Bullet()
{
	name = "bullet";
}

void  Bullet::update()
{
	dx = cos(angle*DEGTORAD) * 6;
	dy = sin(angle*DEGTORAD) * 6;
	// angle+=rand()%6-3;
	x += dx;
	y += dy;

	if (x>W || x<0 || y>H || y<0) life = 0;
}


Bullet::~Bullet()
{
}
