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
    if (dRight == NULL or dLeft == NULL) {
        // check if goomba, mushroom, shell, can fall off edge
        if ((this->objectType() == 7 or this->objectType() == 8 or this->objectType() == 10) and dBelow == NULL) {
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
    
    // call canMove
    b = canMove();
    
    // if b is false, need to turn around
    if (b == false) {
        currentXVelocity = this->getXVelocity();
        currentXVelocity = (-1) * currentXVelocity;
        currentYVelocity = this->getYVelocity();
    }
    else {
        currentXVelocity = this->getXVelocity();
        currentYVelocity = this->getYVelocity();
    }

    
    // update position
    updatedLeft = this->left() + currentXVelocity;
    this->setLeft(updatedLeft);
    updatedRight = this->right() + currentXVelocity;
    this->setRight(updatedRight);
    updatedTop = this->top() + currentYVelocity;
    this->setTop(updatedTop);
    updatedBottom = this->bottom() + currentYVelocity;
    this->setBottom(updatedBottom);
}

//---------------------------------------------------------
