// John (Jack) Johnson, Alex Martishius, Jay Bondzeleske
//------------------------------------------------------------
// include header file Breakable
#include "Breakable.h"
#include "Level.h"
//------------------------------------------------------------
void Breakable::draw()
{
	glColor3ub(151,84,79);
	glBegin(GL_POLYGON);
    glVertex2d(left(),bottom());
    glVertex2d(right(),bottom());
    glVertex2d(right(),top());
    glVertex2d(left(),top());
    glEnd();
	
}
//------------------------------------------------------------
// destroy block
void Breakable::breakBlock(bool isLarge)
{
	if (isLarge == true) {
        Level::sharedLevel()->removeDrawable(this);
	}





}