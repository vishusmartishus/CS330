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
	Drawable* dRight = this->collisionRight();
    Drawable* dTop = this->paddedTop();
    Drawable* dBottom = this->paddedBottom();
    
    if (dTop == NULL && dBottom == NULL && dRight != NULL)
    {
        return dRight;
    }
    
    return NULL;
}
//---------------------------------------------------------

Drawable* AllMovable::checkLeft()
{
    Drawable* dLeft = this->collisionLeft();
    Drawable* dTop = this->paddedTop();
    Drawable* dBottom = this->paddedBottom();
    
    if (dTop == NULL && dBottom == NULL && dLeft != NULL)
    {
        return dLeft;
    }
    
    return NULL;

}

//---------------------------------------------------------

Drawable* AllMovable::checkTop()
{
    Drawable* dTop = this->collisionTop();
    Drawable* dLeft = this->paddedLeft();
    Drawable* dRight = this->paddedRight();
    
    if(dLeft == NULL && dRight == NULL && dTop != NULL)
    {
        return dTop;
    }
    
    return NULL;

}

//---------------------------------------------------------

Drawable* AllMovable::checkBottom()
{
    Drawable* dBottom = this->collisionBottom();
    Drawable* dLeft = this->paddedLeft();
    Drawable* dRight = this->paddedRight();
    
    if(dLeft == NULL && dRight == NULL && dBottom != NULL)
    {
        return dBottom;
    }
    
    return NULL;
}

//---------------------------------------------------------

Drawable* AllMovable::collisionBottom()
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

Drawable* AllMovable::collisionTop()
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

Drawable* AllMovable::collisionLeft()
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

Drawable* AllMovable::collisionRight()
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

Drawable* AllMovable::paddedRight()
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
		if ((thisRight - 1) >= objLeft && (thisRight - 1) <= objRight)
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
		if ((thisRight - 1) >= objLeft && (thisRight - 1) <= objRight)
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
		if ((thisRight - 1) >= objLeft && (thisRight - 1) <= objRight)
		{
			// return that object
			return item;
		}
	}
    
	return NULL;
}

Drawable* AllMovable::paddedLeft()
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
		if ((thisLeft + 1) >= objLeft && (thisLeft + 1) <= objRight)
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
		if ((thisLeft + 1) >= objLeft && (thisLeft + 1) <= objRight)
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
		if ((thisLeft + 1) >= objLeft && (thisLeft + 1) <= objRight)
		{
			// return that object
			return item;
		}
	}
    
	return NULL;

}

Drawable* AllMovable::paddedTop()
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
		if ((thisTop - 1) >= objBottom && (thisTop - 1) <= objTop)
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
		if ((thisTop - 1) >= objBottom && (thisTop - 1) <= objTop)
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
		if ((thisTop - 1) >= objBottom && (thisTop - 1) <= objTop)
		{
			// return that object
			return item;
		}
	}
    
	return NULL;
}

Drawable* AllMovable::paddedBottom()
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
		if ((thisBottom + 1) >= objBottom && (thisBottom + 1) <= objTop)
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
		if ((thisBottom + 1) >= objBottom && (thisBottom + 1) <= objTop)
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
		if ((thisBottom + 1) >= objBottom && (thisBottom + 1) <= objTop)
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

