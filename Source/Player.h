#pragma once


class PlayerAnt
{
public:
	// The constructor and destructor will create/delete
	// the player image and player sprite.
	 PlayerAnt(float antStartX, float antStartY);
	~PlayerAnt();

	
	// Set the (starting) position of the player.
	void PlayerMove();
	
	// This sets the new coordinates of the player, according to movement keys pressed.
	// It returns the current X position of the player.
	// The input parameter is the elapsed time and the current left edge of the screen.

	//int updateAnt(float TimeDiff, int LeftEdge);

private:
	float antPosX, antPosY;
	float antLastPosX, antLastPosY, antStartPosX, antStartPosY;

}; 
	
	
	