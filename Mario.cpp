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
	glColor3i(255, 0, 0);
	int i;
	for(i=0;i<4;++i){
		glBegin(GL_POLYGON);
		glVertex2d(left(), bottom());
		glVertex2d(left(), top());
		glVertex2d(right(),top());
		glVertex2d(right(), bottom());
		glEnd();
	}
}
//------------------------------------------------------------
//constructor for Mario Class
Mario::Mario()
{
    //init the private instance variables to default value
    state_ = SMALL_STATE;
    jumpCount_ = 0;
    
    isInvincible_ = false;
    
    //init the keys
    jumpKey_ = false;
    rightKey_ = false;
    leftKey_ = false;
    sprintKey_ = false;
    fireballKey_ = false;
    
}
//------------------------------------------------------------
//updates Mario's movement info when a button is pushed
void Mario::updateKeyDown(unsigned char button)
{
    if (button == 'a')
    {
        leftKey_ = true;
    }
    
    else if (button == 'd')
    {
        rightKey_ = true;
    }
    
    if (button == 'w')
    {
        jumpKey_ = true;
        jumpCount_ = 5;
    }
    
    if (button == 'j')
    {
        sprintKey_ = true;
    }
    
    if (button = 'k')
    {
        fireballKey_ = true;
    }
}
//------------------------------------------------------------
//upadates Mario's info when a button is let up
void Mario::updateKeyUp(unsigned char button)
{
	if (button == 'a') {
		leftKey_ = false;
	}
	if (button == 'w') {
		jumpKey_ = false;
	}
	if (button == 'd') {
		rightKey_ = false;
	}
	if (button == 'j') {
		sprintKey_ = false;
	}
	if (button == 'k') {
		fireballKey_ = false;
	}
}
//Returns Mario's state
int Mario::getState() 
{
	return state_;
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
