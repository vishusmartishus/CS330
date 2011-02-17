//Level.h 
//Zach Adams, Alex Strohmeyer, Josh Woods
//------------------------------------------------------------
#ifndef _LEVEL_H
#define _LEVEL_H
//------------------------------------------------------------
//forward declaration of LList and Drawable
class LList;
class Drawable;
//------------------------------------------------------------
class Level {
//------------------------------------------------------------    
public:
	//constructor for level
	Level();
	//Creates the LLists from a text file
	void makeLevel();
	//updates the active area and activates the relevant drawables, removes inactive items from the front of the list
	void updateExtends();
	//iterates through the llist to find and remove the object
	void removeDrawable(*Drawable);
//------------------------------------------------------------
private:
	// 6 LLists 3 active 3 inactive
	// levelDrawable_ and activeDrawable contain only coins, fire flowers, and the flag
	LList levelMovable_, levelDrawable_, levelBlocks_, activeMovable_, activeDrawable_, activeBlocks_;
};
#endif