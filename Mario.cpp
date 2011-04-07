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
#include "LListIterator.h"
#include "Level.h"
#include "Breakable.h"
#include "Nonbreakable.h"
#include <iostream>

using std::cout;
using std::endl;


//------------------------------------------------------------
void Mario::draw()
{
    int pattern[256] = {0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,
                0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
                0,0,2,2,2,3,3,2,3,0,0,0,0,0,0,0,
                0,2,3,2,3,3,3,2,3,3,3,0,0,0,0,0,
                0,2,3,2,2,3,3,3,2,3,3,3,0,0,0,0,
                0,2,2,3,3,3,3,2,2,2,2,0,0,0,0,0,
                0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,0,
                0,0,2,2,1,2,2,2,0,0,0,0,0,0,0,0,
                0,2,2,2,1,2,2,1,2,2,2,0,0,0,0,0,
                2,2,2,2,1,1,1,1,2,2,2,2,0,0,0,0,
                3,3,2,1,3,1,1,3,1,2,3,3,0,0,0,0,
                3,3,3,1,1,1,1,1,1,3,3,3,0,0,0,0,
                3,3,1,1,1,1,1,1,1,1,3,3,0,0,0,0,
                0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,
                0,2,2,2,0,0,0,0,2,2,2,0,0,0,0,0,
                2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0};
    
    int current;
    
    for (int i = 0; i<16; ++i) {
        for (int j = 0; j<16; ++j) {
            current = pattern[(i*16)+j];
            
            if (current == 1) {
                glColor3ub(255, 0, 0);
            }
            else if (current == 2){
                glColor3ub(153, 102, 0);
            }
            else{
                glColor3ub(255, 255, 102);
            }
            
            if (current > 0) {
                glBegin(GL_POLYGON);
                glVertex2d(left()+j, top()-i-1);
                glVertex2d(left()+j+1, top()-i-1);
                glVertex2d(left()+j+1, top()-i);
                glVertex2d(left()+j, top()-i);
                glEnd();
            }
        }
    }
}
//------------------------------------------------------------
//constructor for Mario Class
Mario::Mario()
{
    //init the private instance variables to default value
    state_ = SMALL_STATE;
    jumpCount_ = 0;
    starCount_ = 0;
    
    isInvincible_ = false;
    
    //init the keys
    jumpKey_ = false;
    rightKey_ = false;
    leftKey_ = false;
    sprintKey_ = false;
    fireballKey_ = false;
    
    //Set X and Y velocity
    this->setXVelocity(0.0);
    this->setYVelocity(0.0);

}
//------------------------------------------------------------
//updates Mario's movement info when a button is pushed
void Mario::updateKeyDown(unsigned char button)
{
    if (button == 'a')
    {
        leftKey_ = true;
        //set Mario's Velocity
        if (sprintKey_ == true)
        {
            this->setXVelocity(-2.0);
        }
        else 
        {
            this->setXVelocity(-1.0);
        }
    }
    
    else if (button == 'd')
    {
        rightKey_ = true;
        
        //set Mario's velocity
        if (sprintKey_ == true)
        {
            this->setXVelocity(2.0);
        }
        else 
        {
            this->setXVelocity(1.0);
        }
    }
    
    if (button == 'w')
    {
        jumpKey_ = true;
        if (jumpCount_ == 0 && this->getYVelocity() == 0.0) 
        {
            jumpCount_ = 50;
            
            //set Mario's velocity
            this->setYVelocity(2.0);
        }
    }
    
    if (button == 'j')
    {
        sprintKey_ = true;
    }
    
    if (button == 'k')
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
        if (rightKey_) {
            if (this->getXVelocity() < 0) {
                this->setXVelocity(1.0);
            }
        }
        else {
            this->setXVelocity(0.0);
        }
	}
	if (button == 'w') {
		jumpKey_ = false;
        if (jumpCount_ > 15) {
            jumpCount_ = 15;
        } else {
            jumpCount_ = 0;
            this->setYVelocity(-2.0);
        }
	}
    
	if (button == 'd') {
		rightKey_ = false;
        if (leftKey_) {
            if (this->getXVelocity() > 0) {
                this->setXVelocity(-1.0);
            }
        }
        else {
            this->setXVelocity(0.0);
        }
	}
	if (button == 'j') {
		sprintKey_ = false;
	}
	if (button == 'k') {
		fireballKey_ = false;
	}
}
//------------------------------------------------------------
//method to calculate Marios movement
void Mario::move()
{
    //actually does the movement of Mario
    this->setRight(this->right() + this->getXVelocity());
    this->setLeft(this->left() + this->getXVelocity());
    this->setTop(this->top() + this->getYVelocity());
    this->setBottom(this->bottom() + this->getYVelocity());
}
//------------------------------------------------------------
//Handels all jump cases
void Mario::jump() {
    if (this->jumpCount_ > 0) {
        jumpCount_--;
    } else if (this->getYVelocity() > 0.0) {
        this->setYVelocity(-2.0);
    }
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
    
    if (check()) {
        jump();
        move();
    } else {
        //Mario Dies
        this->setLeft(16);
        this->setRight(16+16);
        this->setBottom(16);
        this->setTop(16+16);
    }
}
//------------------------------------------------------------
//method that calculate the intersections of Mario and objects
//to see if Mario runs into anything
bool Mario::check()
{
    /*
    //get all the values of the objects so Mario knows what to do 
    // the object
    //check each case for each object
    //object list
    //flag: 1, breakable: 2, nonbreakable: 3, Fireflower: 4, coin: 5
    //Mario: 6, Goomba: 7, Mushroom: 8, Plant: 9, Shell: 10, Star: 11
    //Turtle: 12, EnemyFireball: 13, MarioFireball: 14
    
    int count = 0;;
    
    //the level 
    Level *level = Level::sharedLevel();
    
    //the lists of active objects
    LList moveableList = level->getActiveMovable();
    LList drawableList = level->getActiveDrawable();
    LList blockList = level->getActiveBlocks();
    
    //instance of LListIterator
    LListIterator iter;
    
    //object that will be checked for its type
    Drawable *object;
    
    iter.init(moveableList);
    
    while ((object = iter.next())) 
    {
        if (((this->right() >= object->left() && this->right() <= object->right()) || (this->left() <= object->right() && this->left() >= object->left())) && (this->bottom() <= object->top()))
        {
            //if Mario runs into an enemy
            if (object->objectType() == goomba_ || object->objectType() == plant_ || object->objectType() == shell_ || object->objectType() == turtle_ || object->objectType() == enemyfireball_)
            {
                //Mario dies from the right
                //go through the changes of Mario's state based on current state
                //and him getting hit by an enemy
                if (isInvincible_)
                {
                    //Mario kills the enemy
                }
                
                else if (this->state_ == FIRE_STATE)
                {
                  this->state_ = BIG_STATE;
                }
                
                else if (this->state_ == BIG_STATE)
                {
                    this->state_ = SMALL_STATE;
                }
                
                else {
                    //Mario dies
                    return false;
                }
                
            }
            //if Mario runs into a Movable Reward
            else if (object->objectType() == mushroom_ || object->objectType() == star_)
            {
                //update Mario's State
                if (object->objectType() == mushroom_) 
                {
                    if (this->state_ == SMALL_STATE)
                    {
                        this->state_ = BIG_STATE;
                    }
                    else
                    {
                        //give Mario Points for getting mushroom
                    }
                    
                }
                else if (object->objectType() == star_)
                {
                    //Mario is invincible 
                    isInvincible_ = true;
                    //Update invincible count
                    starCount_ = 50;
                }
            }
        }
                
        //possibly checking if things fall on Mario's Head
        
         if ((this->top() == object->bottom()) && ((this->right() >= object->left() || this->right() <= object->right()) || (this->left() >= object->left() || this->left() <= object->right())))
         {
             //if an enemy lands on top of Mario
             if (object->objectType() == goomba_ || object->objectType() == shell_ || object->objectType() == turtle_ || object->objectType() == enemyfireball_)
             {
                 if (isInvincible_)
                 {
                     //enemy dies
                 }
                 else 
                 {
                     //Mario dies
                     return false;
                 }
             }
             //if a reward lands on top of Mario
             else if (object->objectType() == mushroom_ || object->objectType() == star_)
             {
                 //update Mario's State
                 if (object->objectType() == mushroom_) 
                 {
                     if (this->state_ == SMALL_STATE)
                     {
                         this->state_ = BIG_STATE;
                     }
                     else
                     {
                         //give Mario Points for getting mushroom
                     }
                     
                 }
                 else if (object->objectType() == star_)
                 {
                     //Mario is invincible 
                     isInvincible_ = true;
                     //Update invicible count
                     starCount_ = 50;
                 }
             }
         }
        
        
        //checks if mario lands on top of object
        if ((this->bottom() == object->top()) && ((this->right() >= object->left() || this->right() <= object->right()) || (this->left() >= object->left() || this->left() <= object->right()))) 
        {
            //if Mario lands on top of an enemy
            if (object->objectType() == goomba_ || object->objectType() == shell_ || object->objectType() == turtle_)
            {
                //enemy dies
                //Mario's jumpcount reset? (Mario will jump higher (bounce))
            }
            //if Mario lands on a reward
            else if (object->objectType() == mushroom_ || object->objectType() == star_)
            {
                //update Mario's State
                if (object->objectType() == mushroom_) 
                {
                    if (this->state_ == SMALL_STATE)
                    {
                        this->state_ = BIG_STATE;
                    }
                    else
                    {
                        //give Mario Points for getting mushroom
                    }
                    
                }
                else if (object->objectType() == star_)
                {
                    //Mario is invincible 
                    isInvincible_ = true;
                    //Update invincible count
                    starCount_ = 50;
                }
            }
            //if Mario lands on an enemy that can't be killed
            else if (object->objectType() == plant_ || object->objectType() == enemyfireball_)
            {
                //go through the changes of Mario's state based on current state
                //and him getting hit by an enemy
                if (this->state_ == FIRE_STATE)
                {
                    this->state_ = BIG_STATE;
                }
                else if (this->state_ == BIG_STATE)
                {
                    this->state_ = SMALL_STATE;
                }
                else {
                    //Mario dies
                    return false;
                }
            }
        }
    }


    iter.init(drawableList);
    
    while ((object = iter.next()))
    {
        if (((this->right() >= object->left() && this->right() <= object->right()) || (this->left() <= object->right() && this->left() >= object->left())) && (this->bottom() <= object->top())) 
        {
            if (object->objectType() == flag_) 
            {
                //end game
            }
            else if (object->objectType() == fireflower_) 
            {
                //update Mario's State
                if (this->state_ == FIRE_STATE)
                {
                    //generate points for fireflower
                }
                else
                {
                    this->state_ = FIRE_STATE;
                }
                    
            }
            else if(object->objectType() == coin_) 
            {
                //update Mario's Points
            }
        }
    }
    
    iter.init(blockList);
    
    while ((object = iter.next()))
    {
        //check if Mario is jumping into a block
        if ((this->top() >= object->bottom() && this->top() <= object->top()) && ((this->right() >= object->left() && this->right() <= object->right()) || (this->left() >= object->left() && this->left() <= object->right()))) 
        {
            this->jumpCount_ = 0;
            this->setYVelocity(-2.0);
            if (this->state_ == BIG_STATE && object->objectType() == breakable_) {
                //break block
            }
            else 
            {
                //stop moving
                if (object->objectType() == question_)
                {
                    //generate reward
                }
            }
        }
        //check if Mario lands on a block
        if (((this->right() >= object->left() && this->right() <= object->right()) || (this->left() <= object->right() && this->left() >= object->left())) && (this->bottom() <= object->top() && this->bottom() >= object->bottom()))
        {
            //stop falling
            //keep moving
            count = 1;
            if (jumpCount_ == 0) {
                this->setYVelocity(0.0);
            }
        }
    }
    if (count == 0 && this->getYVelocity() == 0) {
        this->setYVelocity(-2.0);
    }
    if (this->bottom() > 0)
        return true;
    else
        return false;
    */
    Drawable *objb, *objt, *objl, *objr;
    objb = this->checkBottom();
    objt = this->checkTop();
    objl = this->checkLeft();
    objr = this->checkRight();
    if (objb) {
        cout << "TRUE";
    }
    if (objt) {
        if (objt->objectType() == question_) {
            Nonbreakable *temp = (Nonbreakable*)objt;
            temp->generateReward(this->getState() != SMALL_STATE);
        } else if (objt->objectType() == breakable_) {
            Breakable *temp = (Breakable*)objt;
        }
        this->jumpCount_ = 0;
        this->setYVelocity(-2.0);
        cout << "top";
    }
    if (objb && this->getYVelocity() < 0) {
        this->setYVelocity(0.0);
        cout << "bottom";
    }
    if (objl && this->getXVelocity() < 0) {
        this->setXVelocity(0.0);
        cout << "left";
    }
    if (objr && this->getXVelocity() > 0) {
        this->setXVelocity(0.0);
        cout << "right";
    }
    return true;
}
//------------------------------------------------------------
//Creates a fireball
bool Mario::fireball()
{
	return false;
}
