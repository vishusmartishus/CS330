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
    state_ = 0;
    //will update to actaul height when figured out
    maxHeight_ = 0;
    isInvincible_ = false;
    isJumping_ = false;
    isRunning_ = false;
    
}
//------------------------------------------------------------
//updates Mario's info when a button is pushed
void Mario::update(int button[])
{
    
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
