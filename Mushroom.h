/*
 *  Mushroom.h
 *  Movable
 *
 *  Created by Jeremy Sampson on 2/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __MUSHROOM_H__
#define __MUSHROOM_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Mushroom: public Movable {
    
public:
    // constructor
    Mushroom();
    // destructor
    ~Mushroom();
    
    // instance vars
    
    // point value if killed by mario
    int pointValue_;
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _MUSHROOM_H
