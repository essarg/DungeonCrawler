#pragma once



class PlayerAnt
{
public:
	// The constructor and destructor will create/delete
	// the player image and player sprite.
	 PlayerAnt(int, int);
	~PlayerAnt();

	
	
	void PlayerMove(float);

	int GetXPos();
	int GetYPos();
	

private:
	float antPosX, antPosY;
	bool stopped;

}; 
	
	
	