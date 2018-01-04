#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	this->setName("player");
	//this->anim.sprite.scale(100, 100);
	CorrectAngle = -90;
	DefaultWidthStart = W / 2;
	DefaulHeightStart = H - 100;
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
	return this->DefaulHeightStart;
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

Player::~Player()
{
}
