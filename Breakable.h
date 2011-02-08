// John (Jack) Johnson, Jay Bondzeleske
//--------------------------------------------------------
// If Breakable.h is not defined, defines it
#ifndef _BREAKABLE_H
#define _BREAKABLE_H
//--------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
//--------------------------------------------------------
// Breakable class that inherits the Drawable class
class Breakable:public Drawable{
//--------------------------------------------------------
//
public:
    // breakBlock method that destroys blocks
    void breakBlock();
    // create method that creates the boxes
    void create();
};
#endif