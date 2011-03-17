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
    int thisRight, objLeft;

	// get right value of object
	thisRight = right();

	while(liBlocks.next(item))
	{
		//get left value of block
		objLeft = item->left();

		// if they are touching return that block
		if (thisRight == objLeft)
		{
			return item;
		}
	}

	while(liMovable.next(item))
	{
		//get left value of movable
		objLeft = item->left();

		// if they are touching return that movable
		if (thisRight == objLeft)
		{
			return item;
		}
	}

	while(liDrawable.next(item))
	{
		//get left value of drawable
		objLeft = item->left();

		// if they are touching return that drawable
		if (thisRight == objLeft)
		{
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
    int thisLeft, objRight;

	// get left value of object
	thisLeft = left();

	while(liBlocks.next(item))
	{
		//get right value of block
		objRight = item->right();

		// if they are touching return that block
		if (thisLeft == objRight)
		{
			return item;
		}
	}

	while(liMovable.next(item))
	{
		//get right value of movable
		objRight = item->right();

		// if they are touching return that movable
		if (thisLeft == objRight)
		{
			return item;
		}
	}

	while(liDrawable.next(item))
	{
		//get right value of drawable
		objRight = item->right();

		// if they are touching return that drawable
		if (thisLeft == objRight)
		{
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
    int thisTop, objBottom;

	// get top value of object
	thisTop = top();

	while(liBlocks.next(item))
	{
		//get bottom value of block
		objBottom = item->bottom();

		// if they are touching return that block
		if (thisTop == objBottom)
		{
			return item;
		}
	}

	while(liMovable.next(item))
	{
		//get bottom value of movable
		objBottom = item->bottom();

		// if they are touching return that movable
		if (thisTop == objBottom)
		{
			return item;
		}
	}

	while(liDrawable.next(item))
	{
		//get bottom value of drawable
		objBottom = item->bottom();

		// if they are touching return that drawable
		if (thisTop == objBottom)
		{
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
    int thisBottom, objTop;

	// get bottom value of object
	thisBottom = bottom();

	while(liBlocks.next(item))
	{
		//get top value of block
		objTop = item->top();

		// if they are touching return that block
		if (thisBottom == objTop)
		{
			return item;
		}
	}

	while(liMovable.next(item))
	{
		//get top value of movable
		objTop = item->top();

		// if they are touching return that movable
		if (thisBottom == objTop)
		{
			return item;
		}
	}

	while(liDrawable.next(item))
	{
		//get top value of drawable
		objTop = item->top();

		// if they are touching return that drawable
		if (thisBottom == objTop)
		{
			return item;
		}
	}

    return NULL;
}

//---------------------------------------------------------

double AllMovable::getXVelocity()
>>>>>>> dreed/master
{
    return horizontalVelocity_;
}

//---------------------------------------------------------

void AllMovable::setXVelocity(double x)
>>>>>>> dreed/master
{
    horizontalVelocity_ = x;
}

//---------------------------------------------------------

void AllMovable::setYVelocity(double y)
>>>>>>> dreed/master
{
    verticalVelocity_ = y;
}

//---------------------------------------------------------

double AllMovable::getYVelocity()
{
    return verticalVelocity_;
}
//---------------------------------------------------------

