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
	
    if (reward_== 0) {
        glColor3ub(199, 133, 64);
    }
	else{
        glColor3ub(255,255,51);
    }
	
	
    glBegin(GL_POLYGON);
    glVertex2d(left(),bottom());
    glVertex2d(right(),bottom());
    glVertex2d(right(),top());
    glVertex2d(left(),top());
    glEnd();
	
    
    if (reward_ == 0) {
        
        glColor3ub(0, 0, 0);
        
        glPointSize(2.0);
        
        glBegin(GL_POINTS);
        glVertex2d(left()+2, bottom()+2);
        glVertex2d(left()+2, top()-2);
        glVertex2d(right()-2, bottom()+2);
        glVertex2d(right()-2, top()-2);
        glEnd();
        

    }
    else{
        
        glColor3ub(255, 0, 0);
        
        glBegin(GL_POLYGON);
        glVertex2d(left()+6, bottom()+6);
        glVertex2d(left()+10, bottom()+6);
        glVertex2d(left()+10, bottom()+14);
        glVertex2d(left()+6, bottom()+14);
        glEnd();
        
        glBegin(GL_POLYGON);
        glVertex2d(left()+6, bottom()+2);
        glVertex2d(left()+10, bottom()+2);
        glVertex2d(left()+10, bottom()+4);
        glVertex2d(left()+6, bottom()+4);
        glEnd();
        
    }
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(left(), bottom());
    glVertex2d(left(), top());
    glVertex2d(right(), top());
    glVertex2d(right(), bottom());
    glEnd();
         
    
  
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
