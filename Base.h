/*
 *  Base.h
 *  Base
 *
 *  Created by Jamie Veals on 2/2/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 */

#ifndef _BASE_H
#define _BASE_H

#include <iostream>
using namespace std;

class Base {
private:
    int left, right, bottom, top;
    char color;
    
public:
    //method to draw 
    void draw();
    
};
#endif