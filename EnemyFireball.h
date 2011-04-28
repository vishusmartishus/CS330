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
private:
    GLuint texture_[4];
    int texturePos;
    void sprite();
    
public:
	// openGL draw method
    virtual void draw(bool update);
	
    // constructor
    EnemyFireball();
    // destructor
    ~EnemyFireball();
    
    // methods
    
    // object type
    int objectType() { return ENEMYFIREBALL; }
    
};

//---------------------------------------------------------

#endif // _ENEMYFIREBALL_H
