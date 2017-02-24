#pragma once

/*******************
**** Definitions ***
*******************/

//dinput definition
#define DIRECTINPUT_VERSION 0x0800

// Game map height and width
#define MAP_WIDTH  36
#define MAP_HEIGHT 20

/******************
**** Constants ****
******************/


enum spriteID {sprAnt = 1, sprWall, sprMap, sprEgg = 3000};
enum imageID {iAnt = 1, iEgg, iFloor, iWall, iDown, iEntrance};
enum PriorityID {priMap = 1, priEgg, priAnt, priWall};

// Sets mapsize and width and height of map sprites
const int mapW = 640, mapH = 640, sprW = 64, sprH = 64;
const int tileCount = (MAP_WIDTH - 1) * (MAP_HEIGHT);

// Limit screenscrolling by setting min and max map edges.
const int minLeftEdge = 0, maxLeftEdge = ((MAP_WIDTH-1) * sprW) - mapW,
		  minTopEdge = 0, maxTopEdge = ((MAP_HEIGHT) * sprH) - mapH;


/** Limit the player movement: minimum is the left edge and top of the map area
*** Starts at 32 so half the sprite can't walk out of the map.
*** maximum is the right and bottom edge of the map area
*** minus one half sprite so half the sprite doesn't walk out of the map.
**/

const int minXPos = 32, maxXPos = (MAP_WIDTH - 1.5) * sprW, minYPos = 32, maxYPos = (MAP_HEIGHT - 0.5) * sprH;

// sets player movement speed in pixels per second
const float moveSpeed = 180.0;

const int maxEnemy = 5;

// level map arrayW
const char mapArray[MAP_HEIGHT][MAP_WIDTH] ={	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWEWWWWWW",
												"WFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW",
												"WFFWWWFFWWWWWFWFFFFWFWWWFFFFFFFFFFW",
												"WFWFFFWFWFFFFFWWFFFWFWFFWFFFFFFFFFW",
												"WFFWWFFFWWWFFFWFWFFWFWFFFWFFFFFFFFW",
												"WFFFWWFFWWWFFFWFFWFWFWFFFWFFFFFFFFW",
												"WFWFFFWFWFFFFFWFFFWWFWFFWFFFFFFFFFW",
												"WFFWWWFFWWWWWFWFFFFWFWWWFFFFFFFFFFW",
												"WFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW",
												"WFWFFFFWFWFFFFWFWWWFFFWWWWWFFWWWFFW",
												"WFWWFFFWFWFFFFWFWFFWFFWFFFFFWFFFWFW",
												"WFWFWFFWFWFFFFWFWFFFWFWWWFFFFWWFFFW",
												"WFWFFWFWFWFFFFWFWFFFWFWWWFFFFFWWFFW",
												"WFWFFFWWFWFFFFWFWFFWFFWFFFFFWFFFWFW",
												"WFWFFFFWFFWWWWFFWWWFFFWWWWWFFWWWFFW",
												"WFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW",
												"WFFFFFFFFFFWWFFFWWFFFWWFFFFFFFFFFFW",
												"WFFFFFFFFFFWWFFFWWFFFWWFFFFFFFFFFFW",
												"WFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF",
												"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWX"};