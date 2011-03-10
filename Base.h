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
	// Declare the method to get the x-coordinate and the y-coordinate
    int getX() const { return xCoor_;}
    int getY() const { return yCoor_;}
    // Declare the method to set the x-coordinate.
    // Set to the passed value variable
    void setX( int value );
    // Declare the method to set the y-coordinate.
    // Set to the passed value variable
    void setY( int value );
//------------------------------------------------------------
private:
    // Private variables for the left, right, top, and bottom
    int left_, right_, bottom_, top_, xCoor_, yCoor_;
    // Array of three numbers for the color
    float color_[3];    
};
#endif