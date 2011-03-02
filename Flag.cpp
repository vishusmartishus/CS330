// John (Jack) Johnson, Alex Martishius, Jay Bondzeleske
//------------------------------------------------------------
// include header file
#include "Flag.h"
//------------------------------------------------------------
void Flag::draw()
{
	
	glColor3i(220,220,220);
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
// create flag
void Flag::create(int xCoor, int yCoor)
{

	draw();
	setX(xCoor);
	setY(yCoor);


}

//------------------------------------------------------------
// end level
void Flag::endLevel()
{






}