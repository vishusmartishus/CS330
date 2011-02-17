/*
 *  Goomba.h
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

#include "Movable.h"

//---------------------------------------------------------

class Goomba: public Movable {
    
public:
    // constructor
    Goomba();
    // destructor
    ~Goomba();
    
    // instance vars
    
    // horizontal and vertical velocities
    double horizontalVelocity_, verticalVelocity_;
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _TURTLE_H