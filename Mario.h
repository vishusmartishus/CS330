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

#include "AllMoveable.h"

class Mario: public AllMoveable {

public:
	//Constructor
	Mario();
  
  	//Gets called when key is pressed
	void Update(int Button[]);
	
	//Get instance variables
	int  getState();
	int  getMaxHeight();
	bool getIsInvincible();
	bool getIsJumping();
	bool getIsRunning();

private:
	//State can be 0,1,2 depending if he is Big/Little/Fire Mario
	int state_, maxHeight_; 
	bool isInvincible_, isJumping_, isRunning_;

	void jump();
	//Moves Mario to the left or right and calls check() at beginning
	void move(bool isRunning);

	//Checks to see if Mario ran into something
	bool check(bool isRunning); 
	//Returns true if Mario is in the fire state
	bool fireball(); 
	
	//Set instance variables
	void setState(int s);
	void setMaxHeight(int mH);
	void setIsInvincible(bool i);
	void setIsJumping(bool j);
	void setIsRunning(bool r);
};

#endif
