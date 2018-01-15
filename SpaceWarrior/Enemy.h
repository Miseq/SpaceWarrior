#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
	Clock * enemyTimer;
	Time * timeForChangeDirection;
public:
	Enemy();
	virtual void update();
	~Enemy();
};

