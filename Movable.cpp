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
    Drawable *dRight = checkRight();
    Drawable *dLeft = checkLeft();
    Drawable *dBottom = checkBottom();
    
	bool keepGoing = true;
    
    // if nothing underneath
	if (dBottom == NULL) {
        if (this->objectType() == TURTLE){
            keepGoing = false;
        }
		// check if goomba, mushroom, shell, can fall off edge
		else {
			this->setYVelocity(-2.0);
		}
	}
    
    // if a block type is underneath
	else {
		if (dBottom->objectType() == REGULAR || dBottom->objectType() == BREAKABLE || dBottom->objectType() == QUESTION || dBottom->objectType() == PIPE) {
			this->setYVelocity(0.0);
		}
        else if (dBottom->objectType() == BACKGROUND){
            this->setYVelocity(-2.0);
        }
	}

    // if nothing to the right or left
    if (dRight != NULL) {
        if (dRight->objectType() == REGULAR || dRight->objectType() == BREAKABLE || dRight->objectType() == QUESTION || dRight->objectType() == PIPE) {
            keepGoing = false;
        }
    }
    
    if (dLeft != NULL) {
        if (dLeft->objectType() == REGULAR || dLeft->objectType() == BREAKABLE || dLeft->objectType() == QUESTION || dLeft->objectType() == PIPE) {
            keepGoing = false;
        }
    }

	return keepGoing;
}


//---------------------------------------------------------

void Movable::updateScene()
{
    bool b;
    double currentXVelocity, currentYVelocity;
    double updatedLeft, updatedRight, updatedTop, updatedBottom;
    
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
        this->setXVelocity(currentXVelocity);
        updatedLeft = this->left() + currentXVelocity;
        this->setLeft(updatedLeft);
        updatedRight = this->right() + currentXVelocity;
        this->setRight(updatedRight);
    }
}

//---------------------------------------------------------
