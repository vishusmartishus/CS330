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

//------------------------------------------------------------
void Mario::draw()
{
	glColor3ub(255, 0, 0);
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
    starCount_ = 0;
    
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
//------------------------------------------------------------
//method to calculate Marios movement
void Mario::move()
{
    //assuming Mario Moves 1 unit sprinting or not
    
    //handle if Mario Falls while walking
    //if (check()) 
    //{
    //  this->setX(this->getX() + one unit);
    //}
    
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
    
    
	this->setLeft(this->left() + (vector[0] * vector[2]));
	this->setRight(this->right() + (vector[0] * vector[2]));
	this->setTop(this->top() + (vector[1] * vector[2]));
	this->setBottom(this->bottom() + (vector[1] * vector[2]));
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
    
    //object that will be checked for its type
    Drawable *object;
    
    iter.init(moveableList);
    
    while ((object = iter.next())) 
    {
        if (((this->right() >= object->left() and this->right() <= object->right()) or (this->left() <= object->right() and this->left() >= object->left())) and (this->bottom() <= object->top()))
        {
            //if Mario runs into an enemy
            if (object->objectType() == 7 or object->objectType() == 9 or object->objectType() == 10 or object->objectType() == 12 or object->objectType() == 13)
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
                    
                }
                
            }
            //if Mario runs into a Reward
            else if (object->objectType() == 8 or object->objectType() == 11)
            {
                //update Mario's State
                if (object->objectType() == 8) 
                {
                    if (this->state_ == SMALL_STATE)
                    {
                        this->state_ == BIG_STATE;
                    }
                    else
                    {
                        //give Mario Points for getting mushroom
                    }
                    
                }
                else if (object->objectType() == 11)
                {
                    //Mario is invincible 
                    isInvincible_ = true;
                }
            }
        }
                
        //ARE OBJECTS FALLING OFF OF LEDGES ONTO MARIO OR OTHER LEDGES? :yes
        //goomba mushroom shell star(can hit on top of head from bounce) fall off the ledge
        //possibly checking if things fall on Mario's Head
        
         if ((this->top() == object->bottom()) and ((this->right() >= object->left() or this->right() <= object->right()) or (this->left() >= object->left() or this->left() <= object->right())))
         {
             //if an enemy lands on top of Mario
             if (object->objectType() == 7 or object->objectType() == 10 or object->objectType() == 12 or object->objectType() == 13)
             {
                 if (isInvincible_)
                 {
                     //enemy dies
                 }
                 else 
                 {
                     //Mario dies from the right
                 }
             }
             //if a reward lands on top of Mario
             else if (object->objectType() == 8 or object->objectType() == 11)
             {
                 //update Mario's State
                 if (object->objectType() == 8) 
                 {
                     if (this->state_ == SMALL_STATE)
                     {
                         this->state_ == BIG_STATE;
                     }
                     else
                     {
                         //give Mario Points for getting mushroom
                     }
                     
                 }
                 else if (object->objectType() == 11)
                 {
                     //Mario is invincible 
                     isInvincible_ = true;
                 }
                 
             }
         }
        
        
        //checks if mario lands on top of object
        if ((this->bottom() == object->top()) and ((this->right() >= object->left() or this->right() <= object->right()) or (this->left() >= object->left() or this->left() <= object->right()))) 
        {
            //if Mario lands on top of an enemy
            if (object->objectType() == 7 or object->objectType() == 10 or object->objectType() == 12)
            {
                //enemy dies
                //Mario's jumpcount reset? (Mario will jump higher (bounce))
            }
            //if Mario lands on a reward
            else if (object->objectType() == 8 or object->objectType() == 11)
            {
                //update Mario's State
                if (object->objectType() == 8) 
                {
                    if (this->state_ == SMALL_STATE)
                    {
                        this->state_ == BIG_STATE;
                    }
                    else
                    {
                        //give Mario Points for getting mushroom
                    }
                    
                }
                else if (object->objectType() == 11)
                {
                    //Mario is invincible 
                    isInvincible_ = true;
                }
            }
            //if Mario lands on an enemy that can't be killed
            else if (object->objectType() == 9 or object->objectType() == 13)
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
                    
                }

                
            }
        }
        
    }


    iter.init(drawableList);
    
    while ((object = iter.next()))
    {
        if (((this->right() >= object->left() and this->right() <= object->right()) or (this->left() <= object->right() and this->left() >= object->left())) and (this->bottom() <= object->top())) 
        {
            if (object->objectType() == 1) 
            {
                //end game
            }
            else if (object->objectType() == 4) 
            {
                //update Mario's State
            }
            else if(object->objectType() == 5) 
            {
                //update Mario's Points
            }
        }
    }
    
    iter.init(blockList);
    
    while ((object = iter.next()))
    {
        //check if Mario is jumping into a block
        if (this->top() == object->bottom() and ((this->right() >= object->left() or this->right() <= object->right()) or (this->left() >= object->left() or this->left() <= object->right()))) 
        {
            if (this->state_ == BIG_STATE and object->objectType() == 2) {
                //break block
            }
            else {
                //stop moving
            }
        }
        //check if Mario lands on a block
        if (((this->right() >= object->left() and this->right() <= object->right()) or (this->left() <= object->right() and this->left() >= object->left())) and (this->bottom() <= object->top()))
        {
            //stop falling
            //keep moving
        }
    }
    return true;
}
//------------------------------------------------------------
//Creates a fireball
bool Mario::fireball()
{
	return false;
}
