// Jay Bondzeleske, John (Jack) Johnson, Alex Martishius
//------------------------------------------------------------
// If Nonbreakable.h is not defined, defines it
#ifndef _NONBREAKABLE_H
#define _NONBREAKABLE_H
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
//------------------------------------------------------------
// Nonbreakable class
class Nonbreakable:public Drawable {
//------------------------------------------------------------
public:
    // Nonbreakable constructor
    Nonbreakable()
    {






    }
	virtual void draw();
	// Returns object type
	virtual int objectType() { return 3; }
    // generateReward method that creates an award
	// isLarge is bool that tells if Mario is big or small
	// reward is an int that tells which reward
    void generateReward(bool isLarge, int reward);
	// Checks to see if there is a reward in the nonbreakable box
	bool hasReward(int item = -1);

	//objecttype 15

private:
    // Two types of blocks (Question, Regular)
    int type[2];
};
#endif

