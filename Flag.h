// File: Flag.h
// A header file for Flag.cpp
// by: John (Jack) Johnson CS330

#ifndef _FLAG_H
#define _FLAG_H

#include <iostream>
using namespace std;
#include "Drawable.h"

class Flag:public Drawable{
public:
    void create(); // create flag
    void endLevel(); // end current level
    int flagPoints[5]; // array of flag points awarded 











};
#endif