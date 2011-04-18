//Jay Bondzeleske, John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------

#include "Nonbreakable.h"
#include "Star.h"
#include "Mushroom.h"
#include "FireFlower.h"
#include "Coin.h"
#include "Level.h"
#include "Pipe.h"

//------------------------------------------------------------

void Nonbreakable::draw()
{

	if (type_ != REGULAR){
        glColor3ub(255,204,0);
        glBegin(GL_POLYGON);
        glVertex2d(left(),bottom());
        glVertex2d(right(),bottom());
        glVertex2d(right(),top());
        glVertex2d(left(),top());
        glEnd();
	
        if (type_ == QUESTION) {
        
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
        glPointSize(2.0);
    
        glBegin(GL_POINTS);
        glVertex2d(left()+2, bottom()+2);
        glVertex2d(left()+2, top()-2);
        glVertex2d(right()-2, bottom()+2);
        glVertex2d(right()-2, top()-2);
        glEnd();
    
        glColor3ub(0, 0, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(left(), bottom());
        glVertex2d(left(), top());
        glVertex2d(right(), top());
        glVertex2d(right(), bottom());
        glEnd();
    }
    else{
        
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2d(left(), bottom());
        glVertex2d(right(), bottom());
        glVertex2d(right(), top());
        glEnd();
        
        glColor3ub(199, 133, 120);    
        glBegin(GL_POLYGON);
        glVertex2d(right(), top());
        glVertex2d(left(), top());
        glVertex2d(left(), bottom());
        glEnd();

        glColor3b(0, 0, 0);
        glBegin(GL_LINES);
        glVertex2d(left(), bottom());
        glVertex2d(right(), top());
        glEnd();
        
        glColor3ub(199, 133, 64);
        glBegin(GL_LINES);
        glVertex2d(left(), bottom());
        glVertex2d(right(), top());
        glEnd();
        
        glBegin(GL_POLYGON);
        glVertex2d(left()+4, bottom()+4);
        glVertex2d(left()+4, top()-4);
        glVertex2d(right()-4, top()-4);
        glVertex2d(right()-4, bottom()+4);
        glEnd();
        
        
    }
         
    
  
}

//------------------------------------------------------------

//generateReward function
void Nonbreakable::generateReward(bool isLarge)
{
	// if it is a question block decide which reward to give to mario
    if (type_ == QUESTION) {
        
        if (reward_ == COIN) {
            // Create a coin above block it was in and adds drawable coin to the level
            Coin *coin = new Coin();
			coin->setLeft(this->left());
			coin->setRight(this->right());
			coin->setTop(this->top()+16);
			coin->setBottom(this->top());
			Level::sharedLevel()->addDrawable(coin);
        }
        else if (reward_ == MUSHROOM) {
            if (isLarge != true) {
                // Create a mushroom above block it was in and adds drawable coin to the level
                Mushroom *mushroom = new Mushroom();
				mushroom->setLeft(this->left());
				mushroom->setRight(this->right());
				mushroom->setTop(this->top()+16);
				mushroom->setBottom(this->top());
				Level::sharedLevel()->addMovable(mushroom);
            }	
            else {
                // Create a fireflower above block it was in and adds drawable coin to the level
                FireFlower *fireFlower = new FireFlower();
				fireFlower->setLeft(this->left());
				fireFlower->setRight(this->right());
				fireFlower->setTop(this->top()+16);
				fireFlower->setBottom(this->top());
				Level::sharedLevel()->addDrawable(fireFlower);
            }	
        }
        else {
            // Create a star above block it was in and adds drawable coin to the level
            Star *star = new Star();
			star->setLeft(this->left());
			star->setRight(this->right());
			star->setTop(this->top()+16);
			star->setBottom(this->top());
			Level::sharedLevel()->addDrawable(star);
        }
        // once the block has been hit by mario and the reward generated change type to regular from question
        type_ = OFFQUESTION;
    }
}   
