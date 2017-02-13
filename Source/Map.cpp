#include <vector>
#include "DarkGDK.h"
#include "Global.h"
#include "Player.h"
#include "Map.h"

std::vector<int> collisionVector;
int leftEdge = minLeftEdge;
int topEdge = minTopEdge;
int maxNumSprites = 0;	

struct TileMap
	{
		int X, Y, Type;		
	};
	

TileMap* viewMap;


Map::Map()
{
	dbLoadImage ( "Floor.bmp", iFloor);
	dbLoadImage ( "Wall.bmp", iWall);
	dbSetImageColorKey ( 255, 0, 255 );
}

Map::~Map()
{
	dbDeleteImage ( iFloor );
	dbDeleteImage ( iWall );	
}

void Map::ProcessMap()
{

	viewMap = new TileMap[tileCount];

int tileIndex = 0;
	for (int h = 0; h < MAP_HEIGHT; h++)
	{
		for (int w = 0; w < (MAP_WIDTH - 1); w++)
		{
			if (mapArray[h][w] == 'W') 
			{				
				viewMap[tileIndex].Type = iWall;
				viewMap[tileIndex].X = w * sprW;
				viewMap[tileIndex].Y = h * sprH;
			}
				else if (mapArray[h][w] == 'F')
				{
					viewMap[tileIndex].Type = iFloor;
					viewMap[tileIndex].X = w * sprW;
					viewMap[tileIndex].Y = h * sprH;
				}
		tileIndex++;
		}
	}
}


//
void Map::DrawMap()
{
	// Go through all tiles in the level.
	int spriteIndex = 0;

	for (int i = 0; i < tileCount; i++)
	{
		
		// Draw only those sprites which are within the visible screen area.
		// Which image has to be drawn is determined by the type of the tile.
		if (viewMap[i].X >= (leftEdge - sprW) && viewMap[i].X <= (leftEdge + mapW) &&
			viewMap[i].Y >= (topEdge - sprH) && viewMap[i].Y <= (topEdge + mapH) )
		{
			dbSprite(sprMap + spriteIndex, viewMap[i].X - leftEdge, viewMap[i].Y - topEdge, (viewMap[i].Type));
			if (viewMap[i].Type == iWall) collisionVector.push_back(sprMap+spriteIndex);

			spriteIndex++;
		}
	}

	// If we created more sprites than the maximum so far: 
	// set the transparency (false), backsave (false) and priority of the new sprites, 
	// then adjust the maximum.
	// This way, the properties are only set once for each ground sprite.
	 if (spriteIndex > maxNumSprites) {
		for (int i = maxNumSprites; i < spriteIndex; i++) {
			dbSetSprite(sprMap + i, 0, 0);
			dbSetSpritePriority(sprMap + i, priMap);
		}
		maxNumSprites = spriteIndex;
	}

	
	// If we needed less sprites for this screen, then hide the surplus sprites
	// by placing them outside the visible screen area. (We could use dbHideSprite as well,
	// but this way, we don't need to call dbShowSprite for all the visible sprites every loop.)
	for (int i = spriteIndex; i < maxNumSprites; i++) {
		
		dbSprite(sprMap + i, -mapW, -mapH, iFloor);
	}
}


void Map::CollisionDetection()
{
	
	for (std::vector<int>::iterator p = collisionVector.begin();
		p != collisionVector.end();
                           ++p)
	{
		if (dbSpriteHit(sprAnt, *p))
			dbMoveSprite(sprAnt,-moveSpeed);
	}
	collisionVector.clear();
}


