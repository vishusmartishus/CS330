//Jay Bondzeleske, John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------
// include header file
#include "Nonbreakable.h"
#include "Star.h"
#include "Mushroom.h"
#include "FireFlower.h"
#include "Coin.h"
//------------------------------------------------------------
void Nonbreakable::draw()
{
	
	
	
	
	
}
//------------------------------------------------------------
//generateReward function
void Nonbreakable::generateReward(bool isLarge)
{
	/* Rewards: 
     Coin - 1
     Mushroom (small Mario) / Fireflower (large Mario) - 2
     Star - 3
     */
	if (reward_ == 1) {
		// Create a coin
		Coin coin = Coin::Coin();
	}
	else if (reward_ == 2) {
		if (isLarge != true) {
			// Create a mushroom
			Mushroom mushroom = Mushroom::Mushroom();
		}	
		else {
			// Create a fireflower
			FireFlower fireFlower = FireFlower::FireFlower();
		}	
	}
	else {
		// Create a star
		Star Star = Star::Star();
	}
    /* Change the type from a question block to a regular block 
     once the reward has been generated
     */
    type_ = 15;
    
    //Will need to be redrawn
			

}   
