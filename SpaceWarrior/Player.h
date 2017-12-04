#pragma once
#include "Entity.h"
class Player : Entity
{
public:
	bool thrust;
	void update();
	Player();
	~Player();
};

