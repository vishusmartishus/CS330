// John (Jack) Johnson, Alex Martishius, Jay Bondzeleske
//------------------------------------------------------------
// include header file
#include "Flag.h"
//------------------------------------------------------------
void Flag::draw()
{
	
	glColor3ub(220,220,220);
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
// returns the points based on where flag is touched
int Flag::flagPoints(int touched)
{
	if (touched = 1) {
		return 200;
	}
	else if (touched = 2) {
		return 400;
	}
	else if (touched = 3) {
		return 800;
	}
	else if (touched = 4) {
		return 2000;
	}
	else {
		return 5000;
	}
}
