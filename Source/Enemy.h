#pragma once

void CreateEnemy();
void UpdateEnemy();

class EnemyEgg
{
public:
	// The constructor and destructor will create/delete
	// the player image and player sprite.
	 EnemyEgg(int, int);
	~EnemyEgg();

	
	void EnemyMove();
	void KillEnemy(EnemyEgg);
	//static void ChickenCollision();

	int GetXPos();
	int GetYPos();
	static int enemyCount;
	
private:
	int sprThisEgg;
	float eggPosX, eggPosY;
	bool onWall, stopped;

}; 
	
	
	