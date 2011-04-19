/*
 *  Mushroom.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


//---------------------------------------------------------

#include "Mushroom.h"
#include <string>
#include <sstream>

//---------------------------------------------------------

Mushroom::Mushroom()
{
	setKillsBottom(false);
	setKillsSide(false);
	setKillsTop(false);
	setPoints(0);
	setXVelocity(0.75);
	setYVelocity(0.0);
    
    sprite();
}

//---------------------------------------------------------

Mushroom::~Mushroom()
{
}

//---------------------------------------------------------

void Mushroom::draw()
{
    
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, texture_);
    
    glColor4f(0.7f,0.9f,1.0f,1.0f);
    glBegin( GL_QUADS );
    glTexCoord2d(0.0,0.0); glVertex2d(left(),bottom());
    glTexCoord2d(1.0,0.0); glVertex2d(right(),bottom());
    glTexCoord2d(1.0,1.0); glVertex2d(right(),top());
    glTexCoord2d(0.0,1.0); glVertex2d(left(),top());
    glEnd();
    
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    

    
    
}

//---------------------------------------------------------

void Mushroom::sprite()
{
    // Mac environment variable for home directory
    char *cHomeDir = NULL;
    
    cHomeDir = getenv("HOME");
    
    // I think Windows uses HOMEPATH
    if (!cHomeDir) {
        cHomeDir = getenv("HOMEPATH");
    }
    std::string homeDir = cHomeDir;
    
    homeDir += "/CS330/sprites/mushroom0.tex";
    
    
    
    FILE *fp = fopen(homeDir.c_str(), "r");
    unsigned char *texture = new unsigned char[4 * 32 * 32];
    if (fread(texture, sizeof(unsigned char), 4 * 32 * 32, fp)
        != 4* 32 *32) {
        fprintf(stderr, "error reading %s", homeDir.c_str());
    }
    fclose(fp);
    
    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_);
    
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );        
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_LINEAR );        
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                    GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                    GL_CLAMP );
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 32, 32, GL_RGBA,
                      GL_UNSIGNED_BYTE, texture);
    delete [] texture;
}
