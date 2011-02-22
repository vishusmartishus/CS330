/*
 *  AllMovable.h
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
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
    
    // methods
    
    // passes true if nothing is in front of the object    
	Drawable* checkRight();
    // passes true if nothing is behind the object    
	Drawable* checkLeft();
    // passes true if nothing is below the object    
	Drawable* checkBelow();
    // passes true if nothing is above the object    
	Drawable* checkAbove();
    // getters for velocity
	double getXVelocity();
	double getYVelocity();
    // setters for velocity
    void setXVelocity(double x);
    void setYVelocity(double y);

    // kills object
	void kill(Drawable *&d);
    
private:
    // instance vars
    
    // direction of object; horizontal/vertical velocity
    double horizontalVelocity_;
    double verticalVelocity_;
    
};

//---------------------------------------------------------

#endif // _ALLMOVABLE_H
