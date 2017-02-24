#include "Player.h"
#include "Map.h"
#include "DarkSDK.h"
#include "Global.h"
#include "dinput.h"


PlayerAnt::PlayerAnt(int antStartX, int antStartY):

	antPosX(antStartX+32), antPosY(antStartY+32), stopped(false)
{
	dbCreateAnimatedSprite (sprAnt,"AntAnimNew.bmp",4,2,iAnt);
	dbScaleSprite(sprAnt,85);
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
	// set starting speed to 0
	int speedX = 0, speedY = 0;
	
	/*************************************************
	*** catch keypress disallows diagonal movement ***
	*** Key press rotates ant sprite to desired    ***
	*** direction, then plays the*/

		if (dbKeyState(DIK_D) && dbSpriteX(sprAnt) < maxXPos)
		{
			dbRotateSprite(sprAnt,90);
			dbPlaySprite(sprAnt,1,8,60);
			speedX += moveSpeed;
		}
		else if (dbKeyState(DIK_W) && dbSpriteY(sprAnt) > minYPos)
		{
			dbRotateSprite(sprAnt,0);
			dbPlaySprite(sprAnt,1,8,60);
			speedY -= moveSpeed;
		}
		else if (dbKeyState(DIK_S) && dbSpriteY(sprAnt) < maxYPos)
		{
			dbRotateSprite(sprAnt,180);
			dbPlaySprite(sprAnt,1,8,60);
			speedY += moveSpeed;
		}
		else if (dbKeyState(DIK_A) && dbSpriteX(sprAnt) > minXPos)
		{
			dbRotateSprite(sprAnt,-90);
			dbPlaySprite(sprAnt,1,8,60);
			speedX -= moveSpeed;
		}
		
		if (speedX != 0)
		{
			if(dbKeyState(DIK_LSHIFT))
				speedX = speedX*2;
			antPosX += speedX * timeDiff;
			if (antPosX < minXPos) antPosX = minXPos;
			else if (antPosX > maxXPos) antPosX = maxXPos;
		}

		if (speedY != 0)
		{
			if(dbKeyState(DIK_LSHIFT))
				speedY = speedY*2;
			antPosY += speedY * timeDiff;
			if (antPosX < minYPos) antPosY = minYPos;
			else if (antPosY > maxYPos) antPosY = maxYPos;
		}
		
		dbSprite(sprAnt, antPosX - leftEdge, antPosY - topEdge, iAnt);
		stopped = Map::CollisionDetection(sprAnt);
		if(stopped)
		{
					dbMoveSprite(sprAnt,-8);
					antPosX = dbSpriteX(sprAnt)+leftEdge;
					antPosY = dbSpriteY(sprAnt)+topEdge;
		}
		// idle animation to be 'Really Good' for Dr. B
		dbPlaySprite(sprAnt,4,6,600);
}

int PlayerAnt::GetXPos()
{
	return antPosX;
}

int PlayerAnt::GetYPos()
{
	return antPosY;
}

