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
private:
    GLuint texture_[4];
    int texturePos;
    void sprite();
    
public:
	// openGL draw method
    virtual void draw(bool update);
	
    // constructor
    MarioFireball();
    // destructor
    ~MarioFireball();
    
    // methods
    
    // object type
    int objectType() { return MARIOFIREBALL; }
    
};

//---------------------------------------------------------

#endif // _MARIOFIREBALL_H
