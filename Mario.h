/*
 *  Mario.h
 *  Mario
 *
 *  Created by Andrew Peddicord on 2/1/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 */

#ifndef _MARIO_H
#define _MARIO_H

class Mario {

 public:
  Mario(); //Constructor
  
  void Update(int Button[]); //Gets called when key is pressed

 private:
  int State, maxHeight; //State can be 0,1,2 depending if he is Big/Little/Fire Mario
  bool isInvincible, isJumping, isPounding, isRunning;

  void Jump();
  void Move(bool isRunning); //Moves Mario to the left or right and calls check() at beginning

  bool Check(bool isRunning); //Checks to see if Mario ran into something
  bool CheckLeftRight();
  bool CheckTop();
  bool CheckBottom();
  bool Fireball(); //Returns true if Mario is in the fire state
  bool Buttpound();
};

#endif
