#include "stdafx.h"
#include "MaintenceClass.h"


MaintenceClass::MaintenceClass()
{
	Texture background;
	background.loadFromFile("assets/background.png");
	background.setSmooth(true);
	this->background.setTexture(background);
}


MaintenceClass::~MaintenceClass()
{
}

list<Entity*>* MaintenceClass::getEntities()
{
	return &entities;
}

bool MaintenceClass::isCollide(Entity & a, Entity & b)
{
		return pow((b.getPosition().x - a.getPosition().x), 2) +
		pow((b.getPosition().y - a.getPosition().y), 2)
		<= pow((a.getRadius() + b.getRadius()), 2);;
}

void MaintenceClass::NewEnemies()
{
	int numberOfAsteroids = 40;
	int numberOfShips = 300;
	Singleton *mapOfAnimation = Singleton::getInstance();
	if (rand() % numberOfAsteroids == 0)
	{
		Asteroid *a = new Asteroid();
		a->settings(*mapOfAnimation->Animacje["rockDefault"], rand() % W, 0, rand() % 360, 25);
		entities.push_back(a);
	}
	if (rand() % numberOfShips == 0)
	{
		Enemy *e = new Enemy();
		e->settings(*mapOfAnimation->Animacje["alienShip"], rand() % W, 0, 90, 15);
		entities.push_back(e);
	}
}

void MaintenceClass::UpdateOfStatus()
{
	for (auto i = entities.begin(); i != entities.end();)
	{

		Entity *e = *i;

		e->update();
		e->getAnimation().update();

		if (e->getLife() == false) { i = entities.erase(i); delete e; }
		else i++;
	}
}

void MaintenceClass::EndingExpolsion()
{
	for (auto e : entities)
		if (e->getName() == "explosion")
			if (e->getAnimation().isEnd()) e->setLife(false);
}

Player * MaintenceClass::CreatingPLayer()
{
 	Singleton *mapOfAnimation = Singleton::getInstance();
	Player *p = new Player();
	p->settings(*mapOfAnimation->Animacje["playerPostionDefaul"], p->getDefaultWidthStart(), p->getDefaulHeightStart(), p->getCorrectAngle(), 20);
	entities.push_back(p);
	return p;;
}

void MaintenceClass::PlayerMoving(Player & p)
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		p.playerMove(3);
		p.setAnimation(*mapOfAnimation->Animacje["playerPositionRight"]);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		p.playerMove(-3);
		p.setAnimation(*mapOfAnimation->Animacje["playerPositionLeft"]);
	}
	else
	{
		p.setAnimation(*mapOfAnimation->Animacje["playerPostionDefaul"]);
	}
}

void MaintenceClass::Colisions( Player & p)
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	for (auto a : entities)
		for (auto b : entities)
		{
			if ((a->getName() == "asteroid" || a->getName() == "enemy") && b->getName() == "bullet")
				if (isCollide(*a, *b))
				{
					a->setLife(false);
					b->setLife(false);

					Entity *e = new Entity();
					e->settings(*mapOfAnimation->Animacje["asteroidExplosion"], a->getPosition().x, a->getPosition().y);
					e->setName("explosion");
					entities.push_back(e);


					for (int i = 0; i<(rand() % 3); i++)
					{
						if (a->getRadius() == 15) continue;
						Entity *e = new Asteroid();
						e->settings(*mapOfAnimation->Animacje["rockSmall"], a->getPosition().x, a->getPosition().y, rand() % 360, 15);
						entities.push_back(e);
					}

				}

			if (a->getName() == "player" && (b->getName() == "asteroid" || b->getName() == "enemy" || b->getName() == "enemybullet"))
				if (isCollide(*a, *b))
				{
					b->setLife(false);

					Entity *e = new Entity();
					e->settings(*mapOfAnimation->Animacje["shipExplosion"], a->getPosition().x, a->getPosition().y);
					e->setName("explosion");
					entities.push_back(e);

					p.settings(*mapOfAnimation->Animacje["playerPostionDefaul"], p.getDefaultWidthStart(), p.getDefaulHeightStart(), p.getCorrectAngle(), 20);
				}

		}
}

void MaintenceClass::PlayerActions(RenderWindow & app, Player & p)
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	Event gameEvent;
	while (app.pollEvent(gameEvent))
	{
		if (gameEvent.type == Event::KeyPressed)
		{
			app.setKeyRepeatEnabled(false);
			if (gameEvent.key.code == Keyboard::Escape)
			{
				app.close();
			}

			if (gameEvent.key.code == Keyboard::LControl)
			{
				Bullet *b = p.DefaultShot();
				entities.push_back(b);
			}

		}

	}
	PlayerMoving(p);
}

void MaintenceClass::EnemyShooting()
{
	*gameTime = timer->getElapsedTime();
	Singleton *mapOfAnimation = Singleton::getInstance();
	for (auto i : entities)
	{

		if (i->getName() == "enemy" && gameTime->asMilliseconds() >= 500)
		{
			Bullet *b = new Bullet;
			b->setName("enemybullet");
			b->settings(*mapOfAnimation->Animacje["alienBulelt"], i->getPosition().x, i->getPosition().y, i->getAngle(), 10);
			entities.push_back(b);
			timer->restart();
		}

	}
}

void MaintenceClass::Drawning(RenderWindow & window)
{
	window.draw(this->background);
	for (auto i : entities)	i->draw(window);
	window.display();
	window.clear();
}