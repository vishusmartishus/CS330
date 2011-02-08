// FireFlower.h
// Alex Martishius, John (Jack) Johnson, Jay Bondzeleske
//-----------------------------------------
#ifndef _FIREFLOWER_H
#define _FIREFLOWER_H
#include <iostream>
//-----------------------------------------
// We let ostream and istream be friend functions,
// so they can access the instance variables needed to
// input/output.
class FireFlower {
    friend std::istream& operator>>(std::istream& is, FireFlower &r);
    friend std::ostream& operator<<(std::ostream& os, const FireFlower &r);
//-----------------------------------------
public:
	// constructor
	FireFlower();
    //-----------------------------------------
    // Declare the method to appear
    void appear(FireFlower &f1);
    // Declare the method to disappear
    void disappear(FireFlower &f1);
    // Declare the method to create Fire Mario.
    void createFireMario();








    //-----------------------------------------.
};

#endif