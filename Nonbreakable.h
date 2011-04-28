// Jay Bondzeleske, John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------

#ifndef _NONBREAKABLE_H
#define _NONBREAKABLE_H

//------------------------------------------------------------

#include "Drawable.h"

//------------------------------------------------------------

class Nonbreakable:public Drawable {

//------------------------------------------------------------

public:

    // Constructor that uses the object type and the contained reward
    Nonbreakable(int type, int reward = 0)
    {
        // Will set the type of block dependent on the scene's given information
        // Only Question blocks can have rewards that are also set this way
        // Default reward is 0 for none
		type_ = type;
		reward_ = reward;
    }

	virtual ~Nonbreakable()
	{

	}

	// OpenGL abstract method to draw object
	virtual void draw(bool update);
	// Returns object type, either a question block or a regular nonbreakable block
	virtual int objectType() { return type_; }
    // GenerateReward method that creates an award
	// isLarge is bool that tells if Mario is big or small
    void generateReward(bool isLarge);
	
	//---------------------------------------------------------

private:
    // Two types of blocks (Question, Regular)
    int type_;
    // Four different rewards (coin, mushroom, fireflower, star)
    // Mushroom or fireflower is dependent on whether Mario is large or not
    int reward_;
};

//-------------------------------------------------------------

#endif

