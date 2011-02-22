/*
 *  Shell.h
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


#ifndef __SHELL_H__
#define __SHELL_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Shell: public Movable {
    
public:
	// openGL draw method
    virtual void draw();
	
    // constructor
    Shell();
    // destructor
    ~Shell();
    
    // methods
    

    
};

//---------------------------------------------------------

#endif // _SHELL_H
