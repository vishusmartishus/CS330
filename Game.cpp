/*Game.cpp
Initial version
Zach Adams
Feb. 02 2011*/

/*not included: 
tracking time (is this even our responsibility?)
adding to amount of coins
adding to amount of points
no default value for lives specified
no way to alter number of lives */

#include "game.h"

Game::Game()
{
    score_=0; //sets score and coins to default values. not sure if this is the best way to handle this?
    ccount_=0;
}

int Game::sCall()
{
    return score_;
}

int Game::cCall()
{
    return ccount_;
}

int Game::lCall()
{
    return lcount_;
}
















