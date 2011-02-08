// Jay Bondzeleske, John (Jack) Johnson, Alex Martishius
//------------------------------------------------------------
// If Nonbreakable.h is not defined, defines it
#ifndef _NONBREAKABLE_H
#define _NONBREAKABLE_H
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
//------------------------------------------------------------
// Nonbreakable class
class Nonbreakable:public Drawable {
//------------------------------------------------------------
public:
    // Nonbreakable constructor
    Nonbreakable()
    {






    }
    // create Method that creates the block
    void create();
    // generateReward method that creates an award
    void generateReward();
    // redraw method that redraws the block
    void redraw();
    // Three types of blocks (Question, Regular, and Blocks little Mario cannot break)
    int type[3];
    // Three different contents (Mushroom, Fire Floiwer, and Coin)
    int content[3];
};
#endif

