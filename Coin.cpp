// Coin.cpp
// John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------
// include header file Coin.h
#include "Coin.h"
// include header file Scene.h
#include "Level.h"
//------------------------------------------------------------
void Coin::draw()
{
	
	glColor3i(255, 255, 0);
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


