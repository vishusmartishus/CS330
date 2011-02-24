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
    return true;
}

//---------------------------------------------------------

void Movable::xReverse()
{
	double xVel = getXVelocity();
	double reversedXVel = -1*xVel;
	setXVelocity(reversedXVel);
}

//---------------------------------------------------------

void Movable::yReverse()
{
	double yVel = getYVelocity();
	double reversedYVel = -1*yVel;
	setXVelocity(reversedYVel);
}

//---------------------------------------------------------

void Movable::move()
{

}

//---------------------------------------------------------
