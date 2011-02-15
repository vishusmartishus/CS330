/*
 *  Star.h
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
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
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _STAR_H
