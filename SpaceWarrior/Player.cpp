#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	this->setName("player");
	this->anim.sprite.scale(100, 100);
}

void Player::update()
{
}

void Player::playerMoveRight()
{
	this->x += speed;
	if (this->x >= W) this->x = W;
}

void Player::playerMoveLeft()
{
	this->x -= speed;
	if (this->x <= 0) this->x = 0;
}

Player::~Player()
{
}
