/*
 *  Movable.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

Movable::Movable()
{

}

//---------------------------------------------------------

Movable::~Movable()
{

}

//---------------------------------------------------------

bool Movable::canMove()
{
    // call checkRight and checkLeft methods
    Drawable *dRight = checkLeft();
    Drawable *dLeft = checkRight();
    Drawable *dBelow = checkBelow();
    
    // if check is NULL, nothing in the way, can move
    if (dRight == NULL || dLeft == NULL) {
        // check if goomba, mushroom, shell, can fall off edge
        if ((this->objectType() == goomba_ || this->objectType() == mushroom_ || this->objectType() == shell_) && dBelow == NULL) {
            // can fall
            this->setYVelocity(2.0);
        }
        // going to hit ground, stop motion in y direction
        else {
            this->setYVelocity(0.0);
        }
        return true;
    }
    else {
        return false;
    }
}


//---------------------------------------------------------

void Movable::updateScene()
{
    bool b;
    double currentXVelocity, currentYVelocity;
    int updatedLeft, updatedRight, updatedTop, updatedBottom;
    
    // get velocities
    currentXVelocity = this->getXVelocity();
    currentYVelocity = this->getYVelocity();
    
    // update position to check next move
    updatedLeft = this->left() + currentXVelocity;
    this->setLeft(updatedLeft);
    updatedRight = this->right() + currentXVelocity;
    this->setRight(updatedRight);
    updatedTop = this->top() + currentYVelocity;
    this->setTop(updatedTop);
    updatedBottom = this->bottom() + currentYVelocity;
    this->setBottom(updatedBottom);
    
    b = canMove();
    
    // if b is false, can't move that direction, reverse x direction
    // if b is true, movement can stay
    if (b == false) {
        // undo potential move
        updatedLeft = this->left() - currentXVelocity;
        this->setLeft(updatedLeft);
        updatedRight = this->right() - currentXVelocity;
        this->setRight(updatedRight);
        updatedTop = this->top() - currentYVelocity;
        this->setTop(updatedTop);
        updatedBottom = this->bottom() - currentYVelocity;
        this->setBottom(updatedBottom);
        
        // reverse x
        currentXVelocity = (-1) * currentXVelocity;
        updatedLeft = this->left() + currentXVelocity;
        this->setLeft(updatedLeft);
        updatedRight = this->right() + currentXVelocity;
        this->setRight(updatedRight);
    }
}

//---------------------------------------------------------
