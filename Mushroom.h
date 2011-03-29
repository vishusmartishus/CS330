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
	// openGL draw method
    virtual void draw();
	
    // constructor
    Mushroom();
    // destructor
    ~Mushroom();  
    
    // methods
    
    // object type
    int objectType() { return mushroom_; }

};

//---------------------------------------------------------

#endif // _MUSHROOM_H
