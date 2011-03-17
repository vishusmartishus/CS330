// FireFlower.h
// Jamie Veals, John (Jack) Johnson, Jay Bondzeleske
//------------------------------------------------------------
// If FireFlower.h is not defined, defines it
#ifndef _FIREFLOWER_H
#define _FIREFLOWER_H
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
//------------------------------------------------------------
// Class FireFlower that inherits from Drawable
class FireFlower:public Drawable{
//------------------------------------------------------------
public:
	// Constructor for FireFlower
	FireFlower()
    {






    }
	virtual void draw();
	// Returns object type
	int objectType() { return 4; }
};

#endif