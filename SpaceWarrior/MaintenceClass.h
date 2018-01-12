#pragma once

using namespace std;

class MaintenceClass
{

	list<Entity*> entities;
	Sprite background;

public:
	list<Entity*> * getEntities();
	bool isCollide(Entity &a, Entity &b);
	void NewEnemies();
	void UpdateOfStatus();
	void EndingExpolsion();
	Player* CreatingPLayer();
	void PlayerMoving(Player & p);
	void Colisions(Player &p);
	void PlayerActions(RenderWindow& app, Player & p);
	void EnemyShooting();
	void Drawning(RenderWindow &window);


	MaintenceClass();
	~MaintenceClass();
};

