/*
 *  Mushroom.h
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


#ifndef __MUSHROOM_H__
#define __MUSHROOM_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Mushroom: public Movable {
    
public:
    // constructor
    Mushroom();
    // destructor
    ~Mushroom();
    
    // instance vars
    bool isReward, canKill, canKillFromTop, turnsAround, canFallOff;
    double horizontalVelocity, verticalVelocity, numPoints;
    
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _MUSHROOM_H
