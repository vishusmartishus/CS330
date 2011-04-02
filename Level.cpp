//Level.cpp
//Zach Adams, Alex Strohmeyer, Josh Woods

#include "Level.h"
#include "Drawable.h"
#include <fstream>
#include "Nonbreakable.h"
#include "LList.h"
#include "Coin.h"
#include "Goomba.h"
#include "Turtle.h"
#include "Breakable.h"

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
void Level::makeLevel(int levelNumber)
{
	
	ifstream inFile;
	if (levelNumber== 1){
		inFile.open("levelfiles/level1.txt");
	}
	if (levelNumber== 2){
		inFile.open("levelfiles/level3.txt");
	}
	int xcoord = 0, ycoord = -16;
	char object;
	
	LList(levelBlocks_);
	while (inFile.get(object)) {
		ycoord +=16;
		
		/*at this point the varible 'object' has the next item in the .txt 
		 and here the 'object' and it's xcord and ycord are sent off to the 
		 correct LList*/
		if (object== 'b') {
			//create breakable block
			Breakable *bBlock = new Breakable;
			bBlock->setTop(xcoord  + 16);
			bBlock->setBottom(xcoord);
			bBlock->setLeft(ycoord);
			bBlock->setRight(ycoord + 16);
			//add block to the list
			if (xcoord<208){
				activeBlocks_.append(bBlock);
			}
			else {
				levelBlocks_.append(bBlock);
			}
		}
		if (object== 'B' || object=='M' || object=='C' || object=='S'){
			//create blocks depending on the inside-Shroom/Coin/other
			//The block creation below is for regular blocks and the pointer will change if the block is 
			//supposed to be different, and at the end the block will be placed in the correct LList
			
			Nonbreakable *nBlock = new Nonbreakable(15,15);
			
			if (object== 'M'){
				//delete old nBlock
				delete nBlock;
				Nonbreakable *nBlock = new Nonbreakable(3,8);
			}
			if (object== 'S'){
				//delete old nBlock
				delete nBlock;
				Nonbreakable *nBlock = new Nonbreakable(3,11);
			}
			if (object== 'C'){
				//delete old nBlock
				delete nBlock;
				Nonbreakable *nBlock = new Nonbreakable(3,5);
			}
			
			nBlock->setTop(xcoord  + 16);
			nBlock->setBottom(xcoord);
			nBlock->setLeft(ycoord);
			nBlock->setRight(ycoord + 16);
			//place in correct list
			if (xcoord<208){
				activeBlocks_.append(nBlock);
			}
			else {
				levelBlocks_.append(nBlock);
			}

		}
		if (object== 'c'){
			//create coin
			Coin *coin = new Coin;
			coin->setTop(xcoord  + 16);
			coin->setBottom(xcoord);
			coin->setLeft(ycoord);
			coin->setRight(ycoord + 16);
			//place in correct list
			if (xcoord<208){
				activeDrawable_.append(coin);
			}
			else {
				levelDrawable_.append(coin);
			}
		}
		if (object== 'g'){
			//create goomba
			Goomba *goomba = new Goomba;
			goomba->setTop(xcoord  + 16);
			goomba->setBottom(xcoord);
			goomba->setLeft(ycoord);
			goomba->setRight(ycoord + 16);
			//place in correct list
			if (xcoord<208){
				activeMovable_.append(goomba);
			}
			else {
				levelMovable_.append(goomba);
			}
		}
		if (object== 'k'){
			//create koopa
			Turtle *koopa = new Turtle;
			koopa->setTop(xcoord  + 16);
			koopa->setBottom(xcoord);
			koopa->setLeft(ycoord);
			koopa->setRight(ycoord + 16);
			//place in correct list
			if (xcoord<208){
				activeMovable_.append(koopa);
			}
			else {
				levelMovable_.append(koopa);
			}
		}
		if (ycoord == 162) {
         xcoord += 16;
         ycoord = 0; 
		}
		
		
	}
	inFile.close();
}
//------------------------------------------------------------
void Level::updateExtents(int leftBound, int rightBound)
{
	//removes from the levelDrawable_ llist and adds onto the end of the active list
	while (levelDrawable_.first() != NULL){
		if (levelDrawable_.first()->left() < rightBound){
			Drawable *obj = levelDrawable_.removeFirst();
			activeDrawable_.append(obj);
		}
	}
	
	//removes from the active list when and deleted the object when the right end of an object falls off the left bound
	while (activeDrawable_.first() != NULL){
		if (activeDrawable_.first()->right() < leftBound){
			Drawable *obj = activeDrawable_.removeFirst();
			delete obj;
		}
	}
	
	//removes from the levelMovable_ llist and appends to the active list
	while (levelMovable_.first() != NULL){
		if (levelMovable_.first()->left() < rightBound){
			Drawable *obj = levelMovable_.removeFirst();
			activeMovable_.append(obj);
		}
	}
	
	//removes from the activeMovable_ llist and deletes the object
	while (activeMovable_.first() != NULL){
		if (activeMovable_.first()->right() < leftBound){
			Drawable *obj = activeMovable_.removeFirst();
			delete obj;
		}
	}
	
	//removes from the levelBlocks_ llist and appends to the active list
	while (levelBlocks_.first() != NULL){
		if (levelBlocks_.first()->left() < rightBound){
			Drawable *obj = levelBlocks_.removeFirst();
			activeBlocks_.append(obj);
		}
	}
	
	//removes from the activeBlocks_ llist and deletes the object
	while (activeBlocks_.first() != NULL){
		if (activeBlocks_.first()->right() < leftBound){
			Drawable *obj = activeBlocks_.removeFirst();
			delete obj;
		}
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
	for (i=0; i<10; ++i){
		Nonbreakable *block = new Nonbreakable(15,0);
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
//------------------------------------------------------------
void Level::resetLevel()
{
	//empties the active lists
	while (activeMovable_.first() != NULL){
		Drawable *obj = activeMovable_.removeFirst();
		delete obj;
	}
	while (activeDrawable_.first() != NULL){
		Drawable *obj = activeDrawable_.removeFirst();
		delete obj;
	}
	while (activeBlocks_.first() != NULL){
		Drawable *obj = activeBlocks_.removeFirst();
		delete obj;
	}

	//empties the level Lists
	while (levelMovable_.first() != NULL){
		Drawable *obj = levelMovable_.removeFirst();
		delete obj;
	}
	while (levelDrawable_.first() != NULL){
		Drawable *obj = levelDrawable_.removeFirst();
		delete obj;
	}
	while (levelBlocks_.first() != NULL){
		Drawable *obj = levelBlocks_.removeFirst();
		delete obj;
	}
}