//------------------------------------------------------------
// include header file Coin.h
#include "Pipe.h"
// include header file Scene.h
#include "Level.h"
//------------------------------------------------------------
void Pipe::draw()
{
	if (type_ == 0) {
		glColor3ub(0, 255, 0);
		glBegin(GL_POLYGON);
		glVertex2d(left(),bottom());
		glVertex2d(right(),bottom());
		glVertex2d(right(),top());
		glVertex2d(left(),top());
		glEnd();
	}
	if (type_ == 1) {
		glColor3ub(100, 255, 100);
		glBegin(GL_POLYGON);
		glVertex2d(left(),bottom());
		glVertex2d(right(),bottom());
		glVertex2d(right(),top());
		glVertex2d(left(),top());
		glEnd();
	}
	
	
}

void Pipe::setType(double type)
{
    type_ = type;
}