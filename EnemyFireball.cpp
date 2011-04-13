/*
 *  EnemyFireball.cpp
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

//---------------------------------------------------------

#include "EnemyFireball.h"

//---------------------------------------------------------

EnemyFireball::EnemyFireball()
{
	setKillsBottom(true);
	setKillsSide(true);
	setKillsTop(true);
	setPoints(0);
	setXVelocity(0.0);
	setYVelocity(0.0);
}

//---------------------------------------------------------

EnemyFireball::~EnemyFireball()
{
}

//---------------------------------------------------------

void EnemyFireball::draw()
{
    glColor3ub(255, 48, 48);
    glBegin(GL_POLYGON);
    glVertex2d(left(),bottom());
    glVertex2d(right(),bottom());
    glVertex2d(right(),top());
    glVertex2d(left(),top());
    glEnd();
    
    
    
    
    
    
    
    
    
    
    
    
    
}

//---------------------------------------------------------
