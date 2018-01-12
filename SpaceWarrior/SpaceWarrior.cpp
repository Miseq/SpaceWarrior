// SpaceWarrior.cpp : D+9efines the entry point for the console application.
#include "stdafx.h"


using namespace sf;

//TODO zmienić na grę chodzącą po czasie sf::Timer;
void main()
{
	Clock * gametimer = new Clock;
	Time* gameTime = new Time;
	MaintenceClass* game = new MaintenceClass;
	int LiczbaKlatek = 90;
	RenderWindow app(VideoMode(W, H), "Space Warrior v2.0");
	app.setFramerateLimit(LiczbaKlatek);
	

	Player *p = game->CreatingPLayer();


	while (app.isOpen())	
	{
		// TODO zrobic animacje eksplozji na gifach nie klatkach
		game->PlayerActions(app, *p);
		game->NewEnemies();
		game->Colisions(*p);	
		game->UpdateOfStatus();
		game->EndingExpolsion();
		game->EnemyShooting();
		game->Drawning(app);
	}
}

