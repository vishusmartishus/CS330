// Jay Bondzeleske, John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------

#ifndef _COIN_H
#define _COIN_H

//------------------------------------------------------------

#include "Drawable.h"

//------------------------------------------------------------

class Coin:public Drawable{

//------------------------------------------------------------

private:
    GLuint texture_;
    void sprite();
public:
	Coin()
    {
        
        sprite(); 





    }

	virtual ~Coin()
	{

	}

	// OpenGL abstract method to draw object
	virtual void draw();
	// Returns object type COIN
	int objectType() { return COIN; }
};



#endif