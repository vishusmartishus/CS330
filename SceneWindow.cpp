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
    //// window size
    //width_ = 600;
    //height_ = 400;
    //
    //paddleHalfHeight_ = 40;
    //
    //// set inital position of ball and paddle
    //ballPosition_.set(width_ - 10, height_ / 2.0);
    //paddlePosition_.set(20, height_ / 2);
    //playing_ = false;
    //
    //// create window
    //glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    //glutInitWindowSize(width_, height_);
    //glutInitWindowPosition(30, 100);
    //glutCreateWindow("Pong");
    //
    //// initialize orthographic viewing projections
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluOrtho2D(0, width_, 0, height_);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //
    //// GLUT callbacks
    //glutDisplayFunc(&PongWindow::displayFunc);
    //glutKeyboardFunc(&PongWindow::keyboardFunc);
    //glutKeyboardUpFunc(&PongWindow::keyboardUpFunc);
    //glutIgnoreKeyRepeat(true);

    //// draw ball as point with size 5
    //glPointSize(5.0);
}

//----------------------------------------------------------------------

void SceneWindow::mainLoop()
{
    glutMainLoop();
}

//----------------------------------------------------------------------

void SceneWindow::startGame()
{
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
    //// clear window
    //glClear(GL_COLOR_BUFFER_BIT);
    //
    //// draw paddle
    //glBegin(GL_LINES);
    //glVertex2d(paddlePosition_[0], paddlePosition_[1] - paddleHalfHeight_);
    //glVertex2d(paddlePosition_[0], paddlePosition_[1] + paddleHalfHeight_);
    //glEnd();
    //
    //// draw game sides
    //glBegin(GL_LINE_STRIP);
    //glVertex2i(1, 1);
    //glVertex2i(width_ - 1, 1);
    //glVertex2i(width_ - 1, height_ - 1);
    //glVertex2i(1,height_ - 1);
    //glEnd();
    //
    //// draw ball
    //glBegin(GL_POINTS);
    //glVertex2dv(ballPosition_.array());
    //glEnd();
    //
    //// force screen update
    //glutSwapBuffers();
    //glFlush();
}

//----------------------------------------------------------------------

void SceneWindow::keyboardCB(unsigned char key, int x, int y)
{
    //if (key == 'q') {
    //    exit(0);
    //}
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

