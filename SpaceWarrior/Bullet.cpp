#include "stdafx.h"


Bullet::Bullet()
{
	name = "bullet";
}

void  Bullet::update()
{
	movment.x = cos(angle*DEGTORAD) * 6;
	movment.y = sin(angle*DEGTORAD) * 6;
	// angle+=rand()%6-3;
	position.x += movment.x;
	position.y += movment.y;

	if (position.x>W || position.x<0 || position.y>H || position.y<0) life = 0;
}


Bullet::~Bullet()
{
}
