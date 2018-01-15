#include "stdafx.h"
#include "Colision.h"


Colision::Colision()
{
}

void Colision::Collisions(std::list<Entity*>& entities, Player &p, Score & playerScore)
{

	Singleton *mapOfAnimation = Singleton::getInstance();
	string nameA, nameB;
	double SpaceAB, RadiousAB;

	for (auto a : entities)
	{
		nameA = a->getName();
		for (auto b : entities)
		{
			SpaceAB = pow((b->getPosition().x - a->getPosition().x), 2) + pow((b->getPosition().y - a->getPosition().y), 2);
			RadiousAB = pow((a->getRadius() + b->getRadius()), 2);
			nameB = b->getName();
			/// nie wygl¹da ³¹dnie ale przy wielu kolizjach wywo³ywanie 2x funkcji i przesy³anie wartoœci + obliczenia powoda³y problem w optymalizacji
			bool isCollide = [](int SpaceAB, int RadiousAB)->bool { return SpaceAB <= RadiousAB; } (SpaceAB,RadiousAB);
			
			if ((nameA == "asteroid" || nameA == "enemy") && nameB == "bullet")
				if (isCollide)
				{
					a->setLife(false);
					b->setLife(false);
					playerScore.AddValueToPlayerScore(*a);

					Entity *e = new Entity();
					e->settings(*mapOfAnimation->Animacje["asteroidExplosion"], a->getPosition().x, a->getPosition().y);
					e->setName("explosion");
					entities.push_back(e);



					for (int i = 0; i < (rand() % 4); i++)
					{
						if (a->getRadius() == 15) continue;
						Entity *e = new Asteroid();
						e->settings(*mapOfAnimation->Animacje["rockSmall"], a->getPosition().x, a->getPosition().y, rand() % 360, 15);
						entities.push_back(e);
					}

				}

			if (nameA == "player" && (nameB == "asteroid" || nameB == "enemy" || nameB == "enemybullet"))
			{
				if (isCollide)
				{
					p.setLife(p.getLife() - 1);
					p.DestroyingHeart();
					p.playerWasShooted();
					b->setLife(0);
					Entity *e = new Entity();
					e->settings(*mapOfAnimation->Animacje["shipExplosion"], a->getPosition().x, a->getPosition().y);
					e->setName("explosion");
					entities.push_back(e);
					p.settings(*mapOfAnimation->Animacje["playerPostionDefaul"], p.getDefaultWidthStart(), p.getDefaulHeightStart(), p.getCorrectAngle(), 20);
				}
			}
		}
	}
}


Colision::~Colision()
{
}
