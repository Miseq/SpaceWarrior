#pragma once
#include "Animation.h"
#include <string>
class Entity
{
public:	
	float x, y, dx, dy, R, angle;
	bool life;
	std::string name;
	Animation anim;
	Entity();
	void settings(Animation &a, int X, int Y, float Angle = 0, int radius = 1);
	virtual void update() {};
	void draw(RenderWindow &app);
	virtual ~Entity() {};
	Entity();
};

