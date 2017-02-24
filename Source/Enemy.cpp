#include "Enemy.h"
#include "DarkSDK.h"
#include "Global.h"
#include "Map.h"


std::vector<EnemyEgg*> enemyVector;
std::vector<EnemyEgg*>::iterator enemy;

int EnemyEgg::enemyCount = 1;

EnemyEgg::EnemyEgg()	
{
	do
	{
		eggPosX=dbRND(mapW-65); 
		eggPosY=dbRND(mapH-65); 
		sprThisEgg = enemyCount + sprEgg;
		dbCreateAnimatedSprite(sprThisEgg,"EggAnim.bmp",4,2,iEgg);
		dbSprite (sprThisEgg,eggPosX,eggPosY,iEgg);
		dbSetSprite(sprThisEgg,1,1);
		dbSetSpritePriority(sprThisEgg,priEgg);	
		onWall = Map::CollisionDetection(sprThisEgg);
		bumped = ChickenCollision(sprThisEgg);
		if(onWall) dbDeleteSprite(sprThisEgg);
	}while(onWall || bumped);
}


EnemyEgg::~EnemyEgg(void)
{
	dbDeleteSprite(sprThisEgg);
}

void CreateEnemy()
{
	
for (EnemyEgg::enemyCount; EnemyEgg::enemyCount <= maxEnemy; EnemyEgg::enemyCount++)
	{
		
		EnemyEgg* enemy = new EnemyEgg();
		enemyVector.push_back(enemy);	
	}
}

void UpdateEnemy()
{
	for (enemy = enemyVector.begin();
		enemy != enemyVector.end();
                           ++enemy)
		{
			int startX = (*enemy)->GetEnemyPosX();
			int startY = (*enemy)->GetEnemyPosY();
			(*enemy)->EnemyMove(startX, startY);
		}
}

void DestroyEnemy()
{
	for (enemy = enemyVector.begin();
		enemy!= enemyVector.end();
		++enemy)

		delete *enemy;
}



void EnemyEgg::EnemyMove(int startX, int startY)
{
	int newX, newY;
	int addORsub = dbRND(1);

	if(addORsub == 0)
		newX = startX - (dbRND(3)/3);
	else if(addORsub == 1)
		newX = startX + (dbRND(3)/3);

	addORsub = dbRND(1);
	if(addORsub == 0)
		newY = startY - (dbRND(3)/3);
	else if(addORsub == 1)
		newY = startY + (dbRND(3)/3);

	dbSprite(sprThisEgg,newX,newY,iEgg);
	onWall = Map::CollisionDetection(sprThisEgg);
	bumped = ChickenCollision(sprThisEgg);
	if(onWall) dbSprite(sprThisEgg,startX,startY,iEgg);
	if(bumped) dbSprite(sprThisEgg,startX,startY,iEgg);
	dbPlaySprite(sprThisEgg,1,8,300);
}

bool EnemyEgg::ChickenCollision(int sprCheck)
{
	for (enemy = enemyVector.begin();
		enemy != enemyVector.end();
                           ++enemy)
	{
		if (sprCheck == (*enemy)->GetSprID()) return false;
		if (dbSpriteCollision(sprCheck, (*enemy)->GetSprID())) return true;
		
	}
	return false;
}

/**
void EnemyEgg::KillEnemy(EnemyEgg enemy)
{
	delete EnemyVector[enemy];
}
*/
int EnemyEgg::GetSprID()
{
	return sprThisEgg;
}

int EnemyEgg::GetEnemyPosX()
{
	return  dbSpriteX(sprThisEgg);
}

int EnemyEgg::GetEnemyPosY()
{
	return dbSpriteY(sprThisEgg);
}
