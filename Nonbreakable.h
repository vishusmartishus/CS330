//Jay Bondzeleske, John (Jack) Johnson
//CS330

//If Nonbreakable.h is not defined, defines it
#ifndef _NONBREAKABLE_H
#define _NONBREAKABLE_H

//Includes iostream
#include <iostream>
#include "Drawable.h"

//Nonbreakable class
class Nonbreakable:public Drawable {

public:
    //Create Method
    void create();




    
    
    //generateReward Method
    void generateReward();
    
    
    
    
    
    
    //redraw Method
    void redraw();





    //Three types of blocks (Question, Regular, and Blocks little Mario cannot break)
    int type[3];


    //Three different contents (Mushroom, Fire Floiwer, and Coin)
    int content[3];

};
//Ends if
#endif

