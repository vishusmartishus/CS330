//Level.h 
//Zach Adams, Alex Strohmeyer, Josh Woods
//------------------------------------------------------------
#ifndef _LEVEL_H
#define _LEVEL_H
//------------------------------------------------------------
#include "LList.h"
//Forward declaration of Drawable
class Drawable;
//------------------------------------------------------------
class Level {
//------------------------------------------------------------    
public:
	//Creates the LLists from a text file
	void makeLevel();
	//updates the active area and activates the relevant drawables, removes inactive items from the front of the list
	void updateExtents(int leftBound, int rightBound);
	//iterates through the llist to find and remove the object
	void removeDrawable(Drawable *obj);
	static Level* sharedLevel();
	~Level();
	//getters for all six linked lists
	LList& getActiveMovable() {return activeMovable_; }
	LList& getActiveDrawable() {return activeDrawable_; }
	LList& getActiveBlocks() {return activeBlocks_; }
	LList& getLevelMovable() {return levelMovable_; }
	LList& getLevelDrawable() {return levelDrawable_; }
	LList& getLevelBlocks() {return levelBlocks_; }
	//creates a line of unbreakable blocks across the bottom for testing
	void loadTestLevel();
//------------------------------------------------------------
private:
	//constructor for level
	Level();
	static bool instanceFlag;
	static Level *single;
	
	// 6 LLists 3 active 3 inactive
	// levelDrawable_ and activeDrawable contain only coins, fire flowers, and the flag
	LList levelMovable_, levelDrawable_, levelBlocks_, activeMovable_, activeDrawable_, activeBlocks_;
};
#endif
