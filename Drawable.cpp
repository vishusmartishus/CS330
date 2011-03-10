// Alex Martishius, John (Jack) Johnson, Jay Bondzeleske
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
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
