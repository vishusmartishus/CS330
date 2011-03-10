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
		glVertex2d(getX(),getY());
		glVertex2d(getX()+16,getY());
		glVertex2d(getX()+16,getY()+16);
		glVertex2d(getX(),getY()+16);
		glEnd();
	}
	
}
