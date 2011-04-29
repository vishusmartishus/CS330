/*
 *  test_Movable.cpp
 *  Game
 *
 *  Created by David M. Reed on 3/31/11. Modified by Alex Martishius and Matt Oldfield: 4/13/11
 *  Finished by Alex Martishius 4/28/11
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Level.h"
#include "AllMovable.h"
#include "Base.h"
#include "LListIterator.h"
#include "Goomba.h"
#include "Turtle.h"
#include "Nonbreakable.h"
#include "SceneWindow.h"
#include <iostream>
using namespace std;

SceneWindow *sw;

int main(int argc, char **argv) {
    
    sw = new SceneWindow(argc, (char**) argv);
    

    Level* level = Level::sharedLevel();
    
    LList blocks, moving, drawing;
    blocks = level->getActiveBlocks();
    moving = level->getActiveMovable();
    drawing = level->getActiveDrawable();
    
    

    // initialize iterators
    LListIterator liBlocks, liMovable, liDrawable;
    liBlocks.init(blocks);
    liMovable.init(moving);
    liDrawable.init(drawing);
    
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
    g1->setLeft(64);
    g1->setRight(80);
    g1->setBottom(16);
    g1->setTop(32);
    //place block 1
    n1->setLeft(32);
    n1->setRight(48);
    n1->setBottom(0);
    n1->setTop(16);
    // place goomba 2
    g2->setLeft(32);
    g2->setRight(48);
    g2->setBottom(16);
    g2->setTop(32);
    // place block 2
    n2->setLeft(112);
    n2->setRight(128);
    n2->setBottom(16);
    n2->setTop(32);
    // place block 3
    n3->setLeft(64);
    n3->setRight(80);
    n3->setBottom(0);
    n3->setTop(16);
    // place block 4
    n4->setLeft(80);
    n4->setRight(96);
    n4->setBottom(0);
    n4->setTop(16);
    // place block 5
    n5->setLeft(48);
    n5->setRight(64);
    n5->setBottom(0);
    n5->setTop(16);
    // place block 6
    n6->setLeft(80);
    n6->setRight(96);
    n6->setBottom(16);
    n6->setTop(32);
    // place block 7
    n7->setLeft(96);
    n7->setRight(112);
    n7->setBottom(16);
    n7->setBottom(32);
    // place turtle
    t1->setLeft(80);
    t1->setRight(96);
    t1->setBottom(32);
    t1->setTop(48);
    // place final goomba
    g3->setLeft(48);
    g3->setRight(64);
    g3->setBottom(64);
    g3->setTop(80);
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
    moving.append(g1);
    moving.append(g2);
    moving.append(g3);
    moving.append(t1);
    blocks.append(n1);
    blocks.append(n2);
    blocks.append(n3);
    blocks.append(n4);
    blocks.append(n5);
    blocks.append(n6);
    blocks.append(n7);
    
    // Now we make a loop and output all of the checks for each of the 
    // four Movables in the room. 
    
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    
    cout<< "goomba 1 checks:"<<endl;
    
    while(a<120) 
    {
        if (g1->checkRight())
        {
            cout<< g1->checkRight()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if (g1->checkLeft()) 
        {
            cout<< g1->checkLeft()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if (g1->checkBottom())
        {
            cout<< g1->checkBottom()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if(g1->checkTop()) 
        {
            cout<< g1->checkTop()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        g1->updateScene();
        ++a;
    }
    
    cout<< "goomba 2 checks:"<<endl;
    
    while(b<120)
    {
        if (g2->checkRight())
        {
            cout<< g2->checkRight()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if (g2->checkLeft())
        {
            cout<< g2->checkLeft()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if (g2->checkBottom())
        {
            cout<< g2->checkBottom()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if(g2->checkTop())
        {
            cout<< g2->checkTop()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        g2->updateScene();
        ++b;
    }
    
    cout<< "goomba 3 checks:"<<endl;
    
    while(c<120)
    {
        if (g3->checkRight())
        {
            cout<< g3->checkRight()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if (g3->checkLeft())
        {
            cout<< g3->checkLeft()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if (g3->checkBottom())
        {
            cout<< g3->checkBottom()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if(g3->checkTop()) 
        {
            cout<< g3->checkTop()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        g3->updateScene();
        ++c;
    }
    
    cout<< "turtle checks"<<endl;
    
    while(d<120) 
    {
        if (t1->checkRight())
        {
            cout<< t1->checkRight()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if (t1->checkLeft()) 
        {
            cout<< t1->checkLeft()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if (t1->checkBottom())
        {
            cout<< t1->checkBottom()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        if(t1->checkTop()) 
        {
            cout<< t1->checkTop()->objectType();
        }
        else
        {
            cout<<"NULL ";
        }
        t1->updateScene();
        ++d;
    }

	return 0;
}