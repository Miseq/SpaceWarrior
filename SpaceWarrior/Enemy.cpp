#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	this->NextShotTime = 4;
	this->CurrentTime = 0;
	this->ShotDelay = 1;
	dx = 0;
	dy =  1;
	name = "enemy";
}

void Enemy::update()
{
	this->y += dy;
	if (y > H) this->life = false;
}

Bullet* Enemy::LaserOfDamnation()
{
	if (CurrentTime >= NextShotTime)
	{
		Singleton *mapOfAnimation = Singleton::getInstance();
		Bullet *e = new Bullet();
		e->settings(*mapOfAnimation->Animacje["bulletRed"], this->x, this->y, this->angle, 10);
		return e;
		CurrentTime = 0;
	}
	else
	{
		CurrentTime += ShotDelay;
		return nullptr;
	}
}

Enemy::~Enemy()
{
}
