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
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


//------------------------------------------------------------
void Mario::draw()
{
    //Determine power up
    int dState= 0;
    
    if (this->state_ == BIG_STATE) {
        dState = 1;
    }
    else if ( this->state_ == FIRE_STATE){
        dState = 2;
    }
    
    
    if (this->getYVelocity() != 0.0) {
        texturePos = 3;
    }
    else if (this->getXVelocity() != 0.0){
        if (texturePos == 1) {
            texturePos = 2;
        }
        else{
            texturePos = 1;
        }
    }
    else{
        texturePos = 0;
    }

             
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, texture_[dState][texturePos]);
    

    glBegin( GL_QUADS );
    glColor4f(0.7f,0.9f,1.0f,1.0f);
    if (this->getXVelocity() >= 0) {
        glTexCoord2d(0.0,0.0); glVertex2d(left(),bottom());
        glTexCoord2d(1.0,0.0); glVertex2d(right(),bottom());
        glTexCoord2d(1.0,1.0); glVertex2d(right(),top());
        glTexCoord2d(0.0,1.0); glVertex2d(left(),top());
    }
    else{
        glTexCoord2d(0.0,0.0); glVertex2d(right(),bottom());
        glTexCoord2d(1.0,0.0); glVertex2d(left(),bottom());
        glTexCoord2d(1.0,1.0); glVertex2d(left(),top());
        glTexCoord2d(0.0,1.0); glVertex2d(right(),top());
    }
    glEnd();
    
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}
//------------------------------------------------------------
//constructor for Mario Class
Mario::Mario()
{
    //init the private instance variables to default value
    state_ = SMALL_STATE;
    jumpCount_ = 0;
    starCount_ = 0;
    
    isDead_ = false;
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
    
        
    sprite();
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
    
    if (button == 'd')
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
        isDead_ = true;
        
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
            if (object->objectType() == GOOMBA || object->objectType() == PLANT || object->objectType() == SHELL || object->objectType() == TURTLE || object->objectType() == ENEMYFIREBALL)
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
            else if (object->objectType() == MUSHROOM || object->objectType() == STAR)
            {
                //update Mario's State
                if (object->objectType() == MUSHROOM) 
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
                else if (object->objectType() == STAR)
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
             if (object->objectType() == GOOMBA || object->objectType() == SHELL || object->objectType() == TURTLE || object->objectType() == ENEMYFIREBALL)
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
             else if (object->objectType() == MUSHROOM || object->objectType() == STAR)
             {
                 //update Mario's State
                 if (object->objectType() == MUSHROOM) 
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
                 else if (object->objectType() == STAR)
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
            if (object->objectType() == GOOMBA || object->objectType() == SHELL || object->objectType() == TURTLE)
            {
                //enemy dies
                //Mario's jumpcount reset? (Mario will jump higher (bounce))
            }
            //if Mario lands on a reward
            else if (object->objectType() == MUSHROOM || object->objectType() == STAR)
            {
                //update Mario's State
                if (object->objectType() == MUSHROOM) 
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
                else if (object->objectType() == STAR)
                {
                    //Mario is invincible 
                    isInvincible_ = true;
                    //Update invincible count
                    starCount_ = 50;
                }
            }
            //if Mario lands on an enemy that can't be killed
            else if (object->objectType() == PLANT || object->objectType() == ENEMYFIREBALL)
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
            if (object->objectType() == FLAG) 
            {
                //end game
            }
            else if (object->objectType() == FIREFLOWER) 
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
            else if(object->objectType() == COIN) 
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
            if (this->state_ == BIG_STATE && object->objectType() == BREAKABLE) {
                //break block
            }
            else 
            {
                //stop moving
                if (object->objectType() == QUESTION)
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
    
    cout << objt << " top" << endl;
    cout << objl << " left" << endl;
    cout << objr << " right" << endl;
    
    if (!objb && this->getYVelocity() == 0) {
        this->setYVelocity(-2.0);
    }
    if (objb) {
        if (objb->objectType() == BACKGROUND) {
            this->setYVelocity(-2.0);
        }
    }
    //mario jumps into something
    if (objt) {
        //Mario jumps into a reward block
        if (objt->objectType() == QUESTION) {
            Nonbreakable *temp = (Nonbreakable*)objt;
            temp->generateReward(this->getState() != SMALL_STATE);
        } 
        //Mario jumps into a breakable block
        else if (objt->objectType() == BREAKABLE) {
            Breakable *temp = (Breakable*)objt;
            temp->breakBlock(this->getState() != SMALL_STATE);
        }
        //Mario jumps into an enemy
        else if (objt->objectType() == GOOMBA || objt->objectType() == SHELL || objt->objectType() == TURTLE || objt->objectType() == ENEMYFIREBALL) {
            //if Mario is invincible the enemy dies
            if (starCount_ > 0) {
                //kill enemy
            }
            else {
                //change his state or kill Mario
                if (this->getState() == BIG_STATE) {
                    this->state_ = SMALL_STATE;
                    this->setTop(this->top()-16);
                }
                else if (this->getState() == FIRE_STATE) {
                    this->state_ = BIG_STATE;
                    this->setTop(this->top() + 16);
                }
                else {
                    //Mario dies
                    return false;
                }
            }
        }
        //jumps into mushroom
        else if (objt->objectType() == MUSHROOM) {
            //update state
            if (this->state_ == SMALL_STATE) {
                this->state_ = BIG_STATE;
                this->setTop(this->top()+16);
            }
            else {
                //add points
            }
        }
        /*
        else if (objt->objectType() == FIREFLOWER) {
            if (this->getState() == FIRE_STATE) {
                //add points
            }
            else {
                if (this->getState() == SMALL_STATE) {
                    this->setTop(this->top()+16);
                }
                this->state_ = FIRE_STATE;
            }
        }*/
        //star hits Mario from top
        else if (objt->objectType() == STAR) {
            starCount_ = 50;
        }
        //mario jumps into coin
        else if (objt->objectType() == COIN)
        {
            //give Mario coins
        }
        
        this->jumpCount_ = 0;
        this->setYVelocity(-2.0);
    }
    //mario falls on something
    if (objb && this->getYVelocity() < 0) {
        this->setYVelocity(0.0);
        //lands on an enemy
        if (objb->objectType() == GOOMBA || objb->objectType() == SHELL || objb->objectType() == TURTLE || objb->objectType() == ENEMYFIREBALL || objb->objectType() == PLANT) {
            if (starCount_ > 0) {
                //kill enemy
            }
            else {
                //lands on a turtle
                if (objb->objectType() == TURTLE) {
                    //turn turtle into shell
                }
                //lands on plant or fireball
                else if (objb->objectType() == ENEMYFIREBALL || objb->objectType() == PLANT){
                    //Mario Dies
                    return false;
                }
                else {
                    //delete enemy
                }
            }
        }
        //lands on Mushroom
        else if (objb->objectType() == MUSHROOM) {
            if (this->state_ == SMALL_STATE) {
                this->state_ = BIG_STATE;
                this->setTop(this->top()+16);
            }
        }
        //lands on fireflower
        else if (objb->objectType() == FIREFLOWER) {
            if (this->getState() == SMALL_STATE) {
                this->setTop(this->top()+16);
            }
            this->state_ = FIRE_STATE;
        }
        //lands on Coin
        else if (objb->objectType() == COIN) {
            //add points
        }
        //lands on star
        else if (objb->objectType() == STAR){
            starCount_ = 50;
        }
        //lands on block
        else if (objb->objectType() == BREAKABLE || objb->objectType() == REGULAR || objb->objectType() == QUESTION) {
            jumpCount_ = 0;
            this->setYVelocity(0.0);
        }
    }
    //Mario moves to the left
    if (objl && this->getXVelocity() < 0) {
        this->setXVelocity(0.0);
        //runs into enemy on the left
        if (objl->objectType() == GOOMBA || objl->objectType() == SHELL || objl->objectType() == TURTLE || objl->objectType() == ENEMYFIREBALL){
            if (this->starCount_ > 0){
                //enemy dies
            }
            //update state
            else if (this->getState() == BIG_STATE || this->getState() == FIRE_STATE){
                if (this->getState() == BIG_STATE) {
                    this->setTop(this->top()-16);
                }
                this->state_--;
            }
            else{
                return false;
            }
        }
        //runs into block on the left
        else if (objl->objectType() == BREAKABLE || objl->objectType() == REGULAR || objl->objectType() == QUESTION){
            this->setXVelocity(0.0);
        }
        //runs into Mushroom on left
        else if (objl->objectType() == MUSHROOM) {
            if (this->getState() == SMALL_STATE) {
                this->state_ = BIG_STATE;
                this->setTop(this->top()+16);
            }
            else{
                //mario gets points
            }
        }
        //runs into fireflower on left
        else if (objl->objectType() == FIREFLOWER){
            if (this->getState() == FIRE_STATE) {
                //mario gets some points
            }
            else {
                if (this->getState() == SMALL_STATE) {
                    this->setTop(this->top()+16);
                }
                this->state_ = FIRE_STATE;
            }
        }
        //runs into star on left
        else if (objl->objectType() == STAR){
            starCount_ = 50;
        }
        //runs into coin on left
        else if (objl->objectType() == COIN){
            //Mario get some points
            }

        
        
        
    }
    else if ((!objl && leftKey_)) {
        this->setXVelocity(-1.0);
    }
    //Mario is moving to the right
    if (objr && this->getXVelocity() > 0) {
        this->setXVelocity(0.0);
        //runs into an enemy  on the right
        if (objr->objectType() == GOOMBA || objr->objectType() == SHELL || objr->objectType() == TURTLE || objr->objectType() == ENEMYFIREBALL){
            if (this->starCount_ > 0){
                //enemy dies
            }
            //update mario's state
            else if (this->getState() == BIG_STATE || this->getState() == FIRE_STATE){
                if (this->getState() == BIG_STATE) {
                    this->setTop(this->top()-16);
                }
                this->state_--;
            }
            else{
                return false;
            }
        }
        //runs into a block on the right
        else if (objr->objectType() == BREAKABLE || objr->objectType() == REGULAR || objr->objectType() == QUESTION){
            this->setXVelocity(0.0);
        }
        //runs into mushroom on the right
        else if (objr->objectType() == MUSHROOM) {
            if (this->getState() == SMALL_STATE) {
                this->state_ = BIG_STATE;
                this->setTop(this->top()+16);
            }
            else{
                //mario gets points
            }
        }
        //runs into fireflower on the right
        else if (objr->objectType() == FIREFLOWER){
            if (this->getState() == FIRE_STATE) {
                //mario gets some points
            }
            else {
                if (this->getState() == SMALL_STATE) {
                    this->setTop(this->top()+16);
                }
                this->state_ = FIRE_STATE;
            }
        }
        //runs into star on the right
        else if (objr->objectType() == STAR){
            starCount_ = 50;
        }
        //runs into a coin on the right
        else if (objr->objectType() == COIN){
            //Mario get some points
        }
    }
    
    else if (!objr && rightKey_) {
        this->setXVelocity(1.0);
    }
    //Mario Falls off the screen
    if (this->top() <= 0)
    {
        isDead_ = true;
        return false;
    }
    //Mario's left bound so he cant move left past screen
    if (this->left() < leftBound_ && this->getXVelocity() < 0)
    {
        this->setXVelocity(0.0);
    }
    return true;
}
//------------------------------------------------------------
//Creates a fireball
bool Mario::fireball()
{
	return false;
}
//------------------------------------------------------------
void Mario::setLeftBound(int leftBound)
{
    leftBound_ = leftBound;
}
//------------------------------------------------------------
void Mario::sprite()
{
    texturePos = 0;
    
    // Mac environment variable for home directory
    char *cHomeDir = NULL;
    
    cHomeDir = getenv("HOME");
    
    // I think Windows uses HOMEPATH
    if (!cHomeDir) {
        cHomeDir = getenv("HOMEPATH");
    }
    string homeDir = cHomeDir;
    string iName, jName;
    homeDir += "/CS330/sprites/";
    
    string pos;
    int height = 32;
    
    for (int j = 0; j<=2; ++j) {
        stringstream out0;
        //Generates Filename
        jName = homeDir;
        out0<<j;
        pos = out0.str();
        jName+=pos;
        jName+="mario";
        
        if (j != 0) {
            height = 64;
        }
        
        
        
        for (int i = 0; i<=3; ++i) {
            stringstream out1;
            //Generates Filename
            iName = jName;
            out1<<i;
            pos = out1.str();
            iName += pos;
            iName += ".tex";
            
            
            FILE *fp = fopen(iName.c_str(), "r");
            unsigned char *texture = new unsigned char[4 * 32 * height];
            if (fread(texture, sizeof(unsigned char), 4 * 32 * height, fp)
                != 4* 32 *height) {
                fprintf(stderr, "error reading %s", iName.c_str());
            }
            fclose(fp);
            
            glGenTextures(1, &texture_[j][i]);
            glBindTexture(GL_TEXTURE_2D, texture_[j][i]);
            
            glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );        
            glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                            GL_LINEAR_MIPMAP_NEAREST );
            glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                            GL_LINEAR );        
            glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                            GL_CLAMP );
            glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                            GL_CLAMP );
            gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 32, height, GL_RGBA,
                              GL_UNSIGNED_BYTE, texture);
            delete [] texture;
            
        }
    }

    
}
