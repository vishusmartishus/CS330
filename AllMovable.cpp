/*
 *  AllMovable.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


#include "AllMovable.h"
#include "Level.h"
#include "LListIterator.h"

//---------------------------------------------------------

AllMovable::AllMovable()
{
    horizontalVelocity_ = 0;
    verticalVelocity_ = 0;
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
    int thisRight, objLeft, objRight;

	// get right value of object
	thisRight = this->right();

	// iterate through active Blocks list
	while ((item = liBlocks.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();

		// if the right is in between objects left & right boundaries
		if (thisRight >= objLeft && thisRight <= objRight)
		{
			// return that object
			return item;
		}
	}

	// iterate through active Movable list
	while ((item = liMovable.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();

		// if the right is in between objects left & right boundaries
		if (thisRight >= objLeft && thisRight <= objRight)
		{
			// return that object
			return item;
		}
	}

	// iterate through active Drawable list
	while ((item = liDrawable.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();

		// if the right is in between objects left & right boundaries
		if (thisRight >= objLeft && thisRight <= objRight)
		{
			// return that object
			return item;
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
    int thisLeft, objLeft, objRight;

	// get right value of object
	thisLeft = this->left();

	// iterate through active Block list
	while ((item = liBlocks.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();

		// if the right is in between objects left & right boundaries
		if (thisLeft >= objLeft && thisLeft <= objRight)
		{
			// return that object
			return item;
		}
	}

	// iterate through active Movable list
	while ((item = liMovable.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();

		// if the right is in between objects left & right boundaries
		if (thisLeft >= objLeft && thisLeft <= objRight)
		{
			// return that object
			return item;
		}
	}

	// iterate through active Drawable list
	while ((item = liDrawable.next())) 
	{
		//get left, right, top and bottom of block
		objLeft = item->left();
		objRight = item->right();

		// if the right is in between objects left & right boundaries
		if (thisLeft >= objLeft && thisLeft <= objRight)
		{
			// return that object
			return item;
		}
	}

	return NULL;
}

//---------------------------------------------------------

Drawable* AllMovable::checkAbove()
{
	// get instance of level
	Level* level = Level::sharedLevel();

	// initialize iterators
	LListIterator liBlocks, liMovable, liDrawable;
	liBlocks.init(level->getActiveBlocks());
	liMovable.init(level->getActiveMovable());
	liDrawable.init(level->getActiveDrawable());

    Drawable *item;
    int thisTop, objTop, objBottom;

	// get right value of object
	thisTop = this->top();

	// iterate through active Blocks list
	while ((item = liBlocks.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();

		// if the top is in between objects top & bottom boundaries
		if (thisTop >= objBottom && thisTop <= objTop)
		{
			// return that object
			return item;
		}
	}

	// iterate through active Movable list
	while ((item = liMovable.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();

		// if the top is in between objects top & bottom boundaries
		if (thisTop >= objBottom && thisTop <= objTop)
		{
			// return that object
			return item;
		}
	}

	// iterate through active Drawable list
	while ((item = liDrawable.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();

		// if the top is in between objects top & bottom boundaries
		if (thisTop >= objBottom && thisTop <= objTop)
		{
			// return that object
			return item;
		}
	}

	return NULL;
}

//---------------------------------------------------------

Drawable* AllMovable::checkBelow()
{
	// get instance of level
	Level* level = Level::sharedLevel();

	// initialize iterators
	LListIterator liBlocks, liMovable, liDrawable;
	liBlocks.init(level->getActiveBlocks());
	liMovable.init(level->getActiveMovable());
	liDrawable.init(level->getActiveDrawable());

    Drawable *item;
    int thisBottom, objTop, objBottom;

	// get right value of object
	thisBottom = this->bottom();

	// iterate through active Blocks list
	while ((item = liBlocks.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();

		// if the top is in between objects top & bottom boundaries
		if (thisBottom >= objBottom && thisBottom <= objTop)
		{
			// return that object
			return item;
		}
	}

	// iterate through active Movable list
	while ((item = liMovable.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();

		// if the top is in between objects top & bottom boundaries
		if (thisBottom >= objBottom && thisBottom <= objTop)
		{
			// return that object
			return item;
		}
	}

	// iterate through active Drawable list
	while ((item = liDrawable.next())) 
	{
		//get left, right, top and bottom of block
		objTop = item->top();
		objBottom = item->bottom();

		// if the top is in between objects top & bottom boundaries
		if (thisBottom >= objBottom && thisBottom <= objTop)
		{
			// return that object
			return item;
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

