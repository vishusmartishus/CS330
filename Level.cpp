//Level.cpp
//Zach Adams, Alex Strohmeyer, Josh Woods

#include "Level.h"
#include "Drawable.h"
#include <fstream>
using namespace std;

//------------------------------------------------------------
Level::Level()
{




}
//------------------------------------------------------------
void Level::makeLevel()
{
	
	ifstream inFile;
	inFile.open("level/level1.txt");
	
	int xcord= -1, ycord= 18;
	char object;
	
	while (inFile.get(object)) {
		xcord++;
		
		/*at this point the varible 'object' has the next item in the .txt 
		 and here the 'object' and it's xcord and ycord are sent off to the 
		 correct LList*/
		
		if (xcord == 211) {
			ycord --;
			xcord =0;
		}
	}
	




}
//------------------------------------------------------------
void Level::updateExtends()
{




}
//------------------------------------------------------------
void Level::removeDrawable(Drawable *obj)
{




}
