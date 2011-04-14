/*
 *  MarioFireball.cpp
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

//---------------------------------------------------------

#include "MarioFireball.h"

//---------------------------------------------------------

MarioFireball::MarioFireball()
{
	setKillsBottom(false);
	setKillsSide(false);
	setKillsTop(false);
	setPoints(0);
	setXVelocity(0.0);
	setYVelocity(0.0);
}

//---------------------------------------------------------

MarioFireball::~MarioFireball()
{
}

//---------------------------------------------------------

void MarioFireball::draw()
{
    
	glColor3ub(139, 26, 26);
    glBegin(GL_POLYGON);
    glVertex2d(left(),bottom());
    glVertex2d(right(),bottom());
    glVertex2d(right(),top());
    glVertex2d(left(),top());
    glEnd();
    
    
    
    
    
    
    
    
}

//---------------------------------------------------------
