// FireFlower.cpp
// John (Jack) Johnson, Jay Bondzeleske, Jamie Veals
//------------------------------------------------------------
// include header file FireFlower.h
#include "FireFlower.h"
// include header file Scene.h
#include "Level.h"
//------------------------------------------------------------
void FireFlower::draw()
{
	
	
	
	
	
}
//------------------------------------------------------------
// Makes the fireflower appear
void FireFlower::appear(int xCoor, int yCoor) 
{






}
//------------------------------------------------------------
// Makes the fireflower disappear
void FireFlower::disappear(int xCoor, int yCoor) 
{
    level_->removeDrawable(this);
}
