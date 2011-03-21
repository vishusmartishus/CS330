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
	// Breakable destructor
	~Breakable()
	{
	}
	virtual void draw();
	// Returns object type
	virtual int objectType() { return 2; }
    // breakBlock method that destroys blocks
	// Mario calls when he hits a block
    // isLarge is bool that tells if Mario is big or small
    void breakBlock(bool isLarge);
};
#endif