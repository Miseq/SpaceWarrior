#pragma once
#include "Animation.h"
#include <string>
class Entity : public Animation
{
protected:
	float R, angle;
	int life;
	Vector2f position;
	Vector2f movment;
	std::string name;
	Animation anim;
	
public:

	void setMovment(Vector2f mov = {0, 0});
	void setPosition(Vector2f position = {0, 0});
	void setLife(int life);
	void setRadius( float R);
	void setAngle(float angle);
	void setAnimation(Animation& anim);
	void setName(std::string Name);

	Vector2f getPosition();
	Vector2f getMovment();
	Animation& getAnimation();
	int getLife();
	float getRadius();
	float getAngle();
	std::string getName();

	Entity();
	void settings(Animation &a, int X, int Y, float Angle = 0 , int radius = 1 );
	virtual void update() {};
	virtual ~Entity();
	void draw(RenderWindow &app);
};

