/*
 *  Shell.h
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
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
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _SHELL_H
