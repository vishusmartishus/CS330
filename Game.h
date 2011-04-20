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

        void pulseClock();
        void resetClock();
		void gameOver(); //alter values on game over condition
    private:
        int pointsTotal_, coinsTotal_, livesTotal_, levelNumber_, levelTime_, microTime_; //point total, coin total, life total
        




























        
};

#endif
