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
    int j;
	
	glColor3ub(199,113,64);
	
    glBegin(GL_POLYGON);
    glVertex2d(left(),bottom());
    glVertex2d(right(),bottom());
    glVertex2d(right(),top());
    glVertex2d(left(),top());
    glEnd();
	
    
    
    for (int i = 0; i<4; ++i) {
        if (i%2 == 1) {
            j = 0;
        }
        else{
            j = 1;
        }
        
        glColor3ub(0, 0, 0);
        glBegin(GL_LINES);
        glVertex2d(left(), bottom()+(i*4));
        glVertex2d(right(), bottom()+(i*4));
        glEnd();
        
        glBegin(GL_LINES);
        glVertex2d(left()+(4*i), j*4);
        glVertex2d(left()+(4*i), (j+1)*4);
        glEnd();
        
        glBegin(GL_LINES);
        glVertex2d(left()+(4*i), (j+2)*4);
        glVertex2d(left()+(4*i), (j+3)*4);
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
    type_ = 15;
    
    //Will need to be redrawn
			

}   
