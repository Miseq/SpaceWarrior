#include "stdafx.h"
#include "Singleton.h"



Singleton::Singleton()
{
	// Tworzenie serii obiektów typu Texture, do przechowywania grafiki
	Texture* defaultPlayerTexture = new Texture();
	Texture* MovingLeftPlayerTexture = new Texture();
	Texture* MovingRightPlayerTexture = new Texture();
	Texture* t2 = new Texture();
	Texture* t3 = new Texture();
	Texture* t4 = new Texture();
	Texture* t5 = new Texture();
	Texture* t6 = new Texture();
	Texture* t7 = new Texture();
	Texture* t8 = new Texture();
	Texture* t9 = new Texture();
	Texture* t10 = new Texture();

	// Za³adowanie tekstur z plików graficznych png
	defaultPlayerTexture->loadFromFile("assets/spaceassets.png");
	MovingLeftPlayerTexture->loadFromFile("assets/spaceassets.png");
	MovingRightPlayerTexture->loadFromFile("assets/spaceassets.png");
	t3->loadFromFile("./assets/explosions/type_A.png");
	t4->loadFromFile("./assets/rock.png");
	t5->loadFromFile("./assets/fire_blue.png");
	t6->loadFromFile("./assets/rock_small.png");
	t7->loadFromFile("./assets/explosions/type_B.png");
	t8->loadFromFile("./assets/alienspaceship.png");
	t9->loadFromFile("./assets/fire_red.png");
	t10->loadFromFile("./assets/heart.png");

	// setSmooth ustawia mniej kanciaste poruszanie siê obiektów po przestrzeni
	defaultPlayerTexture->setSmooth(true);
	t4->setSmooth(true);
	t5->setSmooth(true);
	t8->setSmooth(true);
	t9->setSmooth(true);

	
	// (wspo³rzêdne pocz¹tkowe wcianania x, y, rozmiar wyciêtego fragmentu x,y, iloœæ klatek, szybkoœæ zmiany klatki, skalowanie textury)
	Animation *sExplosion = new Animation(*t3, { 0, 0, 50, 50 }, 48, 0.5);
	Animation *sRock = new Animation(*t4, { 0, 0, 64, 64 }, 16, 0.25, { 0.9f,0.9f });
	Animation *sRock_small = new Animation(*t6, { 0, 0, 64, 64 }, 16, 0.25);
	Animation *sBullet = new Animation(*t5, { 0, 0, 32, 64 }, 16, 0.8);
	Animation *sPlayerDefault = new Animation(*defaultPlayerTexture, { 40, 40, 40, 40 }, 1, 0, { 1.3f,1.3f });
	Animation *sPlayerRight = new Animation(*MovingRightPlayerTexture, { 80, 40, 40, 40 }, 1, 0, { 1.3f,1.3f });
	Animation *sPlayerLeft = new Animation(*MovingLeftPlayerTexture, { 0, 40, 40, 40 }, 1, 0, { 1.3f,1.3f });
	Animation *sExplosion_ship = new Animation(*t7, { 0, 0, 192, 192 }, 64, 0.5);
	Animation *sAlienShip = new Animation(*t8, { 0,0, 320, 320 }, 1, 0, { 0.28f,0.28f });
	Animation *sEnemyBullet = new Animation(*t9, { 0, 0, 32, 64 }, 16, 0.8);
	Animation *sHeart = new Animation(*t10, { 0,0,331,309 }, 1, 0, { 0.1f,0.1f });
	// 
	this->Animacje;
	Animacje["asteroidExplosion"] = sExplosion;
	Animacje["rockDefault"] = sRock;
	Animacje["rockSmall"] = sRock_small;
	Animacje["bulletBlue"] = sBullet;
	Animacje["playerPostionDefaul"] = sPlayerDefault;
	Animacje["playerPositionRight"] = sPlayerRight;
	Animacje["playerPositionLeft"] = sPlayerLeft;
	Animacje["shipExplosion"] = sExplosion_ship;
	Animacje["alienShip"] = sAlienShip;
	Animacje["alienBulelt"] = sEnemyBullet;
	Animacje["heart"] = sHeart;
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

