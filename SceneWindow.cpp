#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <glut.h>
#include <GL/gl.h>
#endif

#include <iostream>

#include "SceneWindow.h"
#include "Mario.h"
#include "Level.h"
#include "LList.h"
#include "LListIterator.h"

extern SceneWindow *sw;
Mario *mario;

SceneWindow::SceneWindow(int argc, char **argv)
{
	// create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(512, 448);
    glutInitWindowPosition(30, 100);
    glutCreateWindow("Mario");
	
	
    // GLUT callbacks
	glutDisplayFunc(&SceneWindow::displayFunc);
    glutKeyboardFunc(&SceneWindow::keyboardFunc);
	glutKeyboardUpFunc(&SceneWindow::keyboardUpFunc);
	glutIgnoreKeyRepeat(true);
	
	
    
    // initialize orthographic viewing projections
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 256, 0, 224);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	// view port initializer
	viewportWidth_ = 16;
	viewportHeight_ = 16;
	viewportLeftX_ = 0;
	viewportRightX_ = viewportLeftX_ + viewportWidth_;
	glViewport(0, 0, viewportWidth_, viewportHeight_);
	
	glClearColor(0.7, 0.9, 1.0, 1.0);
	
	startGame();
	
	glutPostRedisplay();
}

//----------------------------------------------------------------------

void SceneWindow::mainLoop()
{
    glutMainLoop();
}

//----------------------------------------------------------------------

void SceneWindow::startGame()
{
	
	//set intial variables

	//PONG
    // initial ball position
    //ballPosition_.set(width_ - 10, height_ / 2);
    //
    //// get a random number from -1.25 to 1.25
    //float y = (random() % 11 - 5) / 4.0;
    //// use it to initialize ball velocity
    //ballVelocity_.set(-2, y);
    //ballVelocity_.normalize();
    //// make velocity vector have magnitude 3
    //ballVelocity_ = 3.0 * ballVelocity_;

    //// start playing
    //playing_ = true;
    glutTimerFunc(10, &SceneWindow::timerFunc, 0);
	sw->loadLevel();
}

//----------------------------------------------------------------------

void SceneWindow::loadLevel()
{
	//called from start game
	//loads in current level from set checkpoint
	Level *level_ = Level::sharedLevel();
	level_->loadTestLevel();
	mario = new Mario();
}

//----------------------------------------------------------------------

void SceneWindow::displayFunc()
{
    sw->displayCB();
}

//----------------------------------------------------------------------

void SceneWindow::keyboardFunc(unsigned char key, int x, int y)
{
    sw->keyboardCB(key, x, y);
}

//----------------------------------------------------------------------

void SceneWindow::keyboardUpFunc(unsigned char key, int x, int y)
{
    sw->keyboardUpCB(key, x, y);
}

//----------------------------------------------------------------------

void SceneWindow::timerFunc(int value)
{
    sw->timerCB(value);
}

//----------------------------------------------------------------------

void SceneWindow::displayCB()
{    
    // clear window
    glClear(GL_COLOR_BUFFER_BIT);
	
	//----------------------------
	//show grid on screen
	
	glColor3f(0,0,0);
	int i;
	for(i=0;i<14;++i){
		glBegin(GL_LINES);
		glVertex2d(0,(i*16));
		glVertex2d(256,(i*16));
		glEnd();
	}
	
	int j;
	for(j=0;j<16;++j){
		glBegin(GL_LINES);
		glVertex2d((j*16),0);
		glVertex2d((j*16), 224);
		glEnd();
	}
	//---------------------------
	
	Level *level_ = Level:: sharedLevel();
	//LList movable = level_->getActiveMovable();
	//LList drawable = level_->getActiveDrawable();
	LList blocks = level_->getActiveBlocks();
	LListIterator li;
	//li.init(movable);
	Drawable *item;
	
	/*
	while (item = li.next()) {
		item->draw();
	}
	li.init(drawable);
	while (item = li.next()) {
		item->draw();
	}
	 */
	li.init(blocks);
	while (item = li.next()) {
		item->draw();
	}
	 
	/*
	li.init(blocks);
	for (int i = 0; i<15; ++i) {
		item = li.next();
		item->draw();
	}
*/
	
    // force screen update
    glFlush();
	glutSwapBuffers();
}

//----------------------------------------------------------------------

void SceneWindow::keyboardCB(unsigned char key, int x, int y)
{
	//need to figure out multiple key presses
	
    if (key == 'q') {
        exit(0);
	}
	else if (key == 'p') {
        //pause
	}
	else
	{
		//call update mario to move
		mario->updateKeyDown(key);
	}
}

//----------------------------------------------------------------------

void SceneWindow::keyboardUpCB(unsigned char key, int x, int y)
{
    mario->updateKeyUp(key);
	//call update mario to move
}

//----------------------------------------------------------------------

void SceneWindow::timerCB(int value)
{
	// look at where mario is
	// update extents in level class
	// iterate through objects and move them
	// redraw   

	//Level *level_ = Level:: sharedLevel();
	//level_->updateExtents(viewportLeftX_, viewportRightX_);
	//LList movable = level_->getActiveMovable();
	//LListIterator li;
	//li.init(movable);
	//Drawable *item;
	//while (item = li.next()) {
	//	item->updateScene();
	//}
	//mario->updateScene();
	glutPostRedisplay();

}

//----------------------------------------------------------------------

