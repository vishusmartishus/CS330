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
	// Flag destructor
	virtual ~Flag()
	{
	}
	virtual void draw();
	// Returns object type
	virtual int objectType() { return 1; }
    // Method to decides and returns how many points awarded by touching the flag
    // Touched is the level that the flag was touched
    int flagPoints(int touched);
};
#endif