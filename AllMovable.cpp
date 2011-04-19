/*
 *  AllMovable.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */

//---------------------------------------------------------

#include "AllMovable.h"
#include "Level.h"
#include "LListIterator.h"

//---------------------------------------------------------

AllMovable::AllMovable()
{
    horizontalVelocity_ = 0.0;
    verticalVelocity_ = 0.0;
}

//---------------------------------------------------------

AllMovable::~AllMovable()
{
}

//---------------------------------------------------------

Drawable* AllMovable::checkRight()
{
    // get instance of level
	Level* level = Level::sharedLevel();
    
	// initialize iterators
	LListIterator liBlocks, liMovable, liDrawable;
	liBlocks.init(level->getActiveBlocks());
	liMovable.init(level->getActiveMovable());
	liDrawable.init(level->getActiveDrawable());
    
    Drawable *item;
    int thisRight, thisTop, thisBottom, objLeft, objRight, objTop, objBottom;
    
	// get right value of object
	thisRight = this->right();
    thisTop = this->top();
    thisBottom = this->bottom();
    
    // iterate through active Blocks list
	while ((item = liBlocks.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();
        objTop = item->top();
        objBottom = item->bottom();
        
		// if the right is in between objects left & right boundaries
		if (thisRight >= objLeft && thisRight <= objRight)
		{
			// check if between top and bottom
            if ((thisTop <= objTop && thisTop > objBottom) || (thisBottom < objTop && thisBottom >= objBottom)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}
    
    // iterate through active Movable list
	while ((item = liMovable.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();
        objTop = item->top();
        objBottom = item->bottom();
        
		// if the right is in between objects left & right boundaries
		if (thisRight >= objLeft && thisRight <= objRight && item != this)
		{
			// check if between top and bottom
            if ((thisTop <= objTop && thisTop > objBottom) || (thisBottom < objTop && thisBottom >= objBottom)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}
    
    // iterate through active Drawable list
	while ((item = liDrawable.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();
        objTop = item->top();
        objBottom = item->bottom();
        
		// if the right is in between objects left & right boundaries
		if (thisRight >= objLeft && thisRight <= objRight)
		{
			// check if between top and bottom
            if ((thisTop <= objTop && thisTop > objBottom) || (thisBottom < objTop && thisBottom >= objBottom)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}

	return NULL;
}

//---------------------------------------------------------

Drawable* AllMovable::checkLeft()
{
    // get instance of level
	Level* level = Level::sharedLevel();
    
	// initialize iterators
	LListIterator liBlocks, liMovable, liDrawable;
	liBlocks.init(level->getActiveBlocks());
	liMovable.init(level->getActiveMovable());
	liDrawable.init(level->getActiveDrawable());
    
    Drawable *item;
    int thisLeft, thisTop, thisBottom, objLeft, objRight, objTop, objBottom;
    
	// get right value of object
	thisLeft = this->left();
    thisTop = this->top();
    thisBottom = this->bottom();
    
    // iterate through active Block list
	while ((item = liBlocks.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();
        objTop = item->top();
        objBottom = item->bottom();
        
		// if the right is in between objects left & right boundaries
		if (thisLeft >= objLeft && thisLeft <= objRight)
		{
			// check if between top and bottom
            if ((thisTop <= objTop && thisTop > objBottom) || (thisBottom < objTop && thisBottom >= objBottom)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}

    // iterate through active Movable list
	while ((item = liMovable.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();
        objTop = item->top();
        objBottom = item->bottom();
        
		// if the right is in between objects left & right boundaries
		if (thisLeft >= objLeft && thisLeft <= objRight && item != this)
		{
			// check if between top and bottom
            if ((thisTop <= objTop && thisTop > objBottom) || (thisBottom < objTop && thisBottom >= objBottom)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}
    
	// iterate through active Drawable list
	while ((item = liDrawable.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();
        objTop = item->top();
        objBottom = item->bottom();
        
		// if the right is in between objects left & right boundaries
		if (thisLeft >= objLeft && thisLeft <= objRight )
		{
			// check if between top and bottom
            if ((thisTop <= objTop && thisTop > objBottom) || (thisBottom < objTop && thisBottom >= objBottom)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}

	return NULL;
}

//---------------------------------------------------------

Drawable* AllMovable::checkTop()
{
    // get instance of level
	Level* level = Level::sharedLevel();
    
	// initialize iterators
	LListIterator liBlocks, liMovable, liDrawable;
	liBlocks.init(level->getActiveBlocks());
	liMovable.init(level->getActiveMovable());
	liDrawable.init(level->getActiveDrawable());
    
    Drawable *item;
    int thisTop, thisLeft, thisRight, objTop, objBottom, objLeft, objRight;
    
	// get right value of object
	thisTop = this->top();
    thisLeft = this->left();
    thisRight = this->right();
    
    // iterate through active Blocks list
	while ((item = liBlocks.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();
        objLeft = item->left();
        objRight = item->right();
        
		// if the top is in between objects top & bottom boundaries
		if (thisTop >= objBottom && thisTop <= objTop)
		{
			if ((thisLeft >= objLeft && thisLeft < objRight) || (thisRight > objLeft && thisRight <= objRight)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}
    
    // iterate through active Movable list
	while ((item = liMovable.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();
        objLeft = item->left();
        objRight = item->right();
        
		// if the top is in between objects top & bottom boundaries
		if (thisTop >= objBottom && thisTop <= objTop && item != this)
		{
			if ((thisLeft >= objLeft && thisLeft < objRight) || (thisRight > objLeft && thisRight <= objRight)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}
    
	// iterate through active Drawable list
	while ((item = liDrawable.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();
        objRight = item->right();
        objLeft = item->left();
        
		// if the top is in between objects top & bottom boundaries
		if (thisTop >= objBottom && thisTop <= objTop)
		{
			if ((thisLeft >= objLeft && thisLeft < objRight) || (thisRight > objLeft && thisRight <= objRight)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}

	return NULL;    
}

//---------------------------------------------------------

Drawable* AllMovable::checkBottom()
{
    
    if (this->objectType() == MARIO && this->getYVelocity() > 0) {
        return NULL;
    }
    
    // get instance of level
	Level* level = Level::sharedLevel();
    
	// initialize iterators
	LListIterator liBlocks, liMovable, liDrawable;
	liBlocks.init(level->getActiveBlocks());
	liMovable.init(level->getActiveMovable());
	liDrawable.init(level->getActiveDrawable());
    
    Drawable *item;
    int thisBottom, thisLeft, thisRight, objTop, objBottom, objLeft, objRight;
    
	// get right value of object
	thisBottom = this->bottom();
    thisLeft = this->left();
    thisRight = this->right();
    
    // iterate through active Blocks list
	while ((item = liBlocks.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();
        objLeft = item->left();
        objRight = item->right();
        
		// if the top is in between objects top & bottom boundaries
		if (thisBottom >= objBottom && thisBottom <= objTop)
		{
			if ((thisLeft >= objLeft && thisLeft < objRight) || (thisRight > objLeft && thisRight <= objRight)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}
    
    // iterate through active Movable list
	while ((item = liMovable.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();
        objRight = item->right();
        objLeft = item->left();
        
		// if the top is in between objects top & bottom boundaries
		if (thisBottom >= objBottom && thisBottom <= objTop && item != this)
		{
			if ((thisLeft >= objLeft && thisLeft < objRight) || (thisRight > objLeft && thisRight <= objRight)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}
    
	// iterate through active Drawable list
	while ((item = liDrawable.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();
        objRight = item->right();
        objLeft = item->left();
        
		// if the top is in between objects top & bottom boundaries
		if (thisBottom >= objBottom && thisBottom <= objTop)
		{
			if ((thisLeft >= objLeft && thisLeft < objRight) || (thisRight > objLeft && thisRight <= objRight)) {
                if (item->objectType() != BACKGROUND) {
                    return item;
                }
            }
		}
	}
    
	return NULL;
}

//---------------------------------------------------------

double AllMovable::getXVelocity()
{
    return horizontalVelocity_;
}

//---------------------------------------------------------

void AllMovable::setXVelocity(double x)
{
    horizontalVelocity_ = x;
}

//---------------------------------------------------------

void AllMovable::setYVelocity(double y)
{
    verticalVelocity_ = y;
}

//---------------------------------------------------------

double AllMovable::getYVelocity()
{
    return verticalVelocity_;
}
//---------------------------------------------------------
