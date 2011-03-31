/*
 *  Turtle.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


//---------------------------------------------------------

#include "Turtle.h"

//---------------------------------------------------------

Turtle::Turtle()
{
	setKillsBottom(true);
	setKillsSide(true);
	setKillsTop(false);
	setPoints(0);
	setXVelocity(2.0);
	setYVelocity(0.0);
}

//---------------------------------------------------------

Turtle::~Turtle()
{
    
}

//---------------------------------------------------------

void Turtle::draw()
{
    
	glColor3ub(110, 139, 61);
    glBegin(GL_POLYGON);
    glVertex2d(left(),bottom());
    glVertex2d(right(),bottom());
    glVertex2d(right(),top());
    glVertex2d(left(),top());
    glEnd();
    
    
    
    
    
    
    
    
    
    
    
}

//---------------------------------------------------------
