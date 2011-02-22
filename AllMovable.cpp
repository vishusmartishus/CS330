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
    return d;
}

//---------------------------------------------------------

Drawable* AllMovable::checkLeft()
{
    Drawable *d;
    return d;
}

//---------------------------------------------------------

Drawable* AllMovable::checkAbove()
{
    Drawable *d;
    return d;
}

//---------------------------------------------------------

Drawable* AllMovable::checkBelow()
{
    Drawable *d;
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

}

//---------------------------------------------------------
