// SpaceWarrior.cpp : Defines the entry point for the console application.
#include "stdafx.h"
using namespace sf;

bool isCollide(Entity *a, Entity *b);


int main()
{
	srand(time(0));

	RenderWindow app(VideoMode(W, H), "Asteroids!");
	app.setFramerateLimit(60);

	Texture t1, t2, t3, t4, t5, t6, t7;
	t1.loadFromFile("assets/spaceassets.png");
	t2.loadFromFile("assets/background.png");
	t3.loadFromFile("assets/explosions/type_C.png");
	t4.loadFromFile("assets/rock.png");
	t5.loadFromFile("assets/fire_blue.png");
	t6.loadFromFile("assets/rock_small.png");
	t7.loadFromFile("assets/explosions/type_B.png");

	t1.setSmooth(true);
	t2.setSmooth(true);

	Sprite background(t2);

	Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
	Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);
	Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
	Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
	Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);
	Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
	Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);


	std::list<Entity*> entities;

	for (int i = 0; i<15; i++)
	{
		Asteroid *a = new Asteroid();
		a->settings(sRock, rand() % W, 0, rand() % 360, 25);
		entities.push_back(a);
	}

	Player *p = new Player();
	p->settings(sPlayer, 600, 700, -90, 20);
	entities.push_back(p);

	/////main loop/////
	while (app.isOpen())
	{
		Event event;
		while (app.pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				app.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					Bullet *b = new Bullet();
					b->settings(sBullet, p->x, p->y, p->angle, 10);
					entities.push_back(b);
				}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) p->x += 3;
		if (Keyboard::isKeyPressed(Keyboard::Left))  p->x -= 3;

		for (auto a : entities)
			for (auto b : entities)
			{
				if (a->name == "asteroid" && b->name == "bullet")
					if (isCollide(a, b))
					{
						a->life = false;
						b->life = false;

						Entity *e = new Entity();
						e->settings(sExplosion, a->x, a->y);
						e->name = "explosion";
						entities.push_back(e);


						for (int i = 0; i<2; i++)
						{
							if (a->R == 15) continue;
							Entity *e = new Asteroid();
							e->settings(sRock_small, a->x, a->y, rand() % 360, 15);
							entities.push_back(e);
						}

					}

				if (a->name == "player" && b->name == "asteroid")
					if (isCollide(a, b))
					{
						b->life = false;

						Entity *e = new Entity();
						e->settings(sExplosion_ship, a->x, a->y);
						e->name = "explosion";
						entities.push_back(e);

						p->settings(sPlayer, 600, 700, -90, 20);
					}
			}


		for (auto e : entities)
			if (e->name == "explosion")
				if (e->anim.isEnd()) e->life = 0;

		if (rand() % 30 == 0)
		{
			Asteroid *a = new Asteroid();
			a->settings(sRock, rand() % W, 0, rand() % 360, 25);
			entities.push_back(a);
		}

		for (auto i = entities.begin(); i != entities.end();)
		{
			Entity *e = *i;

			e->update();
			e->anim.update();

			if (e->life == false) { i = entities.erase(i); delete e; }
			else i++;
		}

		//////draw//////
		app.draw(background);

		for (auto i : entities)
			i->draw(app);

		app.display();
		app.clear();
	}

	return 0;
}


bool isCollide(Entity *a, Entity *b)
{
	return (b->x - a->x)*(b->x - a->x) +
		(b->y - a->y)*(b->y - a->y)<
		(a->R + b->R)*(a->R + b->R);
}
