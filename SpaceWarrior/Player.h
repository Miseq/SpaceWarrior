#pragma once
#include "stdafx.h"
class Player : public Entity
{
private:
	int CorrectAngle;
	int DefaultWidthStart;
	int DefaulHeightStart;
	std::list<Entity*> hearts;
	std::string nickname;
	Clock * immunityTimer = new Clock;
	int playerImmunity;

public:
	
	Bullet* DefaultShot();
	int getCorrectAngle();
	int getDefaulHeightStart();
	int getDefaultWidthStart();
	int playerDeath(RenderWindow& window);
	int getPlayerImmunity();
	std::string getNickname();
	std::list<Entity*> & getHearts();

	Clock * getImmunityTimer();
	void setNickname(std::string name);
	void setPlayerImmunity(int status);
	void playerWasShooted();
	void endOfPlayerImmortalty();
	void DestroyingHeart();
	void playerMove(int speed = 0);
	virtual void update();
	void setAnimation(Animation newAnim);
	void PlayerActions(std::list<Entity*> &entities, RenderWindow * app);
	void PlayerMoving();
	Player();
	~Player();
};

