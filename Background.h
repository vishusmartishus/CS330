// Russell Watterson
//------------------------------------------------------------

#ifndef _BACKGROUND_H
#define _BACKGROUND_H

//------------------------------------------------------------

#include "Drawable.h"


//------------------------------------------------------------

class Background:public Drawable{
    
    //------------------------------------------------------------
    
private:
    GLuint texture_;
    void sprite();
    int kind_;
    int height_;
    int width_;
public:
	Background(char kind)
    {
        //Bush
        if (kind == 'u') {
            kind_ = 0;
            width_ = 32;
            height_ = 16;
        }
        else if (kind == 'y'){
            kind_ = 1;
            width_ = 48;
            height_ = 16;
        }
        else if (kind == 'w'){
            kind_ = 2;
            width_ = 64;
            height_ = 16;
        }
        //Cloud
        else if (kind == '1'){
            kind_ = 3;
            width_ = 32;
            height_ = 24;
        }
        else if (kind == '2'){
            kind_ = 4;
            width_ = 48;
            height_ = 24;
        }
        else if (kind == '3'){
            kind_ = 5;
            width_ = 64;
            height_ = 24;
        }
        //Mountain
        else if (kind == '7'){
            kind_ = 6;
            width_ = 48;
            height_ = 19;
        }
        else if (kind == '8'){
            kind_ = 7;
            width_ = 80;
            height_ = 35;
        }
        else if (kind == '8'){
            kind_ = 7;
            width_ = 80;
            height_ = 35;
        }
        
        
        sprite(); 
           
    }
    
	virtual ~Background()
	{
        
	}
    
	// OpenGL abstract method to draw object
	virtual void draw();
	// Returns object type Background
	int objectType() { return BACKGROUND; }
    //return sprite elements
    int getWidth() { return width_; }
    int getHeight() { return height_; }

};



#endif