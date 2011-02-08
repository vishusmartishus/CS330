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
    void appear();
    // Declare the method to disappear
    void disappear();
    // Declare the method to create Fire Mario.
    void createFireMario();
};

#endif