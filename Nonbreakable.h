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
	// Returns object type
	int objectType() { return 3; }
    // create Method that creates the block
	// xCoor is x coordinate for block
    // yCoor is y coordinate for block
    void create(int xCoor, int yCoor);
    // generateReward method that creates an award
	// isLarge is bool that tells if Mario is big or small
	// reward is an int that tells which reward
    void generateReward(bool isLarge, int reward);
    // redraw method that redraws the block
	// xCoor is x coordinate for block
    // yCoor is y coordinate for block
    void redraw(int xCoor, int yCoor);

private:
    // Three types of blocks (Question, Regular, and Blocks little Mario cannot break)
    int type[3];
    // Four different contents (Mushroom, Fire Flower, Star, and Coin)
    int content[4];
};
#endif

