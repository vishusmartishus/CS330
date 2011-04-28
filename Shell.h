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
private:    
    GLuint textureShell;
    void sprite();
public:
	// openGL draw method
    virtual void draw(bool update);
	
    // constructor
    Shell();
    // destructor
    ~Shell();
    
    // methods
    virtual bool canMove();
    
    // object type
    int objectType() { return SHELL; }
    
};

//---------------------------------------------------------

#endif // _SHELL_H
