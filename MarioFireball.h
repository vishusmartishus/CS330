/*
 *  MarioFireball.h
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __MARIOFIREBALL_H__
#define __MARIOFIREBALL_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class MarioFireball: public Movable {
    
public:
	// openGL draw method
    virtual void draw();
	
    // constructor
    MarioFireball();
    // destructor
    ~MarioFireball();
    
    // methods
    
    // object type
    int objectType() { return mariofireball_; }
    
};

//---------------------------------------------------------

#endif // _MARIOFIREBALL_H
