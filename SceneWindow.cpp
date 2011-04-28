#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <glut.h>
#include <GL/gl.h>
#endif

#include <iostream>
#include <sstream>
#include <string>
#include <time.h>

#include "SceneWindow.h"
#include "Mario.h"
#include "Level.h"
#include "LList.h"
#include "LListIterator.h"
#include "Movable.h"
#include "Game.h"
#include "Coin.h"

extern SceneWindow *sw;
Mario *mario;
Game *game;
Coin *coin;
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
	
	glClearColor(0, 0, 0, 0);
	start_=false;
	game = new Game();
	
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
	mario = new Mario();
	pause_ = false;
	coin = new Coin();
    sw->loadLevel();
    glutTimerFunc(1, &SceneWindow::timerFunc, 0);
}

//----------------------------------------------------------------------

void SceneWindow::loadLevel()
{
    //loads in current level
	Level *level_ = Level::sharedLevel();
	level_->makeLevel(game->getLevel());
    
	// initialize orthographic viewing projections
    //Reset Viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOWWIDTH, 0, WINDOWHEIGHT/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Set Marios Starting Position
    mario->setLeft(16);
    mario->setRight(16+16);
    mario->setBottom(32);
	mario->setLeftBound(0);
    
    if (mario->isDead() || mario->getState() == SMALL_STATE) {
        
        mario->setTop(32+16);
    }
    else{
        mario->setTop(32+24);
    }
    mario->reset();
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
	
	if (start_==true){
		glClearColor(0.4196, 0.549, 1.0, 1.0);
		
		Drawable *item;
	
        //Loops through all active drawable objects
		li.init(drawable);
		while ((item = li.next())) {
			item->draw(true);
		}
        
        //Loops through all active moveable objects
		li.init(movable);
		while ((item = li.next())) {
			item->draw(game->spriteUpdate());
		}
    
        //Loops through all active block objects
		li.init(blocks);
		while ((item = li.next())) {
			item->draw(true);
		}
        
		// mario isn't in any of the lists, so must be drawn seperately
        
		mario->draw(game->spriteUpdate());
	}
    
    //Game is not started determine why and draw correct screen
	else {
        
        //Mario is out of lives
        //Draw Game over Screen
		if (game->getLives()<0) {
			string name = "GAME OVER";
			glColor3f(255,255,255);
			glRasterPos2f(viewportLeftX_ + 95, 110);
			for (int i=0; i<name.length(); ++i){
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);
			}
			glutSwapBuffers();
			glutPostRedisplay();
			
			
			//Return to the start screen in 3 sec
			time_t start_time, cur_time;
			time(&start_time);
			do
			{
				time(&cur_time);
			}
			while((cur_time - start_time) < 3);
			
			game = new Game;
			loadLevel();
			}
        
        //User has not yet started a level
        //Draw Load Screen
		else{
			string press = "Press 'S' to start";
			glColor3f(255,255,255);
			glRasterPos2f(viewportLeftX_ + 95, 110);
			for (int i=0; i<press.length(); ++i){
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, press[i]);
				}
			string name = "Mario x";
			glRasterPos2f(viewportLeftX_ +95, 100);
			for (int i=0; i<name.length(); ++i){
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);
			}
        
			//draw lives
			std::stringstream lives;
			lives << game->getLives();
			glColor3f(255,255,255);
			glRasterPos2f(viewportLeftX_ + 130, 100);
			for (int i=0; i<(lives.str()).length(); ++i){
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, lives.str()[i]);
				}
		}
	}
	
	
	//draw top line of game information
	string name = "MARIO                                   WORLD           TIME";
	glColor3f(255,255,255);
	glRasterPos2f(viewportLeftX_ + 20, 210);
	for (int i=0; i<name.length(); ++i){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);
	}
	//draw point total
	std::stringstream points;
	points << game->getPoints();
	glColor3f(255,255,255);
	glRasterPos2f(viewportLeftX_ + 20, 200);
	for (int i=0; i<(points.str()).length(); ++i){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, points.str()[i]);
	}
	//draw number of coins
	coin->setTop(208);
	coin->setBottom(198);
	coin->setLeft(viewportLeftX_+70);
	coin->setRight(viewportLeftX_ + 82);
	coin->draw(true);
	std::stringstream coins;
	coins << game->getCoins();
	glColor3f(255,255,255);
	glRasterPos2f(viewportLeftX_ + 82, 200);
	for (int i=0; i<(coins.str()).length(); ++i){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, coins.str()[i]);
	}
	//draw level number
	std::stringstream level;
	level << game->getLevel();
	glColor3f(255,255,255);
	glRasterPos2f(viewportLeftX_ + 145, 200);
	for (int i=0; i<(level.str()).length(); ++i){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, level.str()[i]);
	}
	//draw time
	std::stringstream lives;
	lives << game->getTime();
	glColor3f(255,255,255);
	glRasterPos2f(viewportLeftX_ + 201, 200);
	for (int i=0; i<(lives.str()).length(); ++i){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, lives.str()[i]);
	}
	
    //Game is Paused
    //Overlay Pause on active game
	if (pause_ && !mario->isDead()) {
		string pause = "PAUSE";
		glColor3f(255,255,255);
		glRasterPos2f(viewportLeftX_ + 110, 110);
		for (int i=0; i<pause.length(); ++i){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pause[i]);
		}
	}
	
    // force screen update
    glFlush();
	glutSwapBuffers();
}

