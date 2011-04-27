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
#include "Level.h"

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
    Drawable *dRight = this->checkRight();
    Drawable *dLeft = this->checkLeft();
    Drawable *dBottom = this->checkBottom();
	Drawable *dTop = this->checkTop();

	bool keepGoing = true;
    
	if (this->objectType() == MARIOFIREBALL)
	{
		/*
		bool killed = false;
		if (this->getXVelocity() < 0)
		{
			if (dLeft->objectType() == BREAKABLE || dLeft->objectType() == QUESTION || dLeft->objectType() == PIPE || dLeft->objectType() == OFFQUESTION)
			{
				killed = true;
			}
			else if (dLeft->objectType() == GOOMBA || dLeft->objectType() == TURTLE || dLeft->objectType() == PLANT)
			{
				Level::sharedLevel()->removeDrawable(dLeft);
				killed = true;
			}
		}
		else
		{
			if (dLeft->objectType() == BREAKABLE || dLeft->objectType() == QUESTION || dLeft->objectType() == PIPE || dLeft->objectType() == OFFQUESTION)
			{
				killed = true;
			}
			else if (dRight->objectType() == GOOMBA || dRight->objectType() == TURTLE || dRight->objectType() == PLANT)
			{
				Level::sharedLevel()->removeDrawable(dRight);
				killed = true;
			}
		}
		if (dLeft->objectType() == BREAKABLE || dLeft->objectType() == QUESTION || dLeft->objectType() == PIPE || dLeft->objectType() == OFFQUESTION)
		{
			killed = true;
		}
		else if (dTop->objectType() == GOOMBA || dTop->objectType() == TURTLE || dTop->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dTop);
			killed = true;
		}
		if (dLeft->objectType() == BREAKABLE || dLeft->objectType() == QUESTION || dLeft->objectType() == PIPE || dLeft->objectType() == OFFQUESTION)
		{
			killed = true;
		}
		else if (dBottom->objectType() == GOOMBA || dBottom->objectType() == TURTLE || dBottom->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dBottom);
			killed = true;
		}
		if (killed)
		{
			Level::sharedLevel()->removeDrawable(this);
		}
		*/
	}
	else
	{
		// if nothing underneath
		if ((dBottom == NULL || dBottom == this) || dBottom->objectType() == BACKGROUND || dBottom->objectType() == COIN)
		{
			if (this->objectType() == TURTLE) 
			{
				keepGoing = false;
			}
			// check if goomba, mushroom, shell, can fall off edge
			else 
			{
				this->setYVelocity(-2.0);
			}
		}
    
		// if a block type is underneath
		else 
		{
			if (dBottom->objectType() == REGULAR || dBottom->objectType() == BREAKABLE || dBottom->objectType() == QUESTION || dBottom->objectType() == PIPE || dBottom->objectType() == OFFQUESTION) 
			{
				this->setYVelocity(0.0);
			}
			else if (dBottom->objectType() == BACKGROUND)
			{
				this->setYVelocity(-2.0);
			}
		}

		// if nothing to the right or left
		if (dRight != NULL && dRight->objectType() != BACKGROUND) 
		{
			if (dRight->objectType() == REGULAR || dRight->objectType() == BREAKABLE || dRight->objectType() == QUESTION || dRight->objectType() == PIPE) 
			{
				keepGoing = false;
			}
		}
    
		if (dLeft != NULL && dLeft->objectType() != BACKGROUND) 
		{
			if (dLeft->objectType() == REGULAR || dLeft->objectType() == BREAKABLE || dLeft->objectType() == QUESTION || dLeft->objectType() == PIPE) 
			{
				keepGoing = false;
			}
		}
	}
	if (this->objectType() == SHELL)
	{
		/*
		if (dRight->objectType() == GOOMBA || dRight->objectType() == TURTLE || dRight->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dRight);
		}

		if (dLeft->objectType() == GOOMBA || dLeft->objectType() == TURTLE || dLeft->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dLeft);
		}

		if (dBottom->objectType() == GOOMBA || dBottom->objectType() == TURTLE || dBottom->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dBottom);
		}
		*/
	}

	return keepGoing;
}


//---------------------------------------------------------

void Movable::updateScene()
{
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
        
    // if canMove is false, can't move that direction, reverse x direction
	// if canMove is true, movement can stay
    if (!canMove()) {
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
