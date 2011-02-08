// Drawable.h
// Alex Martishius, John (Jack) Johnson, Jay Bondzeleske
//-------------------------------------------------------------
// If Drawable.h is not defined, defines it
#ifndef _DRAWABLE_H
#define _DRAWABLE_H
//-------------------------------------------------------------
// Includes the Base.h file
#include "Base.h"
//-------------------------------------------------------------
// Forward declaration of scene
class Scene; 
//-------------------------------------------------------------
// Drawable class that inherits the Base class
class Drawable:public Base {
//-------------------------------------------------------------
public:
	// constructor
    // s is the scene that holds this Drawable
	Drawable(Scene *s);
    // Declare the method to get the x-coordinate.
    int getX();
    // Declare the method to get the y-coordinate.
    int getY();
    // Declare the method to set the x-coordinate.
    int setX();
    // Declare the method to set the y-coordinate.
    int setY();
    // Setters and getters for the killsleft, killsright, killstop, and killsbottom
    bool killsFromBottom() const { return killsBottom_ }
    bool killsFromLeft() const { return killsLeft_ }
    bool killsFromRight() const { return killsRight_ }
    bool killsFromTop() const { return killsTop_ }
//-------------------------------------------------------------
private:
    // Determines if it kills Mario from the left, right, top, and bottom
    bool killsBottom_, killsLeft_, killsRight_, killsTop_;
    // Integer number for the points
    int points_;
    // Pointer for the scene
    Scene *scene_;
};

#endif