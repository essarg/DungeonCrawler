
#include "Global.h"
#include "DarkGDK.h"
#include "Map.h"
#include "Player.h"
#include "Timer.h"



PlayerAnt* player = 0;
int antStartX, antStartY;
int minX = minAntXPos, maxX = maxAntXPos, minY = minAntYPos, maxY = maxAntYPos;

void SetAntStart()
{
for (int h = 0; h < MAP_HEIGHT; h++)
	{
		for (int w = 0; w < MAP_WIDTH; w++)
		{
			if (mapArray[h][w] == 'E')
			{
				// Set the starting position of the player.
				// (The player object must exist already.)
				antStartX = w * sprW;
				antStartY = h * sprH;
			} 
		}
	}
}

// the main entry point for the application is this function
void DarkGDK ( void )
{

	dbSyncOn   ( );
	dbSyncRate (60);
	dbSetDisplayMode(640,640,32);
	dbSetWindowTitle("Ant in a Dungeon");
	dbSetWindowLayout(0,1,0);
	dbSetWindowPosition(46,46);
	dbAutoCamOff();
	dbDrawSpritesLast();
	//dbRandomize ( dbTimer ( ) ); //--I don't know if I'll need a randomizer yet

	SetAntStart();

	Map map;

	Timer timer;
	timer.Start();

	player = new PlayerAnt(antStartX, antStartY);

	
	map.ProcessMap();

	float playerPos(0);
	float timeDiff(0);
	

	// now we come to our main loop, we call LoopGDK so some internal
	// work can be carried out by the GDK
	while ( LoopGDK ( ) )
	{
		
		timeDiff = timer.UpdateTimer();

		player->PlayerMove(timeDiff);

		leftEdge = int(player->GetXPos() + 0.5) - mapW / 2;
		if(leftEdge < minLeftEdge){
			leftEdge = minLeftEdge;}
		else if (leftEdge > maxLeftEdge){
			leftEdge = maxLeftEdge;}	
		
		topEdge = int(player->GetYPos() + 0.5) - mapH / 2;
		if(topEdge < minTopEdge) topEdge = minTopEdge;
		else if (topEdge > maxTopEdge) topEdge = maxTopEdge;

	
		
		map.DrawMap();
		dbSync ( );
	}

	// when the user presses escape the code will break out to this location
	// and we can free up any previously allocated resources
	
	// delete all the sprites
	delete player;
	// delete the backdrop image
	map.~Map();

	// and now everything is ready to return back to Windows
	return;
}

