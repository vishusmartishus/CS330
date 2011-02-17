// John (Jack) Johnson, Jay Bondzeleske, Alex Martishius
//------------------------------------------------------------
// If Breakable.h is not defined, defines it
#ifndef _BREAKABLE_H
#define _BREAKABLE_H
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
//------------------------------------------------------------
// Breakable class that inherits the Drawable class
class Breakable:public Drawable{
//------------------------------------------------------------
public:
    //Constructor for Breakable
    Breakable()
    {






    }
	// Returns object type
	int objectType() { return 2; }
    // breakBlock method that destroys blocks
    // isLarge is bool that tells if Mario is big or small
    // xCoor is x coordinate for block
    // yCoor is y coordinate for block
    void breakBlock(bool isLarge, int xCoor, int yCoor);
    // create method that creates the boxes
    // xCoor is x coordinate for block
    // yCoor is y coordinate for block
    void create(int xCoor, int yCoor);
};
#endif