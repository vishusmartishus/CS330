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
	else if (button == 'w') {
		jumpKey_ = false;
	}
	else if (button == 'd') {
		rightKey_ = false;
	}
	else if (button == 'j') {
		sprintKey_ = false;
	}
	else if (button == 'k') {
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
    //depending on whats happening we need to update Mario
    // check the key and move mario according to the button that is being pushed
    //call the check methods to check to see if Mario is running into things
    //this works one frame at a time
    //if Mario jumps decrease the jumpCount_ by 1 every frame
    
    
}
//------------------------------------------------------------
//method that calculate the intersections of Mario and objects
//to see if Mario runs into anything
bool Mario::check()
{
    //get all the values of the objects so Mario knows what to do 
    // the object
    //check each case for each object
    //object list
    //flag: 1, breakable: 2, nonbreakable: 3, Fireflower: 4, coin: 5
    //Mario: 6, Goomba: 7, Mushroom: 8, Plant: 9, Shell: 10, Star: 11
    //Turtle: 12, EnemyFireball: 13, MarioFireball: 14
    
    //the level 
    Level *level = Level::sharedLevel();
    
    //the lists of active objects
    LList moveableList = level->getActiveMovable();
    LList drawableList = level->getActiveDrawable();
    LList blockList = level->getActiveBlocks();
    
    //instance of LListIterator
    LListIterator iter;
    
    return false;
}
//------------------------------------------------------------
//Creates a fireball
bool Mario::fireball()
{    
	return false;
}