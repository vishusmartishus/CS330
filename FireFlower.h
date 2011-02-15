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
    // Declare the method to appear
	// xCoor is x coordinate for fire flower
    // yCoor is y coordinate for fire flower
    void appear(int xCoor_, int yCoor_);
    // Declare the method to disappear
	// xCoor is x coordinate for fire flower
    // yCoor is y coordinate for fire flower
    void disappear(int xCoor_, int yCoor_);
    // Declare the method to create Fire Mario.
    void createFireMario();
};

#endif