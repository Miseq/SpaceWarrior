// SpaceWarrior.cpp : Defines the entry point for the console application.
#include "stdafx.h"

using namespace std;

bool isCollide(Entity &a, Entity &b);
void NewAsteroids(list <Entity*>& entities);
void UpdateOfStatus(list <Entity*> &entities);
void EndingExpolsion(list <Entity*> &entities);
void PlayerMoving(Player & p);

using namespace sf;

int shotDealy = 1.2, currentShot = 0, nextShot = 2;


int main()
{
	RenderWindow app(VideoMode(W, H), "Space Warrior v2.0");
	app.setFramerateLimit(60);
	
	Texture t2;
	t2.loadFromFile("assets/background.png");
	t2.setSmooth(true);
	Sprite background(t2);
	
	std::list<Entity*> entities; //lista jednostek w grze
	
	Singleton *mapOfAnimation = Singleton::getInstance(); // słownik animacji

	Player *p = new Player();
	p->settings(*mapOfAnimation->Animacje["playerPostionDefaul"], 600, 700, -90, 20);
	entities.push_back(p);

	//główna pętla
	while (app.isOpen())	
	{
		
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
						Bullet *b = new Bullet();
						b->settings(*mapOfAnimation->Animacje["bulletBlue"], p->x, p->y, p->angle, 10);
						entities.push_back(b);
				}
				
			}

		}

		PlayerMoving(*p);

		for (auto a : entities)
			for (auto b : entities)
			{
				if (a->name == "asteroid" && b->name == "bullet")
					if (isCollide(*a, *b))
					{
						a->life = false;
						b->life = false;

						Entity *e = new Entity();
						e->settings(*mapOfAnimation->Animacje["asteroidExplosion"], a->x, a->y);
						e->name = "explosion";
						entities.push_back(e);


						for (int i = 0; i<(rand()%3); i++)
						{
							if (a->R ==15 ) continue;
							Entity *e = new Asteroid();
							e->settings(*mapOfAnimation->Animacje["rockSmall"], a->x, a->y, rand() % 360, 15);
							entities.push_back(e);
						}

					}

				if (a->name == "player" && b->name == "asteroid")
					if (isCollide(*a, *b))
					{
						b->life = false;

						Entity *e = new Entity();
						e->settings(*mapOfAnimation->Animacje["shipExplosion"], a->x, a->y);
						e->name = "explosion";
						entities.push_back(e);

						p->settings(*mapOfAnimation->Animacje["playerPostionDefaul"], 600, 700, -90, 20);
					}
			}


		for (auto e : entities)
			if (e->name == "explosion")
				if (e->anim.isEnd()) e->life = 0;

		EndingExpolsion(entities);
		NewAsteroids(entities);
		UpdateOfStatus(entities);


		//////draw//////
		app.draw(background);

		for (auto i : entities)
			i->draw(app);

		app.display();
		app.clear();
	}

	return 0;
}

using namespace std;

bool isCollide(Entity &a, Entity &b)
{
	return (b.x - a.x)*(b.x - a.x) +
		(b.y - a.y)*(b.y - a.y)<
		(a.R + b.R)*(a.R + b.R);
}
void NewAsteroids(list <Entity*>& entities) // TODO konstruktor kopiujący na asteroidy
{
	int numberOfAsteroids = 30;
	Singleton *mapOfAnimation = Singleton::getInstance();
	if (rand() % numberOfAsteroids == 0) 
	{
		Asteroid *a = new Asteroid();
		a->settings(*mapOfAnimation->Animacje["rockDefault"], rand() % W, 0, rand() % 360, 25);
		entities.push_back(a);
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
