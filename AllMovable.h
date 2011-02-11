/*
 *  AllMovable.h
 *  Movable
 *
 *  Created by Jeremy Sampson on 2/7/11.
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
    
    // determine if moving
    bool isMoving_;
    // determine if object can fall off edge of
    // non-blocked ledge
    bool canFallOffEdge_;
    // determine if object can kill mario
    bool canKillMario_;
    // determine if object can move
    bool canMove_;
    // direction of object; horizontal/vertical velocity
    double horizontalVelocity_;
    double verticalVelocity_;
    
    // methods
        
    // if mario kills object, call disappear method
    void disappear();
    // if hits edge of block, reverse direction
    void reverseDirection();
    // check to see if object if able to move
    bool canMove();
    
};

//---------------------------------------------------------

#endif // _ALLMOVABLE_H
