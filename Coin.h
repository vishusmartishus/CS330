// Coin.h
// John (Jack) Johnson
//------------------------------------------------------------
// If Coin.h is not defined, defines it
#ifndef _COIN_H
#define _COIN_H
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
//------------------------------------------------------------
// Class Coin that inherits from Drawable
class Coin:public Drawable{
//------------------------------------------------------------
public:
	// Constructor for Coin
	Coin()
    {






    }
	// Returns object type
	int objectType() { return 5; }
    // Declare the method to appear
	// xCoor is x coordinate for coin
    // yCoor is y coordinate for coin
    void appear(int xCoor, int yCoor);
    // Declare the method to disappear
	// xCoor is x coordinate for coin
    // yCoor is y coordinate for coin
    void disappear(int xCoor, int yCoor);
};

#endif