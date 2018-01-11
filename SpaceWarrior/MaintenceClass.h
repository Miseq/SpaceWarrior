#pragma once

using namespace std;

class MaintenceClass
{

	list<Entity*> entities;

public:
	list<Entity*> * getEntities();
	bool isCollide(Entity &a, Entity &b);
	void NewEnemies(list <Entity*>& entities);
	void UpdateOfStatus(list <Entity*> &entities);
	void EndingExpolsion(list <Entity*> &entities);
	Player* CreatingPLayer(list <Entity*> &entities);
	void PlayerMoving(Player & p);
	void Colisions(list <Entity*> &entities, Player &p);
	void PlayerActions(RenderWindow& app, list <Entity*> &entities, Player & p);
	void EnemyShooting(list <Entity*> &entities);
	MaintenceClass();
	~MaintenceClass();
};

