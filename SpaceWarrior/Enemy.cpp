#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	movment.x =rand()% 2 - 0.7f;
	movment.y =  1;
	name = "enemy";
}

void Enemy::update()
{
	this->position.x += movment.x;
	this->position.y += movment.y;
	if (position.y > H) this->life = false;
}



Enemy::~Enemy()
{
}
