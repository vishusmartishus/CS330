/*
 *  AllMovable.h
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __ALLMOVABLE_H__
#define __ALLMOVABLE_H__

//---------------------------------------------------------

#include "Drawable.h"

//---------------------------------------------------------

class AllMovable: public Drawable {
    
public:
    // constructor
    AllMovable();
    // destructor
    ~AllMovable();
    
    // instance vars

		// direction of object; horizontal/vertical velocity
    double horizontalVelocity_;
    double verticalVelocity_;

    
    // methods
		// passes true if nothing is in front of the object    
	bool checkFront();
	    // passes true if nothing is behind the object    
	bool checkBehind();
	    // passes true if nothing is below the object    
	bool checkBelow();
	    // passes true if nothing is above the object    
	bool checkAbove();
		// getters for velocity
	double getXvelocity();
	double getYvelocity();
    
};

//---------------------------------------------------------

#endif // _ALLMOVABLE_H
