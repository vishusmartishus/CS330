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
	//---------------------------------------------------------
    
    // returns a drawable object that is causing a collision to the right
	// side of the object. Returns a drawable which has the characteristic
	// of an object type which will tell us what the appropriate action
	// is to take as a result of the collision. If there is no collision,
	// the returned object type will be "-1".
	Drawable* checkRight();
	//---------------------------------------------------------

    // returns a drawable object that is causing a collision to the left
	// side of the object. Returns a drawable which has the characteristic
	// of an object type which will tell us what the appropriate action
	// is to take as a result of the collision. If there is no collision,
	// the returned object type will be "-1".  
	Drawable* checkLeft();
	//---------------------------------------------------------

    // returns a drawable object that is causing a collision underneath
	//  the object. Returns a drawable which has the characteristic
	// of an object type which will tell us what the appropriate action
	// is to take as a result of the collision. If there is no collision,
	// the returned object type will be "-1".    
	Drawable* checkBelow();
	//---------------------------------------------------------

    // returns a drawable object that is causing a collision above
	//  the object. Returns a drawable which has the characteristic
	// of an object type which will tell us what the appropriate action
	// is to take as a result of the collision. If there is no collision,
	// the returned object type will be "-1". 
	Drawable* checkAbove();
	//---------------------------------------------------------

    // getters for velocity. might remove since I'm not sure it's
	// neccessary to get any velocities, as all velocities in the
	// system will be constant, which means we will always know them.
	double getXVelocity();
	double getYVelocity();
	//---------------------------------------------------------

    // setters for velocity. might remove since methods in other 
	// classes will be able to reverse x-directions and y-directions
	// manually, and velocities will remain constant throughout the
	// system over time. 
    void setXVelocity(double x);
    void setYVelocity(double y);
	//---------------------------------------------------------
    
private:
    // instance vars
    
    // direction of object; horizontal/vertical velocity
    double horizontalVelocity_;
    double verticalVelocity_;
    
};

//---------------------------------------------------------

#endif // _ALLMOVABLE_H
