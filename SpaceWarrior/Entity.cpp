#include "stdafx.h"
#include "Entity.h"


Vector2f Entity::getPosition()
{
	return position;
}

Vector2f Entity::getMovment()
{
	return movment;
}

Animation& Entity::getAnimation()
{
	return anim;
}


int Entity::getLife()
{
	return life;
}

float Entity::getRadius()
{
	return R;
}

float Entity::getAngle()
{
	return angle;
}

std::string Entity::getName()
{
	return name;
}

void Entity::setMovment(Vector2f mov)
{
	movment.x = mov.x;
	movment.y = mov.y;
}

void Entity::setPosition(Vector2f position)
{
	this->position.x = position.x;
	this->position.y = position.y;
}

void Entity::setLife(int life)
{
	this->life = life;
}

void Entity::setRadius(float R)
{
	this->R = R;
}

void Entity::setAngle(float angle)
{
	this->angle = angle;
}

void Entity::setAnimation(Animation& anim)
{
	this->anim = anim;
}

Entity::Entity()
{
	name = "";
	life = 1;
}

void Entity::settings(Animation &a, int X, int Y, float Angle, int radius) 
{
	anim = a;
	position.x = X;
	position.y = Y;
	this->angle = Angle;
	R = radius;
}

void Entity::draw(RenderWindow &app) 
{
	anim.getSprite().setPosition(position.x, position.y);
	anim.getSprite().setRotation(angle + 90); // TODO usunaæ anim i animacje bo skoro dziedziczy to na chuj
	app.draw(anim.getSprite());

	CircleShape circle(R);
	circle.setFillColor(Color(255, 0, 0, 170));
	circle.setPosition(position.x, position.y);
	circle.setOrigin(R, R);
	//app.draw(circle);
}

Entity::~Entity()
{
}

void Entity::setName(std::string Name)
{
	this->name = Name;
}


