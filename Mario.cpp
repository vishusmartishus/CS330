/* 
 *  Mario.cpp
 *  Mario
 *
 *  Created by Andrew Peddicord on 2/1/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 * filed edited by Drew and Nate
 */


#include "Mario.h"
//------------------------------------------------------------
void Mario::draw()
{

	
    
    
	
	
}
//------------------------------------------------------------
//constructor for Mario Class
Mario::Mario()
{
    //init the private instance variables to default value
    state_ = SMALL_STATE;
    jumpCount = 0;
    
    isInvincible_ = false;
    
    //init the keys
    jumpKey = false;
    rightKey = false;
    leftKey = false;
    sprintKey = false;
    
    
}
//------------------------------------------------------------
//updates Mario's info when a button is pushed
void Mario::updateKeyDown(unsigned char button)
{
    
}
//------------------------------------------------------------
//upadates Mario's info when a button is let up
void Mario::updateKeyUp(unsigned char button)
{
    
}
//------------------------------------------------------------
//method to calculate Marios movement
void Mario::move()
{
    //sets Mario's x position to allowed distance
    //this->setX(this->getX() + checkDistance(isRunning_));
    
}
//------------------------------------------------------------
//updates Mario for one Frame
void Mario::updateScene()
{
 
    
    
}
//------------------------------------------------------------
//method that checks to see if Mario runs into or is hit by
//an enemy
bool Mario::checkEnemy()
{
    

    
    
    
    
    
    return false;
    
}
//------------------------------------------------------------
//method that calculate the intersections of Mario and objects
//to see if Mario runs into anything
int Mario::checkDistance()
{
    
    
    return 0;
}
//------------------------------------------------------------
//Creates a fireball
bool Mario::fireball()
{    
	return false;
}
