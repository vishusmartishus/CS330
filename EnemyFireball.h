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
	// openGL draw method
    virtual void draw();
	
    // constructor
    EnemyFireball();
    // destructor
    ~EnemyFireball();
    
    // methods
    
    // object type
    int objectType() { return 13; }
    
};

//---------------------------------------------------------

#endif // _ENEMYFIREBALL_H
