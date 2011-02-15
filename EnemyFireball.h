/*
 *  EnemyFireball.h
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __ENEMYFIREBALL_H__
#define __ENEMYFIREBALL_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class EnemyFireball: public Movable {
    
public:
    // constructor
    EnemyFireball();
    // destructor
    ~EnemyFireball();
    
    // instance vars
    

    
    // methods
    
    // openGL draw method
    virtual void draw()=0;
    
};

//---------------------------------------------------------

#endif // _ENEMYFIREBALL_H
