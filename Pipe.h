// John (Jack) Johnson, Alex Martishius, Jay Bondzeleske, Jamie Veals
//------------------------------------------------------------
#ifndef _PIPE_H
#define _PIPE_H
//------------------------------------------------------------
#include "Drawable.h"
//------------------------------------------------------------
class Pipe:public Drawable{
	//------------------------------------------------------------
public:
    Pipe()
    {
		
		
		
		
		
    }
	virtual ~Pipe()
	{
	}
	virtual void draw();
	void setType(double type);
	// Returns object type
	virtual int objectType() { return PIPE; };
private:
    // Two types of pipes, top & body
    int type_;	
};
#endif