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
    GLuint texture_[2];
    int texturePos_;
    void sprite();
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
