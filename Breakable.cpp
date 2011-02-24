// John (Jack) Johnson, Alex Martishius, Jay Bondzeleske
//------------------------------------------------------------
// include header file Breakable
#include "Breakable.h"
#include "Level.h"
//------------------------------------------------------------
void Breakable::draw()
{


	
	
}
//------------------------------------------------------------
// create block
void Breakable::create(int xCoor, int yCoor)
{
	draw();
	setX(xCoor);
	setY(yCoor);



}

//------------------------------------------------------------
// destroy block
void Breakable::breakBlock(bool isLarge, int xCoor, int yCoor)
{
	if (isLarge == true) {
		level_->removeDrawable(this);
	}





}