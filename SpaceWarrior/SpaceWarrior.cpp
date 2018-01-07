// SpaceWarrior.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <cmath> // do kolizji

using namespace std;

bool isCollide(Entity &a, Entity &b);
void NewEnemies(list <Entity*>& entities);
void UpdateOfStatus(list <Entity*> &entities);
void EndingExpolsion(list <Entity*> &entities);
Player* CreatingPLayer(list <Entity*> &entities);
void PlayerMoving(Player & p);
void Colisions(list <Entity*> &entities, Player &p);
void PlayerActions(RenderWindow& app, list <Entity*> &entities, Player & p);
using namespace sf;


void main()
{
	RenderWindow app(VideoMode(W, H), "Space Warrior v2.0");
	app.setFramerateLimit(90);
	
	Texture t2;
	t2.loadFromFile("assets/background.png");
	t2.setSmooth(true);
	Sprite background(t2);
	
	std::list<Entity*> entities; //lista jednostek w grze
	
	Singleton *mapOfAnimation = Singleton::getInstance(); // słownik animacji
	Player *p = CreatingPLayer(entities);


	//główna pętla
	while (app.isOpen())	
	{
		PlayerActions(app, entities, *p);
		
		NewEnemies(entities);
		Colisions(entities, *p);	
		UpdateOfStatus(entities);
		EndingExpolsion(entities);
		//////draw/////
		app.draw(background);
		for (auto i : entities) i->draw(app);
		app.display();
		app.clear();
	}
}

using namespace std;

bool isCollide(Entity &a, Entity &b)
{
	return pow((b.x - a.x),2) +
		pow((b.y - a.y),2)<
		pow((a.R + b.R),2);
}

void NewEnemies(list <Entity*>& entities)
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

void UpdateOfStatus(list <Entity*> &entities)
{
	for (auto i = entities.begin(); i != entities.end();)
	{
		Entity *e = *i;

		e->update();
		e->anim.update();

		if (e->life == false) { i = entities.erase(i); delete e; }
		else i++;
	}
}

void EndingExpolsion(list <Entity*> &entities)
{
	for (auto e : entities)
		if (e->name == "explosion")
			if (e->anim.isEnd()) e->life = 0;
}

Player* CreatingPLayer(list<Entity*>& entities)
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	Player *p = new Player();
	p->settings(*mapOfAnimation->Animacje["playerPostionDefaul"], p->getDefaultWidthStart(), p->getDefaulHeightStart(), p->getCorrectAngle(), 0);
	entities.push_back(p);
	return p;
}

void PlayerMoving(Player & p)
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

void Colisions(list<Entity*>& entities, Player &p)
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	for (auto a : entities)
		for (auto b : entities)
		{
			if ((a->name == "asteroid" || a->name == "enemy") && b->name == "bullet")
				if (isCollide(*a, *b))
				{
					a->life = false;
					b->life = false;

					Entity *e = new Entity();
					e->settings(*mapOfAnimation->Animacje["asteroidExplosion"], a->x, a->y);
					e->name = "explosion";
					entities.push_back(e);


					for (int i = 0; i<(rand() % 3); i++)
					{
						if (a->R == 15) continue;
						Entity *e = new Asteroid();
						e->settings(*mapOfAnimation->Animacje["rockSmall"], a->x, a->y, rand() % 360, 15);
						entities.push_back(e);
					}

				}

			if (a->name == "player" && (b->name == "asteroid" || b->name =="enemy" || b->name== "enemybullet"))
				if (isCollide(*a, *b))
				{
					b->life = false;

					Entity *e = new Entity();
					e->settings(*mapOfAnimation->Animacje["shipExplosion"], a->x, a->y);
					e->name = "explosion";
					entities.push_back(e);

					p.settings(*mapOfAnimation->Animacje["playerPostionDefaul"], p.getDefaultWidthStart(), p.getDefaulHeightStart(), p.getCorrectAngle(), 20);
				}

		}
}

void PlayerActions(RenderWindow& app, list <Entity*> &entities, Player & p)
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

