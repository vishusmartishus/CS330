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
        void addCoin(); //add a single coin to current total. also handles 100 coins=life transition
        void addLife(); 
        void subLife(); //subtract life
    private:
        int pointsTotal_, coinsTotal_, livesTotal_; //point total, coin total, life total
        




























        
};

#endif
