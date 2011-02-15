/*
 *  Turtle.h
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __TURTLE_H__
#define __TURTLE_H__

//---------------------------------------------------------

#include "Walking.h"

//---------------------------------------------------------

class Turtle: public Walking {
    
public:
    // constructor
    Turtle();
    // destructor
    ~Turtle();
    
    // instance vars
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _TURTLE_H
