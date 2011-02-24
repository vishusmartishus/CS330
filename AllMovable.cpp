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
    Drawable *d;
    
    // get x velocity of self object
    // get x coordinate of self object
    
    // if x velocity is positive (moving right)
    
      // assign object type of -1 for nothing in the way
    
      // iterate through active lists
      // get x velocity of current object
      // get x coordinate of current object
      // if current iteration object's x coordinate + x velocity is less
      // than self object's x coordinate + x velocity
        // going to hit that object
          // determine what object is by object type number
          // decide how to react
          // call kill (remove from active LList)
          // or do nothing if able to pass through
    
        // return that object that will be hit
    
    return d;
}

//---------------------------------------------------------

Drawable* AllMovable::checkLeft()
{
    Drawable *d;
    
    // get x velocity of self object
    // get x coordinate of self object
    
    // if x velocity is negative (moving left)
    
      // assign object type of -1 for nothing in the way
    
      // iterate through active lists
      // get x velocity of current object
      // get x coordinate of current object
      // if current iteration object's x coordinate + x velocity is greater
      // than self object's x coordinate + x velocity
        // going to hit that object
        // determine what object is by object type number
          // decide how to react
          // call kill (remove from active LList)
          // or do nothing if able to pass through
       
        // return that object that will be hit
    
    return d;
}

//---------------------------------------------------------

Drawable* AllMovable::checkAbove()
{
    Drawable *d;
    
    // get y velocity of self object
    // get y coordinate of self object
    
    // if y velocity is positive (moving up)
    
    // assign object type of -1 for nothing in the way
    
    // iterate through active lists
    // get y velocity of current object
    // get y coordinate of current object
    // if current iteration object's y coordinate + y velocity is less
    // than self object's y coordinate + y velocity
      // going to hit that object
      // determine what object is by object type number
        // decide how to react
        // call kill (remove from active LList)
        // or do nothing if able to pass through
    
      // return that object that will be hit
    
    return d;
}

//---------------------------------------------------------

Drawable* AllMovable::checkBelow()
{
    Drawable *d;
    
    // get y velocity of self object
    // get y coordinate of self object
    
    // if y velocity is negative (moving down)
    
    // assign object type of -1 for nothing in the way
    
    // iterate through active lists
    // get y velocity of current object
    // get y coordinate of current object
    // if current iteration object's y coordinate + y velocity is greater
    // than self object's y coordinate + y velocity
      // going to hit that object
      // determine what object is by object type number
        // decide how to react
        // call kill (remove from active LList)
        // or do nothing if able to pass through
    
      // return that object that will be hit
    
    return d;
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

void AllMovable::kill(Drawable *&d)
{
    // get object type
    // if object is mario
      // see how many lives are left
      // if no more lives, remove from active LList
        // signal game over
    // any other object
      // remove from active LList
}

//---------------------------------------------------------
