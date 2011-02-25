
#include <iostream>
#include "SceneWindow.h"

SceneWindow *sw;

int main (int argc, char * const argv[]) {
    sw = new SceneWindow(argc, (char**) argv);
    sw->mainLoop();
    delete sw;
    return 0;
}
