/*
 *  Shell.h
 *  Movable
 *
 *  Created by Jeremy Sampson on 2/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SHELL_H__
#define __SHELL_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Shell: public Movable {
    
public:
    // constructor
    Shell();
    // destructor
    ~Shell();
    
    // instance vars
    
    // point value if killed by mario
    int pointValue_;
    // determine if can fall off of edge
    bool cliffDetection_;
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _SHELL_H
