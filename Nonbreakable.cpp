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
	/* As long as it is a Question block 
     Rewards: 
     Coin - 1
     Mushroom (small Mario) / Fireflower (large Mario) - 2
     Star - 3
     */
    if (type_ == question_) {
        
        if (reward_ == 1) {
            // Create a coin
            Coin *coin = new Coin();
        }
        else if (reward_ == 2) {
            if (isLarge != true) {
                // Create a mushroom
                Mushroom *mushroom = new Mushroom();
            }	
            else {
                // Create a fireflower
                FireFlower *fireFlower = new FireFlower();
            }	
        }
        else {
            // Create a star
            Star *star = new Star();
        }
        /* Change the type from a question block to a regular block 
         once the reward has been generated
         */
        type_ = regular_;
    }
}   
