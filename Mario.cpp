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
//constructor for Mario Class
Mario::Mario()
{
    //init the private instance variables to default value
    state_ = 0;
    //will update to actaul height when figured out
    maxHeight_ = 0;
    isInvincible_ = false;
    isJumping_ = false;
    isRunning_ = false;
    
}
//------------------------------------------------------------
//updates Mario's info when a button is pushed
void Mario::Update(int button[])
{
    
}
//------------------------------------------------------------
//returns Mario state
int Mario::getState()
{
    return state_;
}
//------------------------------------------------------------
//returns Mario's Max Height
int Mario::getMaxHeight()
{
    return maxHeight_;
}
//------------------------------------------------------------
//returns whether Mario is Invincible
bool Mario::getIsInvincible()
{
    return isInvincible_;
}
//------------------------------------------------------------
//returns if Mario is jumping
bool Mario::getIsJumping()
{
    return isJumping_;
}
//------------------------------------------------------------
//returns if Mario is running
bool Mario::getIsRunning()
{
    return isRunning_;
}
//------------------------------------------------------------
//method to calculate Marios Jump
void Mario::jump()
{

}
//------------------------------------------------------------
//method to calculate Marios movement
void Mario::move(bool isRunning)
{
    
}
//------------------------------------------------------------
//method that calculate the intersections of Mario and objects
//to see if Mario runs into anything
bool Mario::check(bool isRunning)
{
    return false;
}
//------------------------------------------------------------
//Creates a fireball
bool Mario::fireball()
{    
	return false;
}
//------------------------------------------------------------
//Helper method for setting the state
void Mario::setState(int i) 
{
    
}
//------------------------------------------------------------
//Helper method for calculating max height
void Mario::setMaxHeight(int mH)
{
    
}
//------------------------------------------------------------
//Helper method for setting invincible
void Mario::setIsInvincible(bool i)
{
    
}
//------------------------------------------------------------
//Helper method for setting the jump
void Mario::setIsJumping(bool j)
{
    
}
//------------------------------------------------------------
//Helper method for running
void Mario::setIsRunning(bool r)
{
    
}











