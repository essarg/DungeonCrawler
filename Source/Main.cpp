

#include "DarkGDK.h"
#include "Global.h"
#include "mapping.h"
#include "dinput.h"
#include "Player.h"





											// the main entry point for the application is this function
void DarkGDK ( void )
{
	

		
	dbSyncOn   ( );
	dbSyncRate ( 60 );
	dbSetDisplayMode(1024,768,32);
	
	dbSetWindowPosition(46,46);
	//dbSetWindowOff();

	// a call is made to this function so we can stop the GDK from
	// responding to the escape key, we can then add in some code in our
	// main loop so we can control what happens when the escape key is pressed
	dbDisableEscapeKey ( );

	// now we will set the random seed value to the timer, this will
	// help us to get more random values each time we run the program
	dbRandomize ( dbTimer ( ) );

	// we are going to display a backdrop for the scene, to do this
	// we load our image and give it an ID number of 1, this particular
	// image is of a sky at night with stars
	//dbLoadImage ( "backdrop.bmp", 1 );
	
	// DrawMap();
	// the next step is to create a sprite that uses this image, this
	// is achieved by calling dbSprite and passing in a value of 1 for the
	// sprites ID, 0 for the X coordinate, 0 for the Y coordinates and a
	// value of 1 for the image
	//dbSprite ( 1, 0, 0, 1 );
	dbLoadImage ( "Floor.bmp", 1);
	dbLoadImage ( "Wall.bmp", 2);
	DrawMap();
	
	

	// next we will load in some animated sprites, before doing this
	// we need to adjust the image color key, by using this function we
	// can make a specific color be transparent, in our case we want this
	// to be bright pink
	dbSetImageColorKey ( 255, 0, 255 );
	int i = 10;
	
	dbCreateAnimatedSprite ( i, "AntAnimNew.bmp", 4, 2, i);
	dbOffsetSprite(i, 24, 24);
	dbSprite (i,20,608,i);
	

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
	for ( int i = 1; i < 30; i++ )
		dbDeleteSprite ( i );
	// delete the backdrop image
	dbDeleteImage ( 1 );
	dbDeleteImage ( 2 );

	// and now everything is ready to return back to Windows
	return;
}

