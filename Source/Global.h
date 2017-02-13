#pragma once

/*******************
**** Definitions ***
*******************/

#define DIRECTINPUT_VERSION 0x0800
// Game map height and width
#define MAP_WIDTH  21
#define MAP_HEIGHT 20



/******************
**** Constants ****
******************/

enum spriteID {sprAnt = 1, sprMap};
enum imageID {iAnt = 1, iFloor, iWall};
enum idPriorities {priMap = 1, priAnt };
// Sets mapsize and width and height of map sprites
const int mapW = 640, mapH = 640, sprW = 64, sprH = 64;
const int tileCount = (MAP_WIDTH - 1) * MAP_HEIGHT;

// Limit screenscrolling by setting min and max map edges.
const int minLeftEdge = 0, maxLeftEdge = ((MAP_WIDTH - 1) * sprW) - mapW,
		  minTopEdge = 0, maxTopEdge = (MAP_HEIGHT * sprH) - mapH;


/** Limit the player movement: minimum is the left edge and top of the map area
*** Starts at 32 so half the sprite can't walk out of the map.
*** maximum is the right and bottom edge of the map area
*** minus one half sprite so half the sprite doesn't walk out of the map.
**/

const int minPlayerXPos = 32, maxPlayerXPos = 9.5 * sprW;
const int minPlayerYPos = 32, maxPlayerYPos = 9.5 * sprH;

// sets player movement speed in pixels per second
const float moveSpeed = 5;

// level map array
const char mapArray[MAP_HEIGHT][MAP_WIDTH] ={	"EWWWWWWWWWWWWWWWWWWW",
												"FFFFFFFFFFWFFFFFFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFFFFFFFFFFFFFFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFW",
												"WFFFWWFFFWWFFFWWFFFF",
												"WWWWWWWWWWWWWWWWWWWX"  };