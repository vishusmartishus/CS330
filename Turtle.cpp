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
	setXVelocity(0);
	setYVelocity(0);
}

//---------------------------------------------------------

Turtle::~Turtle()
{
    
}

//---------------------------------------------------------

void Turtle::draw()
{
    
	glColor3i(110, 139, 61);
    int i;
    for(i=0;i<4;++i){
        glBegin(GL_POLYGON);
        glVertex2d(getX(),getY());
        glVertex2d(getX()+16,getY());
        glVertex2d(getX()+16,getY()+16);
        glVertex2d(getX(),getY()+16);
        glEnd();
    }
    
    
    
    
    
    
    
    
    
    
    
}

//---------------------------------------------------------
