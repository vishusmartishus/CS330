/*
 *  Fireball.h
 *  Movable
 *
 *  Created by Jeremy Sampson on 2/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __FIREBALL_H__
#define __FIREBALL_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Fireball: public Movable {
    
public:
    // constructor
    Fireball();
    // destructor
    ~Fireball();
    
    // instance vars
    
    // point value if killed by mario
    int pointValue_;
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _FIREBALL_H
