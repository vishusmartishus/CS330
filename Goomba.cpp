/*
 *  Goomba.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


//---------------------------------------------------------

#include "Goomba.h"

//---------------------------------------------------------

Goomba::Goomba()
{
	setKillsBottom(true);
	setKillsSide(true);
	setKillsTop(false);
	setPoints(0);
	setXVelocity(2.0);
	setYVelocity(0.0);
}

//---------------------------------------------------------

Goomba::~Goomba()
{
    
}

//---------------------------------------------------------

void Goomba::draw()
{
	glColor3ub(205, 133, 63);
    int i;
    for(i=0;i<4;++i){
        glBegin(GL_POLYGON);
        glVertex2d(left(),bottom());
        glVertex2d(right(),bottom());
        glVertex2d(right(),top());
        glVertex2d(left(),top());
        glEnd();
    }
    
    
    
    

    
    
    
    
}

//---------------------------------------------------------
