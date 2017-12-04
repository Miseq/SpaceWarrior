#pragma once

class Player : public Entity
{
public:
	bool thrust;
	void update();
	Player();
	~Player();
};

