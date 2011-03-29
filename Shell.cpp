/*
 *  Shell.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


//---------------------------------------------------------

#include "Shell.h"

//---------------------------------------------------------

Shell::Shell()
{
	setKillsBottom(true);
	setKillsSide(true);
	setKillsTop(false);
	setPoints(0);
	setXVelocity(2.0);
	setYVelocity(0.0);
}

//---------------------------------------------------------

Shell::~Shell()
{
    
}

//---------------------------------------------------------

void Shell::draw()
{
    
	glColor3ub(153, 50, 204);
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
