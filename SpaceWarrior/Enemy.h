#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
private:
	int NextShotTime;
	int ShotDelay;
public:
	int CurrentTime;
	Enemy();
	void update();
	Bullet* LaserOfDamnation();
	~Enemy();
};

