/*
 *  Star.h
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
	// openGL draw method
    virtual void draw();
	
    // constructor
    Star();
    // destructor
    ~Star();
    
    // methods
    
    // object type
    int objectType() { return star_; }

};

//---------------------------------------------------------

#endif // _STAR_H
