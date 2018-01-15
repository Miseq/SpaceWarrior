#pragma once
#include "Score.h"
#include "Colision.h"
using namespace std;

class MaintenceClass
{
protected:

	Player *p = new Player;
	list<Entity*> entities;
	Sprite* background = new Sprite;
	Score* playerScore = new Score;
	int NewEnemiesRate = 10;
	RenderWindow* app;
	Colision * colision;
public:

	list<Entity*> * getEntities();
	bool isCollide(Entity &a, Entity &b);

	RenderWindow& getMainWindow();
	void afterDeath();
	void Colisions();
	void Drawning();
	void EndingExpolsion();
	void EnemyShooting();
	void NewEnemies();
	void UpdateOfEntitiesStatus();
	void PlayerActions();
	MaintenceClass();
	~MaintenceClass();
};

