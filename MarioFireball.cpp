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
	setXVelocity(0);
	setYVelocity(0);
}

//---------------------------------------------------------

MarioFireball::~MarioFireball()
{
    
}

//---------------------------------------------------------

void MarioFireball::draw()
{
    
	glColor3i(139, 26, 26);
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
