/*Game.h
Zach Adams
Feb. 02 2011*/


#ifndef _GAME_H
#define _GAME_H

class Game {
    public:
        Game();
        int getPoints(); //send score
        int getCoins(); //send coins
        int getLives(); //send lives
		int getLevel(); //send level number
        int getTime(); //send remaining time
        void addCoin(); //add a single coin to current total. also handles 100 coins=life transition
        void addLife(); //add life
        void subLife(); //subtract life
        void jumpEnemy(int num); //add points for enemies killed by jumping
        void addPowerup(); //add points for getting a powerup
        void breakBlock(bool isLarge); //add points for breaking a block
        void touchFlag(int height); //adds points for flagpole and increment level

        void pulseClock(); //Increment the game clock
        void resetClock(); //Reset the game clock
		void gameOver(); //alter values on game over condition
    private:
        int pointsTotal_, coinsTotal_, livesTotal_, levelNumber_, levelTime_, microTime_; //point total, coin total, life total
        




























        
};

#endif
