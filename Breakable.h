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
    // breakBlock method that destroys blocks
    // isLarge is bool that tells if Mario is big or small
    // xCoor is x coordinate for block
    // yCoor is y coordinate for block
    void breakBlock(bool isLarge_, int xCoor_, int yCoor_);
    // create method that creates the boxes
    // xCoor is x coordinate for block
    // yCoor is y coordinate for block
    void create(int xCoor_, int yCoor_);
};
#endif