#pragma once
class Colision
{
public:
	Colision();
	void Collisions(std::list<Entity*> &entities, Player &p, Score & playerScore);
	bool isCollide(Entity & a, Entity & b);
	~Colision();
};

