/*
 *  Mario.h
 *  Mario
 *
 *  Created by Andrew Peddicord on 2/1/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 */

#ifndef _MARIO_H
#define _MARIO_H

class Mario {

public:
	Mario(); //Constructor
  
	void Update(int Button[]); //Gets called when key is pressed
	
	//Get instance variables
	int  getState();
	int  getMaxHeight();
	bool getIsInvincible();
	bool getIsJumping();
	bool getIsPounding();
	bool getIsRunning();

private:
	int state_, maxHeight_; //State can be 0,1,2 depending if he is Big/Little/Fire Mario
	bool isInvincible_, isJumping_, isPounding_, isRunning_;

	void Jump();
	void Move(bool isRunning); //Moves Mario to the left or right and calls check() at beginning

	bool check(bool isRunning); //Checks to see if Mario ran into something
	bool checkLeftRight();
	bool checkTop();
	bool checkBottom();
	bool fireball(); //Returns true if Mario is in the fire state
	bool buttpound();
	
	//Set instance variables
	void setState(int s);
	void setMaxHeight(int mH);
	void setIsInvincible(bool i);
	void setIsJumping(bool j);
	void setIsPounding(bool p);
	void setIsRunning(bool r);
};

#endif
