/*
 *  MarioFireball.cpp
 *  Movable
 *
 *  Created by Jeremy Sampson, Matt Oldfield, and Alex Martishius
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

//---------------------------------------------------------

#include "MarioFireball.h"
#include "Level.h"
#include <string>
#include <sstream>

//---------------------------------------------------------

MarioFireball::MarioFireball()
{
	setKillsBottom(false);
	setKillsSide(false);
	setKillsTop(false);
	setPoints(0);
	setXVelocity(0.0);
	setYVelocity(0.0);
    
    sprite();
}

//---------------------------------------------------------

MarioFireball::~MarioFireball()
{
}

//---------------------------------------------------------

bool MarioFireball::canMove()
{
    // call checkRight and checkLeft methods
    Drawable *dRight = this->checkRight();
    Drawable *dLeft = this->checkLeft();
	Drawable *dTop = this->checkTop();
    Drawable *dBottom = this->checkBottom();
    
	bool keepGoing = true;
    
	if (dRight != NULL)
	{
        if (dRight->objectType() == BREAKABLE || dRight->objectType() == QUESTION || dRight->objectType() == PIPE || dRight->objectType() == OFFQUESTION || dRight->objectType() == REGULAR || dRight->objectType() == FLAG)
        {
            Level::sharedLevel()->removeDrawable(this);
        }
        else if (dRight->objectType() == GOOMBA || dRight->objectType() == TURTLE || dRight->objectType() == PLANT)
        {
            Level::sharedLevel()->removeDrawable(dRight);
            Level::sharedLevel()->removeDrawable(this);
        }
    }
    
    if (dLeft != NULL)
	{
        if (dLeft->objectType() == BREAKABLE || dLeft->objectType() == QUESTION || dLeft->objectType() == PIPE || dLeft->objectType() == OFFQUESTION || dLeft->objectType() == REGULAR || dLeft->objectType() == FLAG)
        {
            Level::sharedLevel()->removeDrawable(this);
        }
        else if (dLeft->objectType() == GOOMBA || dLeft->objectType() == TURTLE || dLeft->objectType() == PLANT)
        {
            Level::sharedLevel()->removeDrawable(dLeft);
            Level::sharedLevel()->removeDrawable(this);
        }
    }
    
    if (dTop != NULL) {
        if (dTop->objectType() == GOOMBA || dTop->objectType() == TURTLE || dTop->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dTop);
			Level::sharedLevel()->removeDrawable(this);
		}
    }
    
    if (dBottom != NULL) {
        if (dBottom->objectType() == GOOMBA || dBottom->objectType() == TURTLE || dBottom->objectType() == PLANT)
		{
			Level::sharedLevel()->removeDrawable(dBottom);
			Level::sharedLevel()->removeDrawable(this);
		}
        else if (dBottom->objectType() == BREAKABLE || dBottom->objectType() == QUESTION || dBottom->objectType() == PIPE || dBottom->objectType() == OFFQUESTION || dBottom->objectType() == REGULAR || dBottom->objectType() == FLAG)
        {
            this->setYVelocity(0.0);
        }
        else if (dBottom->objectType() == MARIOFIREBALL){
            this->setYVelocity(-1.0);
        }

    }
    else {
        this->setYVelocity(-1.0);
    }

    return keepGoing;
}

//---------------------------------------------------------

void MarioFireball::draw(bool update)
{
    if (update) {
        if (texturePos < 3) {
            texturePos++;
        }
        else{
            texturePos = 0;
        }
    }
    
	
    //Set proper blending for alpha
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, texture_[texturePos]);
    
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

void MarioFireball::sprite()
{
    texturePos = 0;
    
    // Mac environment variable for home directory
    char *cHomeDir = NULL;
    
    cHomeDir = getenv("HOME");
    
    // I think Windows uses HOMEPATH
    if (!cHomeDir) {
        cHomeDir = getenv("HOMEPATH");
    }
    std::string homeDir = cHomeDir;
    std::string iName;
    homeDir += "/CS330/sprites/fireball";
    
    std::string pos;
    
    
    for (int i = 0; i<4; ++i) {
        std::stringstream out;
        //Generates Filename
        iName = homeDir;
        out<<i;
        pos = out.str();
        iName += pos;
        iName += ".tex";
        
        //Read in the texture file
        FILE *fp = fopen(iName.c_str(), "r");
        unsigned char *texture = new unsigned char[4 * 16 * 16];
        if (fread(texture, sizeof(unsigned char), 4 * 16 * 16, fp)
            != 4* 16 *16) {
            fprintf(stderr, "error reading %s", iName.c_str());
        }
        fclose(fp);
        
        //Bind Texture to a GLuint
        glGenTextures(1, &texture_[i]);
        glBindTexture(GL_TEXTURE_2D, texture_[i]);
        
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
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 16, 16, GL_RGBA,
                          GL_UNSIGNED_BYTE, texture);
        delete [] texture;
        
    }
    
}

