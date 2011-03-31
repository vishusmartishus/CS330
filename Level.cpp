//Level.cpp
//Zach Adams, Alex Strohmeyer, Josh Woods

#include "Level.h"
#include "Drawable.h"
#include <fstream>
#include "Nonbreakable.h"
using namespace std;

bool Level::instanceFlag = false;
Level* Level::single = NULL;
Level* Level::sharedLevel()
{
	if(! instanceFlag)
	{
		single= new Level();
		instanceFlag = true;
		return single;
	}
	else 
		{
			return single;
		}
	}

//------------------------------------------------------------
Level::Level()
{




}
//------------------------------------------------------------
Level::~Level()
{
	instanceFlag =false;
}
//------------------------------------------------------------
void Level::makeLevel()
{
	
	ifstream inFile;
	inFile.open("level/level1.txt");
	
	int xcoord= -1, ycoord= 18;
	char object;
	
	while (inFile.get(object)) {
		//xcoord++;
		
		/*at this point the varible 'object' has the next item in the .txt 
		 and here the 'object' and it's xcord and ycord are sent off to the 
		 correct LList*/
		
		/*if (xcoord == 211) {
         ycoord --;
         xcoord =0; */
    }



}
//------------------------------------------------------------
void Level::updateExtents(int leftBound, int rightBound)
{
	//removes from the levelDrawable_ llist and adds onto the end of the active list
	while ((levelDrawable_.first() != NULL) && (levelDrawable_.first()->left() < rightBound)){
		Drawable *obj = levelDrawable_.removeFirst();
		activeDrawable_.append(obj);
	}
	
	//removes from the active list when and deleted the object when the right end of an object falls off the left bound
	while ((activeDrawable_.first() != NULL) && (activeDrawable_.first()->right() < leftBound)){
		Drawable *obj = activeDrawable_.removeFirst();
		delete obj;
	}

	//removes from the levelMovable_ llist and appends to the active list
	while ((levelMovable_.first() != NULL) && (levelMovable_.first()->left() < rightBound)){
		Drawable *obj = levelMovable_.removeFirst();
		activeMovable_.append(obj);
	}

	//removes from the activeMovable_ llist and deletes the object
	while ((activeMovable_.first() != NULL) && (activeMovable_.first()->right() < leftBound)){
		Drawable *obj = activeMovable_.removeFirst();
		delete obj;
	}
	
	//removes from the levelBlocks_ llist and appends to the active list
	while ((levelBlocks_.first() != NULL) && (levelBlocks_.first()->left() < rightBound)){
		Drawable *obj = levelBlocks_.removeFirst();
		activeBlocks_.append(obj);
	}

	//removes from the activeBlocks_ llist and deletes the object
	while ((activeBlocks_.first() != NULL) && (activeBlocks_.first()->right() < leftBound)){
		Drawable *obj = activeBlocks_.removeFirst();
		delete obj;
	}
}
//------------------------------------------------------------
void Level::removeDrawable(Drawable *obj)
{
	int type;

	//checks the object type and calls remove on the correct list
	type = obj->objectType();
	if ((type = 1) || (type = 4) || (type = 5)){
		activeDrawable_.removeDrawable(obj);
	}
	else if ((type = 2) || (type = 3) || (type = 15)){
		activeBlocks_.removeDrawable(obj);
	}
	else {
		activeMovable_.removeDrawable(obj);
	}


}
//------------------------------------------------------------
void Level::loadTestLevel()
{
	int left, bottom, i;
	bottom = 0;
	left = 0;
	for (i=0; i<20; ++i){
		Nonbreakable *block = new Nonbreakable(15, 0);
		block->setTop(bottom  + 16);
		block->setBottom(bottom);
		block->setLeft(left);
		block->setRight(left + 16);
		activeBlocks_.append(block);
		left += 16;
	}
}
//------------------------------------------------------------
void Level::addDrawable(Drawable *obj)
{
	//inserts the object to the correct list
	activeDrawable_.insertInSortedOrder(obj);
}
//------------------------------------------------------------
void Level::addMovable(Drawable *obj)
{
	//inserts the object to the correct list
	activeMovable_.insertInSortedOrder(obj);

}
