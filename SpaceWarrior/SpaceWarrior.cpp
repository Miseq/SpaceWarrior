// SpaceWarrior.cpp : Defines the entry point for the console application.
#include "stdafx.h"

using namespace std;

bool isCollide(Entity *a, Entity *b);
void NewAsteroids(Animation sRock,list <Entity*>& entities);
void UpdateOfStatus(list <Entity*> &entities);
void EndingExpolsion(list <Entity*> &entities);
void PlayerMoving(Player * p, Animation left, Animation right, Animation default);

using namespace sf;

int main()
{
	srand(time(0));

	RenderWindow app(VideoMode(W, H), "Space Warrior v2.0");
	app.setFramerateLimit(60);

	Texture defaultPlayerTexture, t2, t3, t4, t5, t6, t7, MovingLeftPlayerTexture, MovingRightPlayerTexture;
	
	defaultPlayerTexture.loadFromFile("assets/spaceassets.png");
	MovingLeftPlayerTexture.loadFromFile("assets/spaceassets.png");
	MovingRightPlayerTexture.loadFromFile("assets/spaceassets.png");
	t2.loadFromFile("assets/background.png");
	t3.loadFromFile("assets/explosions/type_A.png"); 
	t4.loadFromFile("assets/rock.png");
	t5.loadFromFile("assets/fire_blue.png");
	t6.loadFromFile("assets/rock_small.png");
	t7.loadFromFile("assets/explosions/type_B.png");
	
	defaultPlayerTexture.setSmooth(true);
	t2.setSmooth(true);
	t4.setSmooth(true);
	t5.setSmooth(true);
	
	Sprite background(t2);
	// (wspołrzędne początkowe wcianania x, y, rozmiar wyciętego fragmentu x,y, ilość klatek, szybkość zmiany klatki, skalowanie textury)
	Animation sExplosion			(t3, { 0, 0, 50, 50 }, 48, 0.5);
	Animation sRock					(t4, { 0, 0, 64, 64 }, 16, 0.25, { 0.9f,0.9f });
	Animation sRock_small			(t6, { 0, 0, 64, 64 }, 16, 0.25);
	Animation sBullet				(t5, { 0, 0, 32, 64 }, 16, 0.8);
	Animation sPlayerDefault		(defaultPlayerTexture, { 40, 40, 40, 40 }, 1, 0, { 1.3f,1.3f });
	Animation sPlayerRight			(MovingRightPlayerTexture, { 80, 40, 40, 40 }, 1, 0, { 1.3f,1.3f });
	Animation sPlayerLeft			(MovingLeftPlayerTexture, { 0, 40, 40, 40 }, 1, 0, { 1.3f,1.3f });
	Animation sExplosion_ship		(t7, { 0, 0, 192, 192 }, 64, 0.5);

	std::list<Entity*> entities;


	Player *p = new Player();
	p->settings(sPlayerDefault, 600, 700, -90, 20);
	entities.push_back(p);

	/////main loop/////
	while (app.isOpen())
	{
		Event gameEvent;
		while (app.pollEvent(gameEvent))
		{
			if (gameEvent.type == Event::KeyPressed)
			{
				if (gameEvent.key.code == Keyboard::Escape)
				{
					app.close();
				}

				else if (gameEvent.key.code == Keyboard::Space)
				{
					Bullet *b = new Bullet();
					b->settings(sBullet, p->x, p->y, p->angle, 10);
					entities.push_back(b);
					break;
				}
				
			}
		}

		PlayerMoving(p, sPlayerRight, sPlayerLeft, sPlayerDefault);

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


						for (int i = 0; i<(rand()%3); i++)
						{
							if (a->R ==15 ) continue;
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

						p->settings(sPlayerDefault, 600, 700, -90, 20);
					}
			}


		for (auto e : entities)
			if (e->name == "explosion")
				if (e->anim.isEnd()) e->life = 0;

		EndingExpolsion(entities);
		NewAsteroids(sRock, entities); 
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

bool isCollide(Entity *a, Entity *b)
{
	return (b->x - a->x)*(b->x - a->x) +
		(b->y - a->y)*(b->y - a->y)<
		(a->R + b->R)*(a->R + b->R);
}
void NewAsteroids(Animation sRock, list <Entity*>& entities) // TODO konstruktor kopiujący na asteroidy
{
	if (rand() % 10 == 0)
	{
		Asteroid *a = new Asteroid();
		a->settings(sRock, rand() % W, 0, rand() % 360, 25);
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
void PlayerMoving(Player * p, Animation left, Animation right, Animation default)
{

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		p->playerMove(3);
		p->setAnimation(right);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		p->playerMove(-3);
		p->setAnimation(left);
	}
	else
	{
		p->setAnimation(default);
	}
}