//----------------------------------------------------------------------

void SceneWindow::keyboardCB(unsigned char key, int x, int y)
{
	if (key == 's'){
		start_ = true;
		
	}
	// quit = escape(ASCII code 27)
    if (key == 27) {
        exit(0);
	}
	if (start_) {
		// pause = p, hit again to unpause
		if (key == 'p') {
			if (pause_==false){
				pause_=true;
		}
			else if (pause_==true){
				pause_=false;
				timerFunc(0);
			}
		
		}

		else if (key == 'r') {
			// reset level
			viewportLeftX_ = 0;
			viewportRightX_ = viewportLeftX_ + viewportWidth_;
			sw->loadLevel();
		}

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

    
    //Mario is at the end of a level
    //Load next level and reset level independant variables
    if (mario->levelDone()) {
        pause_ = false;
        viewportLeftX_ = 0;
        viewportRightX_ = viewportLeftX_ + viewportWidth_;
        start_=false;
        sw->loadLevel();
        glClearColor(0, 0, 0, 0);
        game->resetClock();
    }
    
    //Game is active
    else if (!mario->isDead() && start_){
        
        //Pulse Clock and update active lists
        game->pulseClock();
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
    }
    
    //Mario is dead
    //Update his position for death animation
    else if (start_ ){
        
        //Set point of death for reference
        if (!pause_) {
            pause_ = true;
            deadups_ = true;
            deathPosY_ = mario->bottom();
            mario->setLeft(mario->left());
            mario->setRight(mario->left()+16.0);
            mario->setBottom(mario->bottom());
            mario->setTop(mario->bottom()+16.0);
            
        }
        
        //Mario is in the death animation and still on screen
        else if (mario->top() > 0){
            
            //Mario has reached the peak of the animation
            //Move his position down
            if (deadups_ == false) {
                mario->setBottom(mario->bottom()-2);
                mario->setTop(mario->top()-2);
            }
            
            //Mario starting the death animation
            //Move his position up
            else{
                mario->setBottom(mario->bottom()+1);
                mario->setTop(mario->top()+1);
                if (mario->bottom() > deathPosY_+48.0) {
                    deadups_ = false;
                }
            }
            
        }
        
        //Mario is dead and the death animation is over
        //Reset level
        else{
            pause_ = false;
            viewportLeftX_ = 0;
            viewportRightX_ = viewportLeftX_ + viewportWidth_;
            game->subLife();
            start_=false;
            sw->loadLevel();
            glClearColor(0, 0, 0, 0);
            game->resetClock();
        }
        
    }

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(viewportLeftX_, viewportRightX_, 0, WINDOWHEIGHT/2);
    

	glutPostRedisplay();
	if ((pause_==false) || (pause_ && mario->isDead())) {
		glutTimerFunc(10, &SceneWindow::timerFunc, 0);
	}
}

//----------------------------------------------------------------------

