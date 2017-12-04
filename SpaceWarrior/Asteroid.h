#pragma once
#include "Entity.h"
class Asteroid : protected Entity
{
public:
	Asteroid();
	~Asteroid();
	void  update();
};

