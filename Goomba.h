/*
 *  Movable.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


#ifndef __GOOMBA_H__
#define __GOOMBA_H__

//---------------------------------------------------------

#include "Walking.h"

//---------------------------------------------------------

class Goomba: public Walking {
    
public:
    // constructor
    Goomba();
    // destructor
    ~Goomba();
    
    // instance vars
    bool isReward, canKill, canKillFromTop, turnsAround, canFallOff;
    double horizontalVelocity, verticalVelocity, numPoints;
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _TURTLE_H