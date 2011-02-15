/*
 *  Movable.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


#ifndef __STAR_H__
#define __STAR_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Star: public Movable {
    
public:
    // constructor
    Star();
    // destructor
    ~Star();
    
    // instance vars
    bool isReward, canKill, canKillFromTop, turnsAround, canFallOff;
    double horizontalVelocity, verticalVelocity, numPoints;
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _STAR_H
