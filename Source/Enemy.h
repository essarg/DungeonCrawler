#pragma once

void CreateEnemy();
void UpdateEnemy();
void DestroyEnemy();


class EnemyEgg
{
public:
	// The constructor and destructor will create/delete
	// the player image and player sprite.
	 EnemyEgg();
	~EnemyEgg();

	
	void EnemyMove(int, int);
	void KillEnemy(EnemyEgg);
	int GetSprID();
	static bool ChickenCollision(int);

	int GetEnemyPosX();
	int GetEnemyPosY();
	
	static int enemyCount;
	
	
private:
	int sprThisEgg;
	float eggPosX, eggPosY;
	bool onWall,bumped;
	
}; 
	
	
	