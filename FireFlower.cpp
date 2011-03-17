// FireFlower.cpp
// John (Jack) Johnson, Jay Bondzeleske, Jamie Veals
//------------------------------------------------------------
// include header file FireFlower.h
#include "FireFlower.h"
// include header file Scene.h
#include "Level.h"
//------------------------------------------------------------
void FireFlower::draw()
{
	
	glColor3i(255, 140, 0);
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
