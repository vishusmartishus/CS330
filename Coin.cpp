// Coin.cpp
// John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------
// include header file Coin.h
#include "Coin.h"
// include header file Scene.h
#include "Level.h"
//------------------------------------------------------------
void Coin::draw()
{
	
	
	
	
	
}
//------------------------------------------------------------
// Makes the coin appear
void Coin::create(int xCoor, int yCoor) 
{
    setX(xCoor);
    setY(yCoor);
    draw();


}
//------------------------------------------------------------
// Makes the coin disappear
void Coin::disappear(int xCoor, int yCoor) 
{
    level_->removeDrawable(this);





}

