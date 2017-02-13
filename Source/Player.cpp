#include "Player.h"
#include "Map.h"
#include "DarkGDK.h"
#include "Global.h"
#include <vector>
#include "dinput.h"


PlayerAnt::PlayerAnt(int antStartX, int antStartY):

	antPosX(antStartX+32), antPosY(antStartY+32), antLastPosX(0),
	antLastPosY(0),stopped(false)
{
	dbCreateAnimatedSprite (sprAnt,"AntAnimNew.bmp",4,2,iAnt);
	dbScaleSprite(sprAnt,90);
	dbOffsetSprite(sprAnt,24,24);
	dbSprite (sprAnt,antPosX,antPosY,iAnt);
	dbSetSprite(sprAnt,1,1);
	dbSetSpritePriority(sprAnt,priAnt);
}

PlayerAnt::~PlayerAnt()
{
	dbDeleteSprite(sprAnt);
	dbDeleteImage(iAnt);
}



void PlayerAnt::PlayerMove(float timeDiff)
{
	
	
	int speedX = 0, speedY = 0;
	stopped = Map::CollisionDetection();
	
		if (dbKeyState(DIK_D) && dbSpriteX(sprAnt) < maxAntXPos)
		{
			dbRotateSprite(sprAnt,90);
			dbPlaySprite(sprAnt,1,8,60);
			if (stopped)
				speedX = -90;
			else
			speedX += moveSpeed;
		}
		else if (dbKeyState(DIK_W) && dbSpriteY(sprAnt) > minAntYPos)
		{
			dbRotateSprite(sprAnt,0);
			dbPlaySprite(sprAnt,1,8,60);
			if (stopped)
				speedY = 90;
			else
			speedY -= moveSpeed;
		}
		else if (dbKeyState(DIK_S) && dbSpriteY(sprAnt) < maxAntYPos)
		{
			dbRotateSprite(sprAnt,180);
			dbPlaySprite(sprAnt,1,8,60);
			if (stopped)
				speedY = -90;
			else
			speedY += moveSpeed;
		}
		else if (dbKeyState(DIK_A) && dbSpriteX(sprAnt) > minAntXPos)
		{
			dbRotateSprite(sprAnt,-90);
			dbPlaySprite(sprAnt,1,8,60);
			if (stopped)
				speedX = 90;
			else			
			speedX -= moveSpeed;
		}
		
		if (speedX != 0)
		{
			antPosX += speedX * timeDiff;
			if (antPosX < minAntXPos) antPosX = minAntXPos;
			else if (antPosX > maxAntXPos) antPosX = maxAntXPos;
		}

		if (speedY != 0)
		{
			antPosY += speedY * timeDiff;
			if (antPosX < minAntYPos) antPosY = minAntYPos;
			else if (antPosY > maxAntYPos) antPosY = maxAntYPos;
		}
		
		dbSprite(sprAnt, antPosX - leftEdge, antPosY - topEdge, iAnt);
				
		// idle animation to be 'Really Good' for Dr. B
		dbPlaySprite(sprAnt,5,6,600);
		stopped = false;
}

int PlayerAnt::GetXPos()
{
	return antPosX;
}

int PlayerAnt::GetYPos()
{
	return antPosY;
}

