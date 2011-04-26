// Jamie Veals, John (Jack) Johnson, Jay Bondzeleske

//------------------------------------------------------------

#ifndef _DRAWABLE_H
#define _DRAWABLE_H

//------------------------------------------------------------

#include "Base.h"
// Includes the Glut/OpenGl Libraries
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <glut.h>
#include <GL/gl.h>
#endif

//------------------------------------------------------------

// Forward declaration of level
class Level;

//------------------------------------------------------------

class Drawable:public Base {

//------------------------------------------------------------

public:

    Drawable () 
    {
        //Point values for all items are defaulted to 100 unless overridden
        points_ = 100;
    }

	virtual ~Drawable ()
	{

	}

    // Getters for the killsside, killstop, killsbottom, and points
    bool killsFromBottom() const { return killsBottom_; }
	bool killsFromSide() const { return killsSide_; }
    bool killsFromTop() const { return killsTop_; }
    int getPoints() const { return points_; }
    // Setters for whether an object kills from the side(left or right), top, and bottom
    // By default all kills are set to false, have to be overridden by objects that kill Mario
    void setKillsBottom(bool kills = false);
	void setKillsSide(bool kills = false);
    void setKillsTop(bool kills = false);
    // Set points allows items to override their default value of 100
	void setPoints(int points);

    //------------------------------------------------------------

private:
    // Determines if an object kills Mario from the side, top, or bottom based on its boolean value
    bool killsBottom_, killsSide_, killsTop_;
    // Integer number for the points, used with each object that inherits from it
    int points_;
};

//------------------------------------------------------------

// Inline methods
//------------------------------------------------------------

// Sets killsBottom_ 
inline void Drawable::setKillsBottom(bool kills)
{
    killsBottom_ = kills;
}

//------------------------------------------------------------

// Sets killsSide_
inline void Drawable::setKillsSide(bool kills)
{
    killsSide_ = kills;
}

//------------------------------------------------------------

// Sets killsTop_
inline void Drawable::setKillsTop(bool kills)
{
    killsTop_ = kills;
}

//------------------------------------------------------------

// Sets points_ for individual object
inline void Drawable::setPoints(int points)
{
    points_ = points;
}

//------------------------------------------------------------

#endif