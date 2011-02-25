/*
 *  Movable.h
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


#ifndef __MOVABLE_H__
#define __MOVABLE_H__

//---------------------------------------------------------

#include "AllMovable.h"

//---------------------------------------------------------

class Movable: public AllMovable {

public:
    // constructor
    Movable();
    // destructor
    ~Movable();

    // methods
    
	// scans movable and drawable arrays and decides if they can move
	// uses "above" bools to decide how to react
	bool canMove();
	// methods to reverse x or y velocity
	void xReverse();
	void yReverse();
	// tells the object to move this step
	void move();
    
};

//---------------------------------------------------------

#endif //__MOVABLE_H
