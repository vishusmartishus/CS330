/*Game.cpp
Zach Adams
Feb. 02 2011*/

#include "game.h"

Game::Game()
{
    pointsTotal_=0;
    coinsTotal_=0;
    livesTotal_=3;
}

//------------------------------------------------------------

int Game::pointsCall()
{
    return pointsTotal_;
}

//------------------------------------------------------------

int Game::coinsCall()
{
    return coinsTotal_;
}

//------------------------------------------------------------

int Game::livesCall()
{
    return livesTotal_;
}

//------------------------------------------------------------

void Game::addCoin()
{
    coinsTotal_++;
    if (coinsTotal_==100) { //100 coins to life transition
        addLife();
        coinsTotal_=0;
    }
}

//------------------------------------------------------------

void Game::addLife()
{
    livesTotal_++;
}

//------------------------------------------------------------

void Game::subLife()
{
    livesTotal_--;
}










