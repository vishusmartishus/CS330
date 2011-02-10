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
    void create();
    // EndLevel method that ends teh level
    void endLevel();
     // FlagPoints array of flag points awarded
    int flagPoints[5]; 
};
#endif