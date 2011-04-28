/*
 *  Shell.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


//---------------------------------------------------------

#include "Shell.h"
#include "Level.h"
#include <string>
#include <sstream>

using namespace std;



//---------------------------------------------------------

Shell::Shell()
{
	setKillsBottom(true);
	setKillsSide(true);
	setKillsTop(false);
	setPoints(0);
	setXVelocity(1.0);
	setYVelocity(0.0);
    
    sprite();

        
    
}

//---------------------------------------------------------

Shell::~Shell()
{
}

//---------------------------------------------------------

bool Shell::canMove()
{
    // call checkRight and checkLeft methods
    Drawable *dRight = this->checkRight();
    Drawable *dLeft = this->checkLeft();
    Drawable *dBottom = this->checkBottom();
	Drawable *dTop = this->checkTop();
    
	bool keepGoing = true;
    
    if (dRight != NULL && dLeft != NULL && dTop != NULL && dBottom != NULL)
	{
		if (dRight->objectType() == GOOMBA || dRight->objectType() == TURTLE || dRight->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dRight);
		}
    }
    if (dLeft != NULL) {
        if (dLeft->objectType() == GOOMBA || dLeft->objectType() == TURTLE || dLeft->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dLeft);
		}
    }
    if (dBottom != NULL) {
        if (dBottom->objectType() == GOOMBA || dBottom->objectType() == TURTLE || dBottom->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dBottom);
		}
    }
	if (dTop != NULL) {
        if (dTop->objectType() == GOOMBA || dTop->objectType() == TURTLE || dTop->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dTop);
		}
    }	
    
    // if nothing underneath
    if ((dBottom == NULL || dBottom == this) || dBottom->objectType() == BACKGROUND || dBottom->objectType() == COIN)
    {
        this->setXVelocity(-2.0);
    }
    
    // if a block type is underneath
    else 
    {
        if (dBottom->objectType() == REGULAR || dBottom->objectType() == BREAKABLE || dBottom->objectType() == QUESTION || dBottom->objectType() == PIPE || dBottom->objectType() == OFFQUESTION || dBottom->objectType() == FLAG) 
        {
            this->setYVelocity(0.0);
        }
        else if (dBottom->objectType() == BACKGROUND)
        {
            this->setYVelocity(-2.0);
        }
    }
    
    // if nothing to the right or left
    if (dRight != NULL && dRight->objectType() != BACKGROUND) 
    {
        if (dRight->objectType() == REGULAR || dRight->objectType() == BREAKABLE || dRight->objectType() == QUESTION || dRight->objectType() == PIPE || dRight->objectType() == FLAG) 
        {
            keepGoing = false;
        }
    }
    
    if (dLeft != NULL && dLeft->objectType() != BACKGROUND) 
    {
        if (dLeft->objectType() == REGULAR || dLeft->objectType() == BREAKABLE || dLeft->objectType() == QUESTION || dLeft->objectType() == PIPE || dLeft->objectType() == FLAG) 
        {
            keepGoing = false;
        }
    }
    
	return keepGoing;
}

//---------------------------------------------------------

void Shell::draw(bool update)
{
    //Set proper blending for alpha
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, textureShell);
    
    //Draw QUAD
    glColor4f(0.7f,0.9f,1.0f,1.0f);
    glBegin( GL_QUADS );
    glTexCoord2d(0.0,0.0); glVertex2d(left(),bottom());
    glTexCoord2d(1.0,0.0); glVertex2d(right(),bottom());
    glTexCoord2d(1.0,1.0); glVertex2d(right(),top());
    glTexCoord2d(0.0,1.0); glVertex2d(left(),top());
    glEnd();
    
    //Disable unwanted gl modes
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);    
    
    
 
}

//---------------------------------------------------------

void Shell::sprite()
{
    // Mac environment variable for home directory
    char *cHomeDir = NULL;
    
    cHomeDir = getenv("HOME");
    
    // I think Windows uses HOMEPATH
    if (!cHomeDir) {
        cHomeDir = getenv("HOMEPATH");
    }
    string homeDir = cHomeDir;
    
    homeDir += "/CS330/sprites/shell0.tex";
    
    
    //Read in the texture file
    FILE *fp = fopen(homeDir.c_str(), "r");
    unsigned char *texture = new unsigned char[4 * 32 * 32];
    if (fread(texture, sizeof(unsigned char), 4 * 32 * 32, fp)
        != 4* 32 *32) {
        fprintf(stderr, "error reading %s", homeDir.c_str());
    }
    fclose(fp);
    
    //Bind Texture to a GLuint
    glGenTextures(1, &textureShell);
    glBindTexture(GL_TEXTURE_2D, textureShell);
    
    //Set parameters for how the texture is displayed
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );        
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_LINEAR );        
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                    GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                    GL_CLAMP );
    
    //Build Mipmap
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 32, 32, GL_RGBA,
                      GL_UNSIGNED_BYTE, texture);
    delete [] texture;
}
