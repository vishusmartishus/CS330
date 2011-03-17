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
	//---------------------------------------------------------
    
	// call checkLeft and check Right methods in AllMovable
    // if returned drawable object is NULL, can move returns TRUE
    // if checks fail, returns FALSE, reverse objects direction
	bool canMove();
	//---------------------------------------------------------

	// tells the object to move this step, which means to update its information for one frame.
	// A timer will tell it to reverse its y-direction and a collision on the appropriate side
	// will tell it to reverse its x-direction. All velocities are constant (no acceleration)
	// so the only change in velocity should result from a change in direction, not magnitude.
	// there are no methods to reverse velocity; this change can be handled directly by changing
	// instance variables.
	void updateScene();
    
};

//---------------------------------------------------------

#endif //__MOVABLE_H
