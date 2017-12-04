#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	name = "player";
}

void Player::update()
{
	if (thrust)
	{
		dx += cos(angle*DEGTORAD)*0.2;
		dy += sin(angle*DEGTORAD)*0.2;
	}
	else
	{
		dx *= 0.99;
		dy *= 0.99;
	}

	int maxSpeed = 15;
	float speed = sqrt(dx*dx + dy*dy);
	if (speed>maxSpeed)
	{
		dx *= maxSpeed / speed;
		dy *= maxSpeed / speed;
	}

	x += dx;
	y += dy;

	if (x>W) x = 0; if (x<0) x = W;
	if (y>H) y = 0; if (y<0) y = H;
}

Player::~Player()
{
}
