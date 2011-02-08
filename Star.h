/*
 *  Star.h
 *  Movable
 *
 *  Created by Jeremy Sampson on 2/7/11.
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
    
    // point value if killed by mario
    int pointValue_;
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _STAR_H
