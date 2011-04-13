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
#include "Movable.h"

extern SceneWindow *sw;
Mario *mario;
static int p;
const int WINDOWWIDTH = 512;
const int WINDOWHEIGHT = 448;

using namespace std;

SceneWindow::SceneWindow(int argc, char **argv)
{
	// create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOWWIDTH, WINDOWHEIGHT);
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
    gluOrtho2D(0, WINDOWWIDTH, 0, WINDOWHEIGHT/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	// view port initializer
	viewportWidth_ = WINDOWWIDTH/2;
	viewportHeight_ = WINDOWHEIGHT/2;
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
	sw->loadLevel();
    glutTimerFunc(10, &SceneWindow::timerFunc, 0);
}

//----------------------------------------------------------------------

void SceneWindow::loadLevel()
{
	//called from start game
	//loads in current level from set checkpoint
	Level *level_ = Level::sharedLevel();
	level_->makeLevel();
	// initialize orthographic viewing projections
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOWWIDTH, 0, WINDOWHEIGHT/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



	mario = new Mario();
    
    mario->setLeft(16);
    mario->setRight(16+16);
    mario->setBottom(32);
    mario->setTop(32+16);
    
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
	// gets lists of the active objects to draw them
	Level *level_ = Level::sharedLevel();
	LList movable = level_->getActiveMovable();
	LList drawable = level_->getActiveDrawable();
	LList blocks = level_->getActiveBlocks();
	LListIterator li;
	
	Drawable *item;
    
	li.init(movable);
	while ((item = li.next())) {
		item->draw();
	}
    
	li.init(drawable);
	while ((item = li.next())) {
		item->draw();
	}
	 
	li.init(blocks);
	while ((item = li.next())) {
		item->draw();
	}
    // mario isn't in any of the lists, so must be drawn seperately
    mario->draw();
	 
	
    // force screen update
    glFlush();
	glutSwapBuffers();
}

//----------------------------------------------------------------------

void SceneWindow::keyboardCB(unsigned char key, int x, int y)
{
	//need to figure out multiple key presses
	
	// quit = q
    if (key == 'q') {
        exit(0);
	}
	// pause = p, hit again to unpause
	else if (key == 'p') {
		if (p==0){
			p=1;
			cout << "pause";
		}
		else if (p==1){
			p=0;
			timerFunc(0);
			cout << "unpause";
		}
		
	}

	else if (key == 'r') {
        // reset level
		viewportLeftX_ = 0;
		viewportRightX_ = viewportLeftX_ + viewportWidth_;
		sw->loadLevel();
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

	Level *level_ = Level:: sharedLevel();
	LList movable = level_->getActiveMovable();
	LListIterator li;
	li.init(movable);
	Drawable *item;
	Movable *movableItem;
	while ((item = li.next())) {
		movableItem = (Movable*)item;
		movableItem->updateScene();
	}

	mario ->updateScene();
	// check if screen needs to be moved
	int viewportMid_;
	viewportMid_ = (viewportLeftX_ + viewportRightX_)/2;
	if (mario->right() > viewportMid_)
	{
		viewportRightX_ = mario->right() + viewportWidth_/2;
		viewportLeftX_ = mario->right() - viewportWidth_/2;
		level_->updateExtents(viewportLeftX_, viewportRightX_);
		mario->setLeftBound(viewportLeftX_);
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(viewportLeftX_, viewportRightX_, 0, WINDOWHEIGHT/2);
    
    if (mario->isDead()) {
        // reset level
		viewportLeftX_ = 0;
		viewportRightX_ = viewportLeftX_ + viewportWidth_;
		sw->loadLevel();
    }

	glutPostRedisplay();
	if (p==0) {
		glutTimerFunc(10, &SceneWindow::timerFunc, 0);
	}
}

//----------------------------------------------------------------------

