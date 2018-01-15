#include "stdafx.h"


Bullet::Bullet()
{
	name = "bullet";
}

void  Bullet::update()
{
	movment.x = cos(angle*DEGTORAD) * 6;
	movment.y = sin(angle*DEGTORAD) * 6;
	position.x += movment.x;
	position.y += movment.y;

	if (position.y>H || position.y<0) life = 0;
}


Bullet::~Bullet()
{
}
