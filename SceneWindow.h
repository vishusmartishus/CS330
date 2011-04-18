#ifndef __SCENEWINDOW_H__
#define __SCENEWINDOW_H__


//----------------------------------------------------------------------

class SceneWindow {
    
public:
    SceneWindow(int argc, char **argv);
    
    // static callbacks
    static void displayFunc();
    static void keyboardFunc(unsigned char key, int x, int y);
    static void keyboardUpFunc(unsigned char key, int x, int y);
    static void timerFunc(int value);
    
    // non-static callbacks
    void displayCB();
    void keyboardCB(unsigned char key, int x, int y);
    void keyboardUpCB(unsigned char key, int x, int y);
    void timerCB(int value);
    
    void startGame();
	void loadLevel();
    void mainLoop();
    
private:
    //Drawable position_[];
    // whole level size
    int width_, height_;
	// viewport size
	int viewportWidth_, viewportHeight_;
	int viewportLeftX_, viewportRightX_;
	bool pause_;
	bool start_;
};

//----------------------------------------------------------------------

#endif

