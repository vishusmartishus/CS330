//Jay Bondzeleske, John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------
// include header file
#include "Nonbreakable.h"
//------------------------------------------------------------
void Nonbreakable::draw()
{
	
	glColor3i(199,113,64);
	int i;
	for(i=0;i<4;++i){
		glBegin(GL_POLYGON);
		glVertex2d(left(),bottom());
        glVertex2d(right(),bottom());
        glVertex2d(right(),top());
        glVertex2d(left(),top());
		
		glEnd();
	}
	
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
	if (reward == 1) {
		// Create a coin
	}
	else if (reward == 2) {
		if (isLarge != true) {
			// Create a mushroom
		}	
		else {
			// Create a fireflower
		}	
	}
	else {
		// Create a star
	}
    /* Change the type from a question block to a regular block 
     once the reward has been generated
     */
    type = 15;
    
    //Will need to be redrawn
			

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

