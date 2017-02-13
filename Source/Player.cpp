#include "Player.h"
#include "mapping.h"
#include "DarkGDK.h"
#include "Global.h"
#include <vector>
#include "dinput.h"


void CreateAntSprite()
{
	dbCreateAnimatedSprite (iAnt, "AntAnimNew.bmp", 4, 2, iAnt);
	dbOffsetSprite(iAnt, 24, 24);
	dbSprite (iAnt,20,608,iAnt);
}

void PlayerMove()
{
		if (dbKeyState(DIK_D) && dbSpriteX(iAnt) < 608)
		{
			dbRotateSprite(iAnt,90);
			dbMoveSprite(iAnt,moveSpeed);
			dbPlaySprite(iAnt,1,6,60);
		}
		else if (dbKeyState(DIK_W) && dbSpriteY(iAnt) > 32)
		{
			dbRotateSprite(iAnt,0);
			dbMoveSprite(iAnt,moveSpeed);
			dbPlaySprite(iAnt,1,6,60);
		}
		else if (dbKeyState(DIK_S) && dbSpriteY(iAnt) < 608)
		{
			dbRotateSprite(iAnt,180);
			dbMoveSprite(iAnt,moveSpeed);
			dbPlaySprite(iAnt,1,6,60);
		}
		else if (dbKeyState(DIK_A) && dbSpriteX(iAnt) > 32)
		{
			dbRotateSprite(iAnt,-90);
			dbMoveSprite(iAnt,moveSpeed);
			dbPlaySprite(iAnt,1,6,60);
		}
		CollisionDetection();
}