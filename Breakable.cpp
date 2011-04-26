// John (Jack) Johnson, Jay Bondzeleske, Jamie Veals
//------------------------------------------------------------

#include "Breakable.h"
#include "Level.h"

//------------------------------------------------------------

void Breakable::draw()
{
    int j;
 
    glColor3ub(199, 133, 64);
    
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
        glVertex2d(left()+(4*i), bottom()+j*4);
        glVertex2d(left()+(4*i), bottom()+(j+1)*4);
        glEnd();
        
        glBegin(GL_LINES);
        glVertex2d(left()+(4*i), bottom()+(j+2)*4);
        glVertex2d(left()+(4*i), bottom()+(j+3)*4);
        glEnd();
        
    }
	
}

//------------------------------------------------------------

// Method that destroys a block if Mario is big
void Breakable::breakBlock(bool isLarge)
{
	// if Mario is large, the block is removed from the shared level of objects to be drawn
	if (isLarge == true) {
        Level::sharedLevel()->removeDrawable(this);
	}
}