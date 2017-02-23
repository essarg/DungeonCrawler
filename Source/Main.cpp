#include <vector>
#include "Global.h"
#include "DarkGDK.h"
#include "Map.h"
#include "Player.h"
#include "Timer.h"
#include "Enemy.h"



//Pointer to player object in Global Space
PlayerAnt* player = 0;

// create variables for maintaining map in window
int antStartX, antStartY;
int minX = minAntXPos, maxX = maxAntXPos, minY = minAntYPos, maxY = maxAntYPos;


// Look through map array and set ant to start position
void SetAntStart()
{
for (int h = 0; h < MAP_HEIGHT; h++)
	{
		for (int w = 0; w < MAP_WIDTH; w++)
		{
			if (mapArray[h][w] == 'E')
			{
				// Set the starting position of the player.
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
	dbSetDisplayMode(1024,768,32);
	dbSetWindowTitle("Ant in a Dungeon");
	dbSetWindowLayout(1,1,1);
	dbSetWindowPosition(46,46);
	dbAutoCamOff();
	dbDrawSpritesFirst();
	//dbRandomize ( dbTimer ( ) ); //--I don't know if I'll need a randomizer yet

	// call ant starting position function
	SetAntStart();

	//Create map object
	Map map;

	//create timer object and start the timer
	Timer timer;
	timer.Start();

	//create new player with starting position
	player = new PlayerAnt(antStartX, antStartY);
	
	//create enemy on the map
	//CreateEnemy();

	// read map array and load map to memory
	map.ProcessMap();
	
	//create player position and time for map scrolling
	float playerPos(0);
	float timeDiff(0);
	

	// now we come to our main loop, we call LoopGDK so some internal
	// work can be carried out by the GDK
	while ( LoopGDK ( ) )
	{
		//get timer difference for player movement
		timeDiff = timer.UpdateTimer();

		// call player movement function
		player->PlayerMove(timeDiff);
		
		//update the enemy(right now this just animates)
		//UpdateEnemy();
		
		//Calculate map position for viewable window
		leftEdge = int(player->GetXPos() + 0.5) - mapW / 2;
		if(leftEdge < minLeftEdge){
			leftEdge = minLeftEdge;}
		else if (leftEdge > maxLeftEdge){
			leftEdge = maxLeftEdge;}	
		
		topEdge = int(player->GetYPos() + 0.5) - mapH / 2;
		if(topEdge < minTopEdge) topEdge = minTopEdge;
		else if (topEdge > maxTopEdge) topEdge = maxTopEdge;
	
		//draw moveable map
		map.DrawMap();
		//draw border to hide scroll remnants
		map.DrawBorder();

		dbSync ( );
	}

	// when the user presses escape the code will break out to this location
	// and we can free up any previously allocated resources
	
	// delete player
	delete player;
	
	// delete the map
	map.~Map();

	// and now everything is ready to return back to Windows
	return;
}

