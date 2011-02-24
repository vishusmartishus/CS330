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
void FireFlower::create(int xCoor, int yCoor) 
{
    setX(xCoor);
    setY(yCoor);
    draw();



}
//------------------------------------------------------------
// Makes the fireflower disappear
void FireFlower::disappear(int xCoor, int yCoor) 
{
    level_->removeDrawable(this);
}
