/*
 *  test_Movable.cpp
 *  Game
 *
 *  Created by David M. Reed on 3/31/11. Modified by Alex Martishius and Matt Oldfield: 4/13/11
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Level.h"
#include "Base.h"
#include "LListIterator.h"
#include "Goomba.h"
#include "Turtle.h"
#include "Nonbreakable.h"
#include <iostream>
using namespace std;

    Level* level = Level::sharedLevel();
    //initialize iterators
    
    LList liBlocks, liMovable, liDrawable;
    liBlocks = level->getActiveBlocks();
    liMovable = level->getActiveMovable();
    liDrawable = level->getActiveDrawable();
    
    // create instances of objects
    Goomba *g1 = new Goomba();
    Goomba *g2 = new Goomba();
    Goomba *g3 = new Goomba();
    Turtle *t1 = new Turtle();
    Nonbreakable *n1 = new Nonbreakable(REGULAR);
    Nonbreakable *n2 = new Nonbreakable(REGULAR);
    Nonbreakable *n3 = new Nonbreakable(REGULAR);
    Nonbreakable *n4 = new Nonbreakable(REGULAR);
    Nonbreakable *n5 = new Nonbreakable(REGULAR);
    Nonbreakable *n6 = new Nonbreakable(REGULAR);
    Nonbreakable *n7 = new Nonbreakable(REGULAR);
    // set starting positions for test cases
    //place goomba 1
    g1.setLeft(16);
    g1.setRight(32);
    g1.setBottom(0);
    g1.setTop(16);
    //place block 1
    n1.setLeft(32);
    n1.setRight(48);
    n1.setBottom(0);
    n1.setTop(16);
    // place goomba 2
    g2.setLeft(32);
    g2.setRight(48);
    g2.setBottom(16);
    g2.setTop(32);
    // place block 2
    n2.setLeft(112);
    n2.setRight(128);
    n2.setBottom(16);
    n2.setTop(32);
    // place block 3
    n3.setLeft(64);
    n3.setRight(80);
    n3.setBottom(0);
    n3.setTop(16);
    // place block 4
    n4.setLeft(80);
    n4.setRight(96);
    n4.setBottom(0);
    n4.setTop(16);
    // place block 5
    n5.setLeft(48);
    n5.setRight(64);
    n5.setBottom(0);
    n5.setTop(16);
    // place block 6
    n6.setLeft(80);
    n6.setRight(96);
    n6.setBottom(16);
    n6.setTop(32);
    // place block 7
    n7.setLeft(96);
    n7.setRight(112);
    n7.setBottom(16);
    n7.setBottom(32);
    // place turtle
    t1.setLeft(80);
    t1.setRight(96);
    t1.setBottom(32);
    t1.setTop(48);
    // place final goomba
    g3.setLeft(48);
    g3.setRight(64);
    g3.setBottom(64);
    g3.setTop(80);
    // The idea is we have some imaginary level where
    // we are going to test all of the functionality of
    // the Movable class. We have one goomba in contact with a block
    // on the right, but not on the bottom. We have a second
    // goomba standing on a row of blocks, that should walk, reach
    // a block, turn around, walk, and fall off the other edge. We
    // have a goomba in the sky that should fall, land on the blocks,
    // and start walking. Finally, we have a turtle on an elevated
    // platform that should walk to each edge and turn around. 
    
    // append objects to the appropriate list
    liMovable.append(g1);
    liMovable.append(g2);
    liMovable.append(g3);
    liMovable.append(t1);
    liBlocks.append(n1);
    liBlocks.append(n2);
    liBlocks.append(n3);
    liBlocks.append(n4);
    liBlocks.append(n5);
    liBlocks.append(n6);
    liBlocks.append(n7);
    
    // Now we make a loop and output all of the checks for each of the 
    // four Movables in the room. 
    
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    
    while(a<120) {
        cout<< g1.checkRight();
        cout<< g1.checkLeft();
        cout<< g1.checkBottom();
        cout<< g1.checkTop();
        g1.updateScene();
        ++a;
    }
    
    while(b<120) {
        cout<< g2.checkRight();
        cout<< g2.checkLeft();
        cout<< g2.checkBottom();
        cout<< g2.checkTop();
        g2.updateScene();
        ++b;
    }
    
    while(c<120) {
        cout<< g3.checkRight();
        cout<< g3.checkLeft();
        cout<< g3.checkBottom();
        cout<< g3.checkTop();
        g3.updateScene();
        ++c;
    }
    
    while(d<120) {
        cout<< t1.checkRight();
        cout<< t1.checkLeft();
        cout<< t1.checkBottom();
        cout<< t1.checkTop();
        t1.updateScene();
        ++d;
    }





int main()
{

    Level* level = Level::sharedLevel();
    //initialize iterators
    
    LList liBlocks, liMovable, liDrawable;
    liBlocks = level->getActiveBlocks();
    liMovable = level->getActiveMovable();
    liDrawable = level->getActiveDrawable();
    
    // create instances of objects
    Goomba *g1 = new Goomba();
    Goomba *g2 = new Goomba();
    Goomba *g3 = new Goomba();
    Turtle *t1 = new Turtle();
    Nonbreakable *n1 = new Nonbreakable(REGULAR);
    Nonbreakable *n2 = new Nonbreakable(REGULAR);
    Nonbreakable *n3 = new Nonbreakable(REGULAR);
    Nonbreakable *n4 = new Nonbreakable(REGULAR);
    Nonbreakable *n5 = new Nonbreakable(REGULAR);
    Nonbreakable *n6 = new Nonbreakable(REGULAR);
    Nonbreakable *n7 = new Nonbreakable(REGULAR);
    // set starting positions for test cases
    //place goomba 1
    g1.setLeft(16);
    g1.setRight(32);
    g1.setBottom(0);
    g1.setTop(16);
    //place block 1
    n1.setLeft(32);
    n1.setRight(48);
    n1.setBottom(0);
    n1.setTop(16);
    // place goomba 2
    g2.setLeft(32);
    g2.setRight(48);
    g2.setBottom(16);
    g2.setTop(32);
    // place block 2
    n2.setLeft(112);
    n2.setRight(128);
    n2.setBottom(16);
    n2.setTop(32);
    // place block 3
    n3.setLeft(64);
    n3.setRight(80);
    n3.setBottom(0);
    n3.setTop(16);
    // place block 4
    n4.setLeft(80);
    n4.setRight(96);
    n4.setBottom(0);
    n4.setTop(16);
    // place block 5
    n5.setLeft(48);
    n5.setRight(64);
    n5.setBottom(0);
    n5.setTop(16);
    // place block 6
    n6.setLeft(80);
    n6.setRight(96);
    n6.setBottom(16);
    n6.setTop(32);
    // place block 7
    n7.setLeft(96);
    n7.setRight(112);
    n7.setBottom(16);
    n7.setBottom(32);
    // place turtle
    t1.setLeft(80);
    t1.setRight(96);
    t1.setBottom(32);
    t1.setTop(48);
    // place final goomba
    g3.setLeft(48);
    g3.setRight(64);
    g3.setBottom(64);
    g3.setTop(80);
    // The idea is we have some imaginary level where
    // we are going to test all of the functionality of
    // the Movable class. We have one goomba in contact with a block
    // on the right, but not on the bottom. We have a second
    // goomba standing on a row of blocks, that should walk, reach
    // a block, turn around, walk, and fall off the other edge. We
    // have a goomba in the sky that should fall, land on the blocks,
    // and start walking. Finally, we have a turtle on an elevated
    // platform that should walk to each edge and turn around. 
    
    // append objects to the appropriate list
    liMovable.append(g1);
    liMovable.append(g2);
    liMovable.append(g3);
    liMovable.append(t1);
    liBlocks.append(n1);
    liBlocks.append(n2);
    liBlocks.append(n3);
    liBlocks.append(n4);
    liBlocks.append(n5);
    liBlocks.append(n6);
    liBlocks.append(n7);
    
    // Now we make a loop and output all of the checks for each of the 
    // four Movables in the room. 
    
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    
    while(a<120) {
        cout<< g1.checkRight();
        cout<< g1.checkLeft();
        cout<< g1.checkBottom();
        cout<< g1.checkTop();
        g1.updateScene();
        ++a;
    }
    
    while(b<120) {
        cout<< g2.checkRight();
        cout<< g2.checkLeft();
        cout<< g2.checkBottom();
        cout<< g2.checkTop();
        g2.updateScene();
        ++b;
    }
    
    while(c<120) {
        cout<< g3.checkRight();
        cout<< g3.checkLeft();
        cout<< g3.checkBottom();
        cout<< g3.checkTop();
        g3.updateScene();
        ++c;
    }
    
    while(d<120) {
        cout<< t1.checkRight();
        cout<< t1.checkLeft();
        cout<< t1.checkBottom();
        cout<< t1.checkTop();
        t1.updateScene();
        ++d;
    }
	return 0;
}
