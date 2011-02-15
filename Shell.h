/*
 *  Shell.h
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


#ifndef __SHELL_H__
#define __SHELL_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Shell: public Movable {
    
public:
    // constructor
    Shell();
    // destructor
    ~Shell();
    
    // instance vars
    bool isReward, canKill, canKillFromTop, turnsAround, canFallOff;
    double horizontalVelocity, verticalVelocity, numPoints;
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _SHELL_H
