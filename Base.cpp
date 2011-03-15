// Jamie Veals
//------------------------------------------------------------
// Included the Base.h file
#include "Base.h"
//------------------------------------------------------------

// return the object type
int Base::objectType() 
{
	return 0;
}
//------------------------------------------------------------
// set left_
void Base::setLeft(int left)
{
    left_ = left;
}
//------------------------------------------------------------
// set right_
void Base::setRight(int right)
{
    right_ = right;
}
//------------------------------------------------------------
// set top_
void Base::setTop(int top)
{
    top_ = top;
}
//------------------------------------------------------------
// set botttom_
void Base::setBottom(int bottom)
{
    bottom_ = bottom;
}
//------------------------------------------------------------
// set color_[]
void Base::setColor(float red, float green, float blue)
{
    color_[0] = red;
    color_[1] = green;
    color_[2] = blue;
}