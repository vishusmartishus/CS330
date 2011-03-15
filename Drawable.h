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
    // Default constructor
    Drawable () {}
	// Constructor for Drawable
    // s is the scene that holds this Drawable
	Drawable(Level *l)
    {
        points_ = 0;





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
    // Set points when called from child classes
	void setPoints(int points);
    // Accumulates the total points for the game
    void incrementPoints(int points);
    //------------------------------------------------------------
private:
    // Determines if it kills Mario from the side, top, and bottom
    bool killsBottom_, killsSide_, killsTop_;
    // Integer number for the points that all others inherit from to accumulate
    int points_, totalPoints_;
protected:
    // Pointer for the level
    Level *level_;

};

#endif