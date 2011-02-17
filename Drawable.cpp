// Alex Martishius, John (Jack) Johnson, Jay Bondzeleske
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
//------------------------------------------------------------
// gets x-coordinate
int Drawable::getX() 
{





	return 1;
}
//------------------------------------------------------------
// gets y-coordinate
int Drawable::getY() 
{





	return 1;
}
//------------------------------------------------------------
// sets x-coordinate
void Drawable::setX( int value ) 
{






}
//------------------------------------------------------------
// sets y-coordinate
void Drawable::setY( int value ) 
{






}
//------------------------------------------------------------
// set killsBottom_
void Drawable::setKillsBottom(bool kills)
{
    killsBottom_ = kills;
}
//------------------------------------------------------------
//set killsSide_
void Drawable::setKillsSide(bool kills)
{
    killsSide_ = kills;
}
//------------------------------------------------------------
//set killsTop_
void Drawable::setKillsTop(bool kills)
{
    killsTop_ = kills;
}
//------------------------------------------------------------
//set points_
void Drawable::setPoints(int points)
{
    points_ += points;
}
