// John (Jack) Johnson, Alex Martishius, Jay Bondzeleske, Jamie Veals
//------------------------------------------------------------
#ifndef _PIPE_H
#define _PIPE_H
//------------------------------------------------------------
#include "Drawable.h"
//------------------------------------------------------------
class Pipe:public Drawable{
	//------------------------------------------------------------
private:
    GLuint texture_[2];
    void sprite();
public:
    Pipe()
    {
		sprite();
    }
	virtual ~Pipe()
	{
	}
	virtual void draw(bool update);
	void setType(double type);
	// Returns object type
	virtual int objectType() { return PIPE; };
private:
    // Two types of pipes, top & body
    int type_;	
};
#endif