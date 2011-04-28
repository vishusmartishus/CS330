// Jamie Veals, John (Jack) Johnson, Jay Bondzeleske

//------------------------------------------------------------

#ifndef _FIREFLOWER_H
#define _FIREFLOWER_H

//------------------------------------------------------------

#include "Drawable.h"

//------------------------------------------------------------

class FireFlower:public Drawable{

//------------------------------------------------------------

private:
    GLuint texture_;
    void sprite();

public:

	FireFlower()
    {
        sprite();
    }

	virtual ~FireFlower()
	{

	}

	// OpenGL abstract method to draw object
	virtual void draw(bool update);
	// Returns object type FIREFLOWER
	int objectType() { return FIREFLOWER; }
};

#endif