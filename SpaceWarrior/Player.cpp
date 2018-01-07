#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	this->setName("player");
	//this->anim.sprite.scale(100, 100);
	this->CorrectAngle = -90;
	this->DefaultWidthStart = W / 2;
	this->DefaulHeightStart = H - 100;
}

int Player::getCorrectAngle()
{
	return this->CorrectAngle;
}

int Player::getDefaulHeightStart()
{
	return this->DefaulHeightStart;
}

int Player::getDefaultWidthStart()
{
	return this->DefaultWidthStart;
}

void Player::update()
{
}


void Player::playerMove(int speed )
{
	this->x += speed;
	if (this->x <= 0) this->x = 0;
	else if (this->x >= W) this->x = W;
}

void Player::setAnimation(Animation newAnim)
{
	this->anim = newAnim;
}

Bullet* Player::DefaultShot()
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	Bullet *b = new Bullet();
	b->settings(*mapOfAnimation->Animacje["bulletBlue"], this->x, this->y, this->angle, 10);
	return b;
}

Player::~Player()
{
}
