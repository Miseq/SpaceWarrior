#include "stdafx.h"
#include "Enemy.h"




Enemy::Enemy()
{
	movment.x =rand()% 2 - 0.7f;
	movment.y =  1;
	name = "enemy";
	enemyTimer = new Clock;
	timeForChangeDirection = new Time;
}

void Enemy::update()
{
	if (timeForChangeDirection->asMilliseconds() >= rand() % 400 )
	{
		movment.x = -movment.x;
		enemyTimer->restart();
	}
	this->position.x += movment.x;
	this->position.y += movment.y;
	if (position.y > H) this->life = false;
	if (position.x > W || position.x < 0) movment.x = -movment.x;
}



Enemy::~Enemy()
{
}
