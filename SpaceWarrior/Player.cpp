#include "stdafx.h"
#include "Player.h"
#include <fstream>

Player::Player()
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	name = "player";
	this->CorrectAngle = -90;
	this->DefaultWidthStart = W / 2;
	this->DefaulHeightStart = H - 100;
	this->life = 3;
	
	nickname = "";

	int odstep = 0;
	for (int i = 0; i < this->life; i++)
	{
		Entity* heart = new Entity();
		heart->settings(*mapOfAnimation->Animacje["heart"], 500 + odstep, 20, -90);
		hearts.push_back(heart);
		odstep += 40;
	}
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

std::list<Entity*>& Player::getHearts()
{
	return hearts;
}

void Player::playerWasShooted()
{
	playerImmunity = 1;
	immunityTimer->restart();
	name = "";
}

void Player::endOfPlayerImmortalty()
{
	playerImmunity = 0;
	name = "player";
}

void Player::update()
{
}

int Player::playerDeath(RenderWindow& window)
{

	return 0;

}

int Player::getPlayerImmunity()
{
	return playerImmunity;
}

std::string Player::getNickname()
{
	return nickname;
}

Clock * Player::getImmunityTimer()
{
	return immunityTimer;
}

void Player::setNickname(std::string name)
{
	nickname = name;
}

void Player::setPlayerImmunity(int status)
{
	playerImmunity = status;
}

void Player::DestroyingHeart()
{
	hearts.erase(hearts.begin());
}

void Player::playerMove(int speed )
{
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

void Player::PlayerActions(std::list<Entity*> &entities, RenderWindow * app)
{

	Event gameEvent;
	while (app->pollEvent(gameEvent))
	{
		if (gameEvent.type == Event::KeyPressed)
		{

			*gameTime = Playertimer->getElapsedTime();
			if (gameEvent.key.code == Keyboard::Escape)
			{
				app->close();
			}

			if (Keyboard::isKeyPressed(Keyboard::LControl) && gameTime->asMilliseconds() >= 120)
			{
				Bullet *b = this->DefaultShot();
				entities.push_back(b);
				Playertimer->restart();
			}

		}

	}
	this->PlayerMoving();
}

void Player::PlayerMoving()
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		this->playerMove(3);
		this->setAnimation(*mapOfAnimation->Animacje["playerPositionRight"]);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		this->playerMove(-3);
		this->setAnimation(*mapOfAnimation->Animacje["playerPositionLeft"]);
	}
	else
	{
		this->setAnimation(*mapOfAnimation->Animacje["playerPostionDefaul"]);
	}
}