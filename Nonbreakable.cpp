//Jay Bondzeleske, John (Jack) Johnson, Alex Martishius
//------------------------------------------------------------
// include header file
#include "Nonbreakable.h"
//------------------------------------------------------------
void Nonbreakable::draw()
{
	
	
	
	
	
}
//------------------------------------------------------------
//generateReward function
void Nonbreakable::generateReward(bool isLarge, int reward)
{
	//reward ints, 1=coin, 2=mushroom/fireflower, 3=star
	if (reward == 1) {
		//reward will be a coin
	}
	else if (reward == 2) {
		if (isLarge == true) {
			// Reward will be fireflower
		}	
		else {
			// Reward will be a mushroom
		}	
	}
	else {
		// reward will be a star
	}
			

}   
//-------------------------------------------------------------
bool Nonbreakable::hasReward(int item) {
	if (item > -1) {
	return true;
	}
	else {
	return false;
	}

}

