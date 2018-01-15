#include "stdafx.h"
#include "MaintenceClass.h"
#include <fstream>
#include <iostream>

MaintenceClass::MaintenceClass()
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	p->settings(*mapOfAnimation->Animacje["playerPostionDefaul"], p->getDefaultWidthStart(), p->getDefaulHeightStart(), p->getCorrectAngle(), 20);
	entities.push_back(p);

	Texture* backgroundTexture = new Texture;
	backgroundTexture->loadFromFile("assets/background.png");
	backgroundTexture->setSmooth(true);
	background->setTexture(*backgroundTexture);
	colision = new Colision();
	app = new RenderWindow(VideoMode(W, H), "Space Warrior v2.0");
	app->setFramerateLimit(90);
	

}

MaintenceClass::~MaintenceClass()
{
}

list<Entity*>* MaintenceClass::getEntities()
{
	return &entities;
}

RenderWindow& MaintenceClass::getMainWindow()
{
	return *app;
}

void MaintenceClass::NewEnemies()
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	Time spawnTime = timer->getElapsedTime();
	int numberOfAsteroids = 40;
	int numberOfShips = 250;
	if (spawnTime.asMilliseconds() >= NewEnemiesRate)
	{
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
}

void MaintenceClass::PlayerActions()
{
	p->PlayerActions(entities, app);
}

void MaintenceClass::EnemyShooting()
{
	Singleton *mapOfAnimation = Singleton::getInstance();
	*gameTime = timer->getElapsedTime();
	for (auto i : entities)
	{
		if (i->getName() == "enemy" && gameTime->asMilliseconds() >= (rand() % 50 + 450))
		{
			Bullet *b = new Bullet;
			b->setName("enemybullet");
			b->settings(*mapOfAnimation->Animacje["alienBulelt"], i->getPosition().x, i->getPosition().y, i->getAngle(), 10);
			entities.push_back(b);
			timer->restart();
		}

	}
}

void MaintenceClass::Colisions()
{
	colision->Collisions(entities, *p, *playerScore);
}

void MaintenceClass::UpdateOfEntitiesStatus()
{
	if (p->getPlayerImmunity() == 1)
	{
		Time timeOfImmortalty;
		timeOfImmortalty = p->getImmunityTimer()->getElapsedTime();
		if (timeOfImmortalty.asMilliseconds() >= 5000) p->endOfPlayerImmortalty();
	}
	if (p->getLife() <= 0)
	{
		afterDeath();
	}
	for (auto i = entities.begin(); i != entities.end();)
	{

		Entity *e = *i;

		e->update();
		e->getAnimation().update();

		if (e->getLife() == 0) { i = entities.erase(i); delete e; }
		else i++;
	}
}

void MaintenceClass::EndingExpolsion()
{
	for (auto e : entities)
		if (e->getName() == "explosion")
			if (e->getAnimation().isEnd()) e->setLife(false);
}

void MaintenceClass::Drawning()
{
	app->clear();
	app->draw(*background);
	for (auto i : entities)	i->draw(*app);
	for (auto d : p->getHearts()) d->draw(*app);
	if (p->getPlayerImmunity() == 1) app->draw(playerScore->getImmortalityText());
	app->draw(playerScore->getPlayerScoreAsText());
	app->display();
}

void MaintenceClass::afterDeath()
{
	Singleton *mapOfAnimation = Singleton::getInstance();

	Font* font = new Font;
	Text restart;
	Color* textColor = new Color;

	std::ifstream records("high_scores.txt", std::ifstream::in);
	int prev_score;
	records >> prev_score;

	int actualscore = playerScore->getPlayerScoreAsInt();
	if (actualscore > prev_score)
	{
		std::ofstream scores("high_scores.txt");
		scores << actualscore;
	}
	//scores << p->getNickname() << "\n";

	font->loadFromFile("assets/waltographUI.ttf");
	restart.setFont(*font);
	restart.setCharacterSize(24);
	restart.setFillColor(textColor->Green);
	restart.setPosition({ 50,400 });
	std::ostringstream oss;
	oss.str(std::string());
	oss << "				GAME OVER!\n\n	Past best score was "<<prev_score<<"\n\n";
	oss<<"Press R to restart or Esc to quit";
	restart.setString(oss.str());
	app->draw(restart);
	app->display();




	do
	{
		if (Keyboard::isKeyPressed(Keyboard::R))
		{
			for (auto i : entities) i->setLife(0);
			app->clear();
			p = new Player;
			p->settings(*mapOfAnimation->Animacje["playerPostionDefaul"], p->getDefaultWidthStart(), p->getDefaulHeightStart(), p->getCorrectAngle(), 20);
			playerScore->setPlayerScore(0);
			entities.push_back(p);
			break;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			app->close();
		}
	} while (1);

	

}