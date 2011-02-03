// Drawable.h
// Alex Martishius, John (Jack) Johnson, Jay Bondzeleske
//-----------------------------------------
#ifndef _DRAWABLE_H
#define _DRAWABLE_H
#include <iostream>
using namespace std;
#include "Base.h"
//-----------------------------------------
// We let ostream and istream be friend functions,
// so they can access the instance variables needed to
// input/output.
class Drawable:public Base {
    friend std::istream& operator>>(std::istream& is, Drawable &r);
    friend std::ostream& operator<<(std::ostream& os, const Drawable &r);
//-----------------------------------------
public:
	// constructor
	Drawable(int obj=0);
    // Declare the method to decide if the object is touched by Mario.
    bool touched(bool touching);
    // Declare the method to get the x-coordinate.
    int getX(Drawable &d1);
    // Declare the method to get the y-coordinate.
    int getY(Drawable &d1);
    //Declare the method to set the x-coordinate.
    int setX(Drawable &d1);
    //Declare the method to set the y-coordinate.
    int setY(Drawable &d1);

    int killsBottom, killsLeft, killsRight, killsTop, points;





    //-----------------------------------------.
};

#endif