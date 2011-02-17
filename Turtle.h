/*
 *  Turtle.h
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


#ifndef __TURTLE_H__
#define __TURTLE_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Turtle: public Movable {
    
public:
    // constructor
    Turtle();
    // destructor
    ~Turtle();
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _TURTLE_H
