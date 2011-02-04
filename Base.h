// Jamie Veals, Jay Bondzeleske
//---------------------------------------------------------
//If Base.h is not defined, defines it
#ifndef _BASE_H
#define _BASE_H
//---------------------------------------------------------
// Base class
class Base {
//---------------------------------------------------------    
public:
    // OpenGL abstract method to draw object
    virtual void draw()=0;
    // Setters and getters for the left, right, top, and bottom
    int left() const { return left_ }
    int right() const { return right_ }
    int top() const { return top_ }
    int bottom() const { return bottom_ }
//---------------------------------------------------------
private:
    // Private variables for the left, right, top, and bottom
    int left_, right_, bottom_, top_;
    // Array of three numbers for the color
    float color_[3];    
};
#endif