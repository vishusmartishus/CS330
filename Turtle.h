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
private:
    GLuint texture_[4];
    int texturePos_;
public:
	// openGL draw method
    virtual void draw();
	
    // constructor
    Turtle();
    // destructor
    ~Turtle();
    
    // methods
    
    // object type
    int objectType() { return TURTLE; }
    
};

//---------------------------------------------------------

#endif // _TURTLE_H
