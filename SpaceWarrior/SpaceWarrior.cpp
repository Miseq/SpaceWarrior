#include "stdafx.h"

using namespace sf;


int main()
{
	MaintenceClass* game = new MaintenceClass;

	while (game->getMainWindow().isOpen())	
	{
		//while(game->getFlaga() == false) game->SettingPlayerNickname(); DO daleszj obrobki
		game->PlayerActions();
		game->NewEnemies();
		game->Colisions();	
		game->UpdateOfEntitiesStatus();
		game->EndingExpolsion();
		game->EnemyShooting();
		game->Drawning();
	}
	return 0;
}