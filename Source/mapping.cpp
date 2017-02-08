#include <vector>
#include "DarkGDK.h"
#include "Global.h"
#include "Player.h"
#include "mapping.h"

std::vector<int> collisionVector;

void GetTile(char a, int x, int y, int p)
{	
	
	if (a == 'W')
	{
		dbSprite (p,x,y,2);
		collisionVector.push_back(p);
	}
	else if (a == 'F')
		dbSprite (p,x,y,1);
	else 
		dbSprite(p,x,y,0);
}

void DrawMap()
{
	int p = 200;
	int x = 0;
	int y = 0;	
	for (int h = 0; h < MAP_HEIGHT; h++){
		x=0;
		for (int w = 0; w < MAP_HEIGHT; w++){			
			GetTile(mapArray[h][w],x,y,p);
			p++;
			x+=64;}
		y+=64;}
	
}

void CollisionDetection()
{
	for (std::vector<int>::iterator p = collisionVector.begin();
		p != collisionVector.end();
                           ++p)
	{
		if (dbSpriteHit(iAnt, *p))
			dbMoveSprite(iAnt,-moveSpeed);
	}
	
}
