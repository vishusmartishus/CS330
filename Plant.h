/*
 *  Plant.h
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __PLANT_H__
#define __PLANT_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Plant: public Movable {
    
public:
    // constructor
    Plant();
    // destructor
    ~Plant();
    
    // instance vars

    
    // methods

    
    // openGL draw method
    virtual void draw()=0;
    // method to shoot fireball from plant
    void shootFireball();
	// plant's move is different from the normal move
	void move();
};

//---------------------------------------------------------

#endif // _PLANT_H
