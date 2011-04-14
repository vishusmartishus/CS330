// Coin.h
// John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------
// If Coin.h is not defined, defines it
#ifndef _COIN_H
#define _COIN_H
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
#include <string>
#include <sstream>
//------------------------------------------------------------
// Class Coin that inherits from Drawable
class Coin:public Drawable{
//------------------------------------------------------------
private:
    GLuint texture_;
    void sprite();
public:
	// Constructor for Coin
	Coin()
    {
        
        sprite(); 





    }
	// Coin destructor
	virtual ~Coin()
	{
	}
	virtual void draw();
	// Returns object type
	int objectType() { return COIN; }
};



#endif