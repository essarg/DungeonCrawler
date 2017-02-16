#pragma once

	extern int leftEdge, diffLeftEdge;
	extern int topEdge, diffTopEdge;

class Map{
public:

	Map();
	~Map();

	
	void ProcessMap();
	void DrawMap();
	void DrawBorder();
	
	void GetTile(char, int, int, int);
	static bool CollisionDetection();

};


