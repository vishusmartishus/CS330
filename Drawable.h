// Drawable.h
// Jamie Veals, John (Jack) Johnson, Jay Bondzeleske
//------------------------------------------------------------
// If Drawable.h is not defined, defines it
#ifndef _DRAWABLE_H
#define _DRAWABLE_H
//------------------------------------------------------------
// Includes the Base.h file
#include "Base.h"
//Includes the Glut/OpenGl Libraries
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <glut.h>
#include <GL/gl.h>
#endif
//------------------------------------------------------------
// Forward declaration of scene
class Level;
//------------------------------------------------------------
// Drawable class that inherits the Base class
class Drawable:public Base {
//------------------------------------------------------------
public:
    // Drawable constructor
    Drawable () 
    {
        //Point value for all items default are 100 unless overridden
        points_ = 100;
    }
	// Drawable destructor
	virtual ~Drawable ()
	{
	}
    // Getters for the killsside, killstop, killsbottom, and points
    bool killsFromBottom() const { return killsBottom_; }
	bool killsFromSide() const { return killsSide_; }
    bool killsFromTop() const { return killsTop_; }
    int getPoints() const { return points_; }
    // Setters for whether an option kills from the side, top, and bottom
    // By default all kills are set to false
    void setKillsBottom(bool kills = false);
	void setKillsSide(bool kills = false);
    void setKillsTop(bool kills = false);
    // Set points allows items to override their default value of 100
	void setPoints(int points);
    //------------------------------------------------------------
private:
    // Determines if it kills Mario from the side, top, and bottom
    bool killsBottom_, killsSide_, killsTop_;
    // Integer number for the points for each object that inherits from it
    int points_;
};
//------------------------------------------------------------
// Inline methods
//------------------------------------------------------------
// set killsBottom_
inline void Drawable::setKillsBottom(bool kills)
{
    killsBottom_ = kills;
}
//------------------------------------------------------------
//set killsSide_
inline void Drawable::setKillsSide(bool kills)
{
    killsSide_ = kills;
}
//------------------------------------------------------------
//set killsTop_
inline void Drawable::setKillsTop(bool kills)
{
    killsTop_ = kills;
}
//------------------------------------------------------------
//set points_
inline void Drawable::setPoints(int points)
{
    points_ = points;
}
//------------------------------------------------------------
#endif