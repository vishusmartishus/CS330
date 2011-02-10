/*
 *  Walking.h
 *  Movable
 *
 *  Created by Jeremy Sampson on 2/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __WALKING_H__
#define __WALKING_H__

//---------------------------------------------------------

#include "Movable.h"

//---------------------------------------------------------

class Walking: public Movable {
    
public:
    // constructor
    Walking();
    // destructor
    ~Walking();
    
    // instance vars
    
    // determine if object can detect cliffs
    // goomba's can fall off, goomba's cannot
    bool cliffDetection_;
    
    // methods
    
};

//---------------------------------------------------------

#endif // _WALKING_H
