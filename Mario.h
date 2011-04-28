
/*
 *  Mario.h
 *  Mario
 *
 *  Created by Andrew Peddicord on 2/1/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 */
//Object constant will be 6
#ifndef __MARIO_H__
#define __MARIO_H__
const int SMALL_STATE = 0, BIG_STATE = 1, FIRE_STATE = 2;

#include "AllMovable.h"
#include "Game.h"
extern Game *game;


class Mario: public AllMovable {

public:
	//Constructor
	Mario();
  
	virtual void draw();
  	//Gets called when key is pressed
	void updateKeyDown(unsigned char button);
	//Gets called when key is let up
	void updateKeyUp(unsigned char button);
	//Returns State of Mario
	int getState();
    //Returns whether or not Mario is dead
    bool isDead();
    //updates Mario 
    void updateScene();
    //left bound of the windo
    void setLeftBound(int leftBound);
    //returns the object type of Mario
    virtual int objectType() { return MARIO; }
    //return end level
    bool levelDone();
    //reset to initial state
    void reset();

private:
	//State can be 0,1,2 depending if he is Big/Little/Fire Mario
	int state_, jumpCount_, starCount_, hitCount_, direction_; 
	bool isInvincible_, isDead_;
    bool jumpKey_, rightKey_, leftKey_, sprintKey_, fireballKey_;
    int leftBound_;
    GLuint texture_[3][4];
    GLuint deadtexture_;
    int texturePos;
    bool compleateLevel_;
    
	//Moves Mario to the left or right and calls check() at beginning
	void move();
    //checks to see if Mario runs into an object
    void check();
	//Returns true if Mario is in the fire state
	bool fireball();
    //Handels all jump cases
    void jump();
    //Loads Sprite
    void sprite();
	
};

//inline getter for state_
inline int Mario::getState() {return state_;}
//inline getter for isDead_
inline bool Mario::isDead() {return isDead_;}
inline bool Mario::levelDone() {return compleateLevel_;}

#endif
