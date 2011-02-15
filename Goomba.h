/*
 *  Goomba.h
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
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
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _TURTLE_H