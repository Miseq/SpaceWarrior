#pragma once

class Player : public Entity
{
public:
	void update();
	Player();
	void playerMove(int speed = 0);
	void setAnimation(Animation newAnim);
	~Player();
};

