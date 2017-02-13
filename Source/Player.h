#pragma once



class PlayerAnt
{
public:
	// The constructor and destructor will create/delete
	// the player image and player sprite.
	 PlayerAnt(int, int);
	~PlayerAnt();

	
	// Set the (starting) position of the player.
	void PlayerMove(float);

	int GetXPos();
	int GetYPos();
	// This sets the new coordinates of the player, according to movement keys pressed.
	// It returns the current X position of the player.
	// The input parameter is the elapsed time and the current left edge of the screen.

	//int updateAnt(float TimeDiff, int LeftEdge);

private:
	float antPosX, antPosY;
	float antLastPosX, antLastPosY, antStartPosX, antStartPosY;

}; 
	
	
	