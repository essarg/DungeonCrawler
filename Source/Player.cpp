#include "Player.h"
#include "mapping.h"
#include "DarkSDK.h"
#include "Global.h"
#include <vector>
#include "dinput.h"



void PlayerMove()
{
	for ( int i = 10; i < 30; i++ )
	{
		
		if (dbKeyState(DIK_D) && dbSpriteX(i) < 608)
		{
			dbRotateSprite(i,90);
			dbMoveSprite(i,1);
			dbPlaySprite(i,1,8,60);
		}
		else if (dbKeyState(DIK_W) && dbSpriteY(i) > 32)
		{
			dbRotateSprite(i,0);
			dbMoveSprite(i,1);
			dbPlaySprite(i,1,8,60);
		}
		else if (dbKeyState(DIK_S) && dbSpriteY(i) < 608)
		{
			dbRotateSprite(i,180);
			dbMoveSprite(i,1);
			dbPlaySprite(i,1,8,60);
		}
		else if (dbKeyState(DIK_A) && dbSpriteX(i) > 32)
		{
			dbRotateSprite(i,-90);
			dbMoveSprite(i,1);
			dbPlaySprite(i,1,8,60);
		}
		CollisionDetection(i);
	}
}

