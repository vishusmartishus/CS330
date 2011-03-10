//Level.cpp
//Zach Adams, Alex Strohmeyer, Josh Woods

#include "Level.h"
#include "Drawable.h"
#include <fstream>
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
	




}
//------------------------------------------------------------
void Level::updateExtents(int leftBound, int rightBound)
{




}
//------------------------------------------------------------
void Level::removeDrawable(Drawable *obj)
{




}
