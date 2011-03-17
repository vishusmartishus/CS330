// Jamie Veals, Jay Bondzeleske
//------------------------------------------------------------
//If Base.h is not defined, defines it
#ifndef _BASE_H
#define _BASE_H
//------------------------------------------------------------
// Base class
class Base {
//------------------------------------------------------------ 
public:
    // Constructor for Base
    Base()
    {






    }
	// Returns an int to indicate an object
	// Is called by movable and drawable classes to determine which object is in that spot: a reward, enemy, or block
	virtual int objectType();
    // OpenGL abstract method to draw object
    virtual void draw()=0;
    //Sets the isMovable to false
    virtual bool isMovable() const { return false; }
    // Getters for the left, right, top, and bottom
    int left() const { return left_; }
    int right() const { return right_; }
    int top() const { return top_; }
    int bottom() const { return bottom_; }
    // Setters for the left, right, top, and bottom
    void setLeft(int left);
    void setRight(int right);
    void setTop(int top);
    void setBottom(int bottom);
//------------------------------------------------------------
private:
    // Private variables for the left, right, top, and bottom
    int left_, right_, bottom_, top_;

//------------------------------------------------------------
};
//------------------------------------------------------------
// Inline methods
//------------------------------------------------------------
// set the object type to 0
inline int Base::objectType()
{
    return 0;
}
//------------------------------------------------------------
// set left_
inline void Base::setLeft(int left)
{
    left_ = left;
}
 
 //------------------------------------------------------------
 // set right_
 inline void Base::setRight(int right)
 {
 right_ = right;
 }
 //------------------------------------------------------------
 // set top_
 inline void Base::setTop(int top)
 {
 top_ = top;
 }
 //------------------------------------------------------------
 // set botttom_
 inline void Base::setBottom(int bottom)
 {
 bottom_ = bottom;
 }
//------------------------------------------------------------
#endif