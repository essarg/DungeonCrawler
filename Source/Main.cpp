
#include "Global.h"
#include "DarkGDK.h"
#include "mapping.h"
#include "Player.h"
											// the main entry point for the application is this function
void DarkGDK ( void )
{		
	dbSyncOn   ( );
	dbSyncRate (60);
	dbSetDisplayMode(1024,768,32);
	
	dbSetWindowPosition(46,46);
		
	dbDisableEscapeKey ( );

	int placeHolder = 0; //DarkGDK needs a variable in here for some reason!
	//dbRandomize ( dbTimer ( ) );

	
	dbLoadImage ( "Floor.bmp", 1);
	dbLoadImage ( "Wall.bmp", 2);
	DrawMap();
	
	

	
	dbSetImageColorKey ( 255, 0, 255 );

	
	
	CreateAntSprite();

	// now we come to our main loop, we call LoopGDK so some internal
	// work can be carried out by the GDK
	while ( LoopGDK ( ) )
	{
		// run a loop through all our sprites
		
			// move the sprite down and play its animation
			// moving from frame 1 to 16 with a delay of 60 ms
		
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
	
	//	dbDeleteSprite ( iAnt );
	// delete the backdrop image
	dbDeleteImage ( 1 );
	dbDeleteImage ( 2 );

	// and now everything is ready to return back to Windows
	return;
}

