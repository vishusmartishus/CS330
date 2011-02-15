/*
 *  Movable.h
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */

#ifndef __MOVABLE_H__
#define __MOVABLE_H__

//---------------------------------------------------------

#include "AllMovable.h"

//---------------------------------------------------------

class Movable: public AllMovable {

public:
    // constructor
    Movable();
    // destructor
    ~Movable();

    // instance vars
	// decides if the object is a reward object
	bool isReward_;
	// decides if the object can kill Mario.
	bool canKill_;
	// if the object can kill Mario, this variable decides if it can
	// kill him from the top. (i.e. piranha plant can kill him even
	// if he lands on it)
	bool canKillFromTop_;
	// decides whether the object turns around or disappears when
	// it hits a block
	bool turnsAround_;
	// decides if the object can fall off of "cliffs"
	bool canFallOff_;

    // methods
	// scans movable and drawable arrays and decides if they can move
	// uses "above" bools to decide how to react
	bool canMove();
	// getters for canKill and isReward
	bool isReward();
	bool canKill();
	// methods to reverse x or y velocity
	void xReverse();
	void yReverse();
	// returns whether movable object can kill from top
	bool getKillTop();
	// tells the object to move this step
	void move();


  
};

//---------------------------------------------------------

#endif //__MOVABLE_H
