// John (Jack) Johnson, Alex Martishius, Jay Bondzeleske
//------------------------------------------------------------
// If Drawable.h is not defined, defines it
#ifndef _FLAG_H
#define _FLAG_H
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
//------------------------------------------------------------
// Class Flag that inherits from Drawable
class Flag:public Drawable{
//------------------------------------------------------------
public:
    // Flag constructor
    Flag()
    {






    }
    // Create method that creates the flag
	// xCoor is x coordinate for flag
    // yCoor is y coordinate for flag
    void create(int xCoor_, int yCoor_);
    // EndLevel method that ends the level
    void endLevel();

private:
     // FlagPoints array of flag points awarded
    int flagPoints[5]; 
};
#endif