// John (Jack) Johnson, Alex Martishius, Jay Bondzeleske, Jamie Veals
//------------------------------------------------------------

#ifndef _FLAG_H
#define _FLAG_H

//------------------------------------------------------------

#include "Drawable.h"

//------------------------------------------------------------

class Flag:public Drawable{

//------------------------------------------------------------

public:

    Flag()
    {

    }

	virtual ~Flag()
	{

	}

	// OpenGL abstract method to draw object
	virtual void draw();
	// Returns object type FLAG
	virtual int objectType() { return FLAG; }
    // Method to decide and return how many points are awarded by touching the flag at a certain point (touched)
    int flagPoints(int touched);
};
#endif