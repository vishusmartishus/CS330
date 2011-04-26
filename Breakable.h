// Jay Bondzeleske, John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------

#ifndef _BREAKABLE_H
#define _BREAKABLE_H

//------------------------------------------------------------

#include "Drawable.h"

//------------------------------------------------------------

class Breakable:public Drawable{

//------------------------------------------------------------

public:

    Breakable()
    {

    }

	virtual ~Breakable()
	{

	}
	 // OpenGL abstract method to draw object
	virtual void draw();
	// Returns object type BREAKABLE
	virtual int objectType() { return BREAKABLE; }
    // BreakBlock method that destroys blocks
	// Mario calls when he hits a block
    // isLarge is bool that tells if Mario is big or small
    void breakBlock(bool isLarge);
};
#endif