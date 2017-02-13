#include "Player.h"
#include "Map.h"
#include "DarkGDK.h"
#include "Global.h"
#include <vector>
#include "dinput.h"


PlayerAnt::PlayerAnt(float antStartX, float antStartY):

	antPosX(0), antPosY(0), antLastPosX(0),
	antLastPosY(0), antStartPosX(antStartX), antStartPosY(antStartY)
{
	dbCreateAnimatedSprite (sprAnt,"AntAnimNew.bmp",4,2,iAnt);
	dbOffsetSprite(sprAnt,24,24);
	dbSprite (sprAnt,antStartPosX+24,antStartPosY+24,iAnt);
	dbSetSprite(sprAnt,1,1);
	dbSetSpritePriority(sprAnt,priAnt);
}

PlayerAnt::~PlayerAnt()
{
	dbDeleteSprite(sprAnt);
	dbDeleteImage(iAnt);
}



void PlayerAnt::PlayerMove()
{
		if (dbKeyState(DIK_D) && dbSpriteX(sprAnt) < maxAntXPos)
		{
			dbRotateSprite(sprAnt,90);
			dbMoveSprite(sprAnt,moveSpeed);
			dbPlaySprite(sprAnt,1,8,60);
		}
		else if (dbKeyState(DIK_W) && dbSpriteY(sprAnt) > minAntYPos)
		{
			dbRotateSprite(sprAnt,0);
			dbMoveSprite(sprAnt,moveSpeed);
			dbPlaySprite(sprAnt,1,8,60);
		}
		else if (dbKeyState(DIK_S) && dbSpriteY(sprAnt) < maxAntYPos)
		{
			dbRotateSprite(sprAnt,180);
			dbMoveSprite(sprAnt,moveSpeed);
			dbPlaySprite(sprAnt,1,8,60);
		}
		else if (dbKeyState(DIK_A) && dbSpriteX(sprAnt) > minAntXPos)
		{
			dbRotateSprite(sprAnt,-90);
			dbMoveSprite(sprAnt,moveSpeed);
			dbPlaySprite(sprAnt,1,8,60);
		}
		
		// Detect collisions with wall
		Map::CollisionDetection();

		antLastPosX = dbSpriteX(sprAnt);
		antLastPosY = dbSpriteY(sprAnt);

		// idle animation to be 'Really Good' for Dr. B
		dbPlaySprite(sprAnt,5,6,600);
}