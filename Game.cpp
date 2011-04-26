/*Game.cpp
Zach Adams
Feb. 02 2011*/

#include "Game.h"

Game::Game()
{
    pointsTotal_ = 0;
    coinsTotal_ = 0;
    livesTotal_ = 3;
	levelNumber_ = 1;
    levelTime_ = 300;
    microTime_ = 0;
}

//------------------------------------------------------------

int Game::getPoints()
{
    return pointsTotal_;
}

//------------------------------------------------------------

int Game::getCoins()
{
    return coinsTotal_;
}

//------------------------------------------------------------

int Game::getLives()
{
    return livesTotal_;
}

//------------------------------------------------------------
int Game::getLevel()
{
	return levelNumber_;
}

//------------------------------------------------------------

void Game::addCoin()
{
    coinsTotal_++;
    if (coinsTotal_ == 100) { //100 coins to life transition
        addLife();
        coinsTotal_ = 0;
    }
    pointsTotal_+=200;
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

//------------------------------------------------------------

int Game::getTime()
{
    return levelTime_;
}

//------------------------------------------------------------

void Game::pulseClock()
{
    if (microTime_ == 40) {
        levelTime_--;
        microTime_ = 0;
    }
    else{
        microTime_++;
    }
}

//------------------------------------------------------------

void Game::resetClock()
{
    levelTime_ = 300;
    microTime_=0;
}

//------------------------------------------------------------

void Game::gameOver()
{
	pointsTotal_ = 0;
    coinsTotal_ = 0;
    livesTotal_ = 3;
	levelNumber_ = 1;
}

//------------------------------------------------------------

void Game::jumpEnemy(int num)
{
    if (num < 5) {
        pointsTotal_+= 50* (2*num);
    }
    else{
        addLife();
    }
}

//------------------------------------------------------------

void Game::addPowerup()
{
    pointsTotal_+=1000;
}

//------------------------------------------------------------

void Game::breakBlock(bool isLarge)
{
    if (isLarge) {
        pointsTotal_ +=50;
    }
}

//------------------------------------------------------------

void Game::touchFlag(int height)
{
    pointsTotal_+=height*10;
    pointsTotal_+=getTime()*10;
    levelNumber_+=1;
}








