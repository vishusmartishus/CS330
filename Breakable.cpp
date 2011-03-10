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
// destroy block
void Breakable::breakBlock(bool isLarge)
{
	if (isLarge == true) {
		level_->removeDrawable(this);
	}





}