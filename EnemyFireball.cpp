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
	setXVelocity(0);
	setYVelocity(0);
}

//---------------------------------------------------------

EnemyFireball::~EnemyFireball()
{
    
}

//---------------------------------------------------------

void EnemyFireball::draw()
{
    glColor3i(255, 48, 48);
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
