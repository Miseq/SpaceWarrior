#include "stdafx.h"
#include "Singleton.h"



Singleton::Singleton()
{
	Texture* defaultPlayerTexture = new Texture();
	Texture* MovingLeftPlayerTexture = new Texture();
	Texture* MovingRightPlayerTexture = new Texture();
	Texture* t2 = new Texture();
	Texture* t3 = new Texture();
	Texture* t4 = new Texture();
	Texture* t5 = new Texture();
	Texture* t6 = new Texture();
	Texture* t7 = new Texture();

	defaultPlayerTexture->loadFromFile("assets/spaceassets.png");
	MovingLeftPlayerTexture->loadFromFile("assets/spaceassets.png");
	MovingRightPlayerTexture->loadFromFile("assets/spaceassets.png");
	t3->loadFromFile("assets/explosions/type_A.png");
	t4->loadFromFile("assets/rock.png");
	t5->loadFromFile("assets/fire_blue.png");
	t6->loadFromFile("assets/rock_small.png");
	t7->loadFromFile("assets/explosions/type_B.png");
	defaultPlayerTexture->setSmooth(true);
	t4->setSmooth(true);
	t5->setSmooth(true);
	
	// (wspo³rzêdne pocz¹tkowe wcianania x, y, rozmiar wyciêtego fragmentu x,y, iloœæ klatek, szybkoœæ zmiany klatki, skalowanie textury)
	Animation *sExplosion = new Animation(*t3, { 0, 0, 50, 50 }, 48, 0.5);
	Animation *sRock = new Animation(*t4, { 0, 0, 64, 64 }, 16, 0.25, { 0.9f,0.9f });
	Animation *sRock_small = new Animation(*t6, { 0, 0, 64, 64 }, 16, 0.25);
	Animation *sBullet = new Animation(*t5, { 0, 0, 32, 64 }, 16, 0.8);
	Animation *sPlayerDefault = new Animation(*defaultPlayerTexture, { 40, 40, 40, 40 }, 1, 0, { 1.3f,1.3f });
	Animation *sPlayerRight = new Animation(*MovingRightPlayerTexture, { 80, 40, 40, 40 }, 1, 0, { 1.3f,1.3f });
	Animation *sPlayerLeft = new Animation(*MovingLeftPlayerTexture, { 0, 40, 40, 40 }, 1, 0, { 1.3f,1.3f });
	Animation *sExplosion_ship = new Animation(*t7, { 0, 0, 192, 192 }, 64, 0.5);

	this->Animacje;
	Animacje["asteroidExplosion"] = sExplosion;
	Animacje["rockDefault"] = sRock;
	Animacje["rockSmall"] = sRock_small;
	Animacje["bulletBlue"] = sBullet;
	Animacje["playerPostionDefaul"] = sPlayerDefault;
	Animacje["playerPositionRight"] = sPlayerRight;
	Animacje["playerPositionLeft"] = sPlayerLeft;
	Animacje["shipExplosion"] = sExplosion_ship;


}

Singleton* Singleton::instance = 0;

Singleton * Singleton::getInstance()
{
	if (instance == 0)
	{
		instance = new Singleton();
	}
	return instance;
}


Singleton::~Singleton()
{
}

