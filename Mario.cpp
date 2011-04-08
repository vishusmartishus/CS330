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

GLuint textureMario[10];
int textureMarioPos = 0;

//------------------------------------------------------------
void Mario::draw()
{
    
    if (this->getYVelocity() != 0.0 && this->getXVelocity() >= 0.0) {
        textureMarioPos = 3;
    }
    else if (this->getYVelocity() != 0.0 && this->getXVelocity() < 0.0){
        textureMarioPos = 7;
    }
    else if (this->getXVelocity() > 0.0){
        if (textureMarioPos == 1) {
            textureMarioPos = 2;
        }
        else{
            textureMarioPos = 1;
        }
    }
    else if (this->getXVelocity() < 0.0){
        if (textureMarioPos == 5) {
            textureMarioPos = 6;
        }
        else {
            textureMarioPos = 5;
        }
    }
    else if (textureMarioPos < 4){
        textureMarioPos = 0;
    }
    else{
        textureMarioPos = 4;
    }

    
     
             
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, textureMario[textureMarioPos]);
    
    
    glColor4f(0.7f,0.9f,1.0f,1.0f);
    glBegin( GL_QUADS );
    glTexCoord2d(0.0,0.0); glVertex2d(left(),bottom());
    glTexCoord2d(1.0,0.0); glVertex2d(right(),bottom());
    glTexCoord2d(1.0,1.0); glVertex2d(right(),top());
    glTexCoord2d(0.0,1.0); glVertex2d(left(),top());
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
    
    
    // Mac environment variable for home directory
    char *cHomeDir = NULL;
    
    cHomeDir = getenv("HOME");
    
    // I think Windows uses HOMEPATH
    if (!cHomeDir) {
        cHomeDir = getenv("HOMEPATH");
    }
    string homeDir = cHomeDir;
    string iName;
    homeDir += "/CS330/sprites/mario";
    
    string pos;
    stringstream out;
    
    for (int i = 0; i<8; ++i) {
        stringstream out;
        //Generates Filename
        iName = homeDir;
        out<<i;
        pos = out.str();
        iName += pos;
        iName += ".tex";
        cout<<iName<<endl;
        
        FILE *fp = fopen(iName.c_str(), "r");
        unsigned char *texture = new unsigned char[4 * 256 * 256];
        if (fread(texture, sizeof(unsigned char), 4 * 256 * 256, fp)
            != 4* 256 *256) {
            fprintf(stderr, "error reading %s", iName.c_str());
        }
        fclose(fp);
        
        glGenTextures(1, &textureMario[i]);
        glBindTexture(GL_TEXTURE_2D, textureMario[i]);
        
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL );        
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        GL_LINEAR_MIPMAP_NEAREST );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                        GL_LINEAR );        
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                        GL_CLAMP );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                        GL_CLAMP );
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 256, 256, GL_RGBA,
                          GL_UNSIGNED_BYTE, texture);
        delete [] texture;

    }
    
   
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
    if (!objb && jumpCount_ == 0) {
        this->setYVelocity(-2.0);
    }
    //mario jumps into something
    if (objt) {
        if (objt->objectType() == question_) {
            Nonbreakable *temp = (Nonbreakable*)objt;
            temp->generateReward(this->getState() != SMALL_STATE);
        } else if (objt->objectType() == breakable_) {
            Breakable *temp = (Breakable*)objt;
            temp->breakBlock(this->getState() != SMALL_STATE);
        }
        else if (objt->objectType() == goomba_ || objt->objectType() == shell_ || objt->objectType() == turtle_ || objt->objectType() == enemyfireball_) {
            if (starCount_ > 0) {
                //kill enemy
            }
            else {
                return false;
            }
        }
        else if (objt->objectType() == mushroom_ || objt->objectType() == star_ || objt->objectType() == fireflower_ || objt->objectType() == coin_) {
            //update state
            if (objt->objectType() == mushroom_) {
                if (this->state_ == SMALL_STATE) {
                    this->state_ = BIG_STATE;
                }
                else {
                    //add points
                }
            }
            else if (objt->objectType() == fireflower_) {
                if (this->getState() == FIRE_STATE) {
                    //add points
                }
                else {
                    this->state_ = FIRE_STATE;
                }
            }
            else {
                starCount_ = 50;
            }
        }
        //Up above, waiting for Drew
        this->jumpCount_ = 0;
        this->setYVelocity(-2.0);
    }
    //mario falls on something
    cout << this->getYVelocity() << endl;
    if (objb && this->getYVelocity() < 0) {
        this->setYVelocity(0.0);
        if (objb->objectType() == goomba_ || objb->objectType() == shell_ || objb->objectType() == turtle_ || objb->objectType() == enemyfireball_ || objb->objectType() == plant_) {
            if (starCount_ > 0) {
                //kill enemy
            }
            else {
                if (objb->objectType() == turtle_) {
                    //turn turtle into shell
                }
                else if (objb->objectType() == enemyfireball_ || objb->objectType() == plant_){
                    //Mario Dies
                    return false;
                }
                else {
                    //delete enemy
                }
            }
        }
        else if (objb->objectType() == mushroom_ || objb->objectType() == star_ || objb->objectType() == fireflower_) {
            //update state
            if (objb->objectType() == mushroom_) {
                if (this->state_ == SMALL_STATE) {
                    this->state_ = BIG_STATE;
                }
                else if (objb->objectType() == fireflower_) {
                    this->state_ = FIRE_STATE;
                }
                else {
                    //add points
                }
            }
            else {
                starCount_ = 50;
            }
        }
        else if (objb->objectType() == breakable_ || objb->objectType() == regular_ || objb->objectType() == question_) {
            jumpCount_ = 0;
            this->setYVelocity(0.0);
        }
    }
    //Mario moves to the left
    if (objl && this->getXVelocity() < 0) {
        this->setXVelocity(0.0);
        if (objl->objectType() == goomba_ || objl->objectType() == shell_ || objl->objectType() == turtle_ || objl->objectType() == enemyfireball_){
            if (this->starCount_ > 0){
                //enemy dies
            }
            else if (this->getState() == BIG_STATE || this->getState() == FIRE_STATE){
                this->state_--;
            }
            else{
                return false;
            }
        }
        else if (objl->objectType() == breakable_ || objl->objectType() == regular_ || objl->objectType() == question_){
            this->setXVelocity(0.0);
        }
        else if (objl->objectType() == mushroom_ || objl->objectType() == star_ || objl->objectType() == fireflower_ || objl->objectType() == coin_){
            if (objl->objectType() == mushroom_) {
                if (this->getState() == SMALL_STATE) {
                    this->state_ = BIG_STATE;
                }
                else{
                    //mario gets points
                }
            }
            else if (objl->objectType() == fireflower_){
                if (this->getState() == FIRE_STATE) {
                    //mario gets some points
                }
                else {
                    this->state_ = FIRE_STATE;
                }
            }
            else if (objl->objectType() == star_){
                starCount_ = 50;
            }
            else{
                //Mario get some points
            }
        }
        
    }
    //Mario is moving to the right
    if (objr && this->getXVelocity() > 0) {
        this->setXVelocity(0.0);
        if (objr->objectType() == goomba_ || objr->objectType() == shell_ || objr->objectType() == turtle_ || objr->objectType() == enemyfireball_){
            if (this->starCount_ > 0){
                //enemy dies
            }
            else if (this->getState() == BIG_STATE || this->getState() == FIRE_STATE){
                this->state_--;
            }
            else{
                return false;
            }
        }
        else if (objr->objectType() == breakable_ || objr->objectType() == regular_ || objr->objectType() == question_){
            this->setXVelocity(0.0);
        }
        else if (objr->objectType() == mushroom_ || objr->objectType() == star_ || objr->objectType() == fireflower_ || objr->objectType() == coin_){
            if (objr->objectType() == mushroom_) {
                if (this->getState() == SMALL_STATE) {
                    this->state_ = BIG_STATE;
                }
                else{
                    //mario gets points
                }
            }
            else if (objr->objectType() == fireflower_){
                if (this->getState() == FIRE_STATE) {
                    //mario gets some points
                }
                else {
                    this->state_ = FIRE_STATE;
                }
            }
            else if (objr->objectType() == star_){
                starCount_ = 50;
            }
            else{
                //Mario get some points
            }
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
