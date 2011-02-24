// FireFlower.cpp
// Alex Martishius, John (Jack) Johnson, Jay Bondzeleske
//------------------------------------------------------------
// include header file FireFlower.h
#include "FireFlower.h"
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
//------------------------------------------------------------
// Makes the fireflower appear
void FireFlower::appear(int xCoor, int yCoor) 
{






}
//------------------------------------------------------------
// Makes the fireflower disappear
void FireFlower::disappear(int xCoor, int yCoor) 
{






}
