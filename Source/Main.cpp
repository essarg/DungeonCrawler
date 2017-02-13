
#include "Global.h"
#include "DarkGDK.h"
#include "mapping.h"
#include "Player.h"
// the main entry point for the application is this function
void DarkGDK ( void )
{
	// Probably move this to it's own function in an attempt to keep the main small
	dbSyncOn   ( );
	dbSyncRate (60);
	dbSetDisplayMode(1024,768,32);
	dbSetWindowPosition(46,46);
	dbDisableEscapeKey ( );
	
	// Don't know why it won't run with out a declared variable in main!
	int placeHolder = 0; //DarkGDK needs a variable in here for some reason!
	
	
	//dbRandomize ( dbTimer ( ) ); --I don't know if I'll need a randomizer yet

	// these declarations will be moved to mapping
	dbLoadImage ( "Floor.bmp", 1);
	dbLoadImage ( "Wall.bmp", 2);
	
	// DrawMap will move to game function
	DrawMap();	
	
	// this will move game function
	dbSetImageColorKey ( 255, 0, 255 );
	CreateAntSprite();

	// now we come to our main loop, we call LoopGDK so some internal
	// work can be carried out by the GDK
	while ( LoopGDK ( ) )
	{
		
		PlayerMove();	
		
		// here we check if the escape key has been pressed, when it has
		// we will break out of the loop
		if ( dbEscapeKey ( ) )
			break;

		// here we make a call to update the contents of the screen
		dbSync ( );
	}

	// when the user presses escape the code will break out to this location
	// and we can free up any previously allocated resources
	
	// delete all the sprites
	dbDeleteSprite ( iAnt );
	// delete the backdrop image
	dbDeleteImage ( 1 );
	dbDeleteImage ( 2 );

	// and now everything is ready to return back to Windows
	return;
}

