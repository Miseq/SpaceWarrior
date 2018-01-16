#pragma once
#include "Entity.h"
class Bullet : public Entity
{
	const float DEGTORAD = 0.017453f;
public:
	Bullet();
	~Bullet();
	virtual void  update();

};

