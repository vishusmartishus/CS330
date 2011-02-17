#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#endif

#include <iostream>

#include "SceneWindow.h"

extern SceneWindow *pw;


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
	
	glClearColor(0.7, 0.9, 1.0, 1.0);
	
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
    //glutTimerFunc(10, &PongWindow::timerFunc, 0);
}

//----------------------------------------------------------------------

void SceneWindow::loadLevel()
{
	//called from start game
	//loads in current level from set checkpoint
}

//----------------------------------------------------------------------

void SceneWindow::displayFunc()
{
    pw->displayCB();
}

//----------------------------------------------------------------------

void SceneWindow::keyboardFunc(unsigned char key, int x, int y)
{
    pw->keyboardCB(key, x, y);
}

//----------------------------------------------------------------------

void SceneWindow::keyboardUpFunc(unsigned char key, int x, int y)
{
    pw->keyboardUpCB(key, x, y);
}

//----------------------------------------------------------------------

void SceneWindow::timerFunc(int value)
{
    pw->timerCB(value);
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
	//
	
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
	if (key == 'p') {
        //pause
	}
	if (key == 'a') {
        //run
		//shoot fireball
	}
	if (key == 's') {
        //jump
	}
	if (key == 'k') {
        //left
	}
	if (key == 'l') {
        //right
	}
	
	//PONG
    //// indicate we should be moving paddle down
    //else if (key == 'd') {
    //    moveDown_ = true;
    //}
    //// indicate we should be moving paddle up
    //else if (key == 'f') {
    //    moveUp_ = true;
    //}
}

//----------------------------------------------------------------------

void SceneWindow::keyboardUpCB(unsigned char key, int x, int y)
{
	//PONG
    //// s to start game
    //if (key == 's') {
    //    if (!playing_) {
    //        startGame();
    //    }
    //}
    //// key release so stop moving paddle
    //moveUp_ = moveDown_ = false;
}

//----------------------------------------------------------------------

void SceneWindow::timerCB(int value)
{   
	//PONG
    //// move paddle if holding down key
    //if (moveUp_) {
    //    paddlePosition_[1] += 3;
    //    if (paddlePosition_[1] > height_ - 10) {
    //        moveUp_ = false;
    //    }
    //}
    //else if (moveDown_) {
    //    paddlePosition_[1] -= 3;
    //    if (paddlePosition_[1] < 10) {
    //        moveDown_ = false;
    //    }
    //}
    //
    //// update ball position
    //ballPosition_ += ballVelocity_;
    //
    //// bounce off top or bottom wall
    //if (ballPosition_[1] < 1 || ballPosition_[1] > height_ - 1) {
    //    ballVelocity_[1] = -ballVelocity_[1];
    //}
    //
    //// bounce off right wall
    //if (ballPosition_[0] > width_ - 1) {
    //    ballVelocity_[0] = -ballVelocity_[0];
    //}
    //
    //// check if bounce off paddle
    //if (ballPosition_[0] <= paddlePosition_[0] + 2) {
    //    double diff = fabs(ballPosition_[1] - paddlePosition_[1]);
    //    if (diff < paddleHalfHeight_) {
    //        // basic reflection
    //        //ballVelocity_[0] = -ballVelocity_[0];
    //        
    //        // realistic pong reflection
    //        // simulates the paddle as an arc
    //        Vec2 origin(paddlePosition_[0] - 5.0 * paddleHalfHeight_, paddlePosition_[1]);
    //        Vec2 normal = ballPosition_ - origin;
    //        normal.normalize();
    //        // reflection formual
    //        ballVelocity_ -= (2 * dot(ballVelocity_, normal) * normal);
    //        
    //        
    //        // normalize and make velocity magnitude 3
    //        ballVelocity_.normalize();
    //        ballVelocity_ = 3.0 * ballVelocity_;
    //    }
    //    else {
    //        playing_ = false;
    //        return;
    //    }
    //}

    //// force a redraw
    //glutPostRedisplay();
    //// continue game
    //glutTimerFunc(10, &PongWindow::timerFunc, 0);
}

//----------------------------------------------------------------------

