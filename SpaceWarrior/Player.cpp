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
{//MOZLIWE BLEDY
	this->position.x += speed;
	if (this->position.x <= 0) this->position.x = 0;
	else if (this->position.x >= W) this->position.x = W;
}

void Player::setAnimation(Animation newAnim)
{
	this->anim = newAnim;
}

Bullet* Player::DefaultShot()
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	Bullet *b = new Bullet();
	b->settings(*mapOfAnimation->Animacje["bulletBlue"], this->position.x, this->position.y, this->angle, 10);
	return b;
}

Player::~Player()
{
}
