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

void Game::gameOver()
{
	pointsTotal_ = 0;
    coinsTotal_ = 0;
    livesTotal_ = 3;
	levelNumber_ = 1;
}










