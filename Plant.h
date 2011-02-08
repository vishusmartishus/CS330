/*
 *  Plant.h
 *  Movable
 *
 *  Created by Jeremy Sampson on 2/7/11.
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
    
    // point value if killed by mario
    int pointValue_;
    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    // method to shoot fireball from plant
    void shootFireball();
    
};

//---------------------------------------------------------

#endif // _PLANT_H
