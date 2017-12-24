#pragma once

class Player : public Entity
{
private:
	int speed = 3;
public:
	void update();
	void playerMoveRight();
	void playerMoveLeft();
	Player();
	~Player();
};

