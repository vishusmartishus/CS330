// FireFlower.h
// Alex Martishius, John (Jack) Johnson, Jay Bondzeleske
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
    // Declare the method to appear
	// xCoor is x coordinate for fire flower
    // yCoor is y coordinate for fire flower
    void appear(int xCoor, int yCoor);
    // Declare the method to disappear
	// xCoor is x coordinate for fire flower
    // yCoor is y coordinate for fire flower
    void disappear(int xCoor, int yCoor);

};

#endif