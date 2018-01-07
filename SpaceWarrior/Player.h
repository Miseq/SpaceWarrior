#pragma once
#include "stdafx.h"

class Player : public Entity
{
private:
	int CorrectAngle;
	int DefaultWidthStart;
	int DefaulHeightStart;

public:
	int getCorrectAngle();
	int getDefaulHeightStart();
	int getDefaultWidthStart();
	void update();
	Player();
	void playerMove(int speed = 0);
	void setAnimation(Animation newAnim);
	Bullet* DefaultShot();
	~Player();
};

