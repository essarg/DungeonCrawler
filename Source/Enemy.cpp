#include "Enemy.h"
#include "DarkSDK.h"
#include "Global.h"


std::vector<EnemyEgg*> enemyVector;
int EnemyEgg::enemyCount = 1;

void CreateEnemy()
{
	int x=64, y=64;
for (EnemyEgg::enemyCount; EnemyEgg::enemyCount <= 5; EnemyEgg::enemyCount++)
	{
		EnemyEgg* enemy = new EnemyEgg(x,y);
		enemyVector.push_back(enemy);
		x += 64;
		y += 64;
	}
}

void UpdateEnemy()
{
	for (std::vector<EnemyEgg*>::iterator enemy = enemyVector.begin();
		enemy != enemyVector.end();
                           ++enemy)
		{
			(*enemy)->EnemyMove();
		}
}

EnemyEgg::EnemyEgg(int EggStartX, int EggStartY):

	eggPosX(EggStartX),eggPosY(EggStartY),stopped(false)
{
	sprThisEgg = enemyCount + sprEgg;
	dbCreateAnimatedSprite(sprThisEgg,"EggAnim.bmp",4,2,iEgg);
	dbSprite (sprThisEgg,eggPosX,eggPosY,iEgg);
	dbSetSprite(sprThisEgg,1,1);
	dbSetSpritePriority(sprThisEgg,priEgg);
}


EnemyEgg::~EnemyEgg(void)
{
	dbDeleteSprite(sprThisEgg);
	dbDeleteImage(iEgg);
}

void EnemyEgg::EnemyMove(void)
{
	dbPlaySprite(sprThisEgg,1,8,300);
}

/**
void EnemyEgg::KillEnemy(EnemyEgg enemy)
{
	delete EnemyVector[enemy];
}
*/
