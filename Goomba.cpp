/*
 *  Goomba.cpp
 *  Game
 *
 *  Created by David Reed, Matt Oldfield, Jeremy Sampson, Andrew Daugherty
 *  and Alex Martishius
 *  Copyright 2011. All rights reserved.
 *
 */


//---------------------------------------------------------

#include "Goomba.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


GLuint textureGoomba;

//---------------------------------------------------------

Goomba::Goomba()
{
	setKillsBottom(true);
	setKillsSide(true);
	setKillsTop(false);
	setPoints(0);
	setXVelocity(2.0);
	setYVelocity(0.0);
    
    // Mac environment variable for home directory
    char *cHomeDir = NULL;
    
    cHomeDir = getenv("HOME");
    
    // I think Windows uses HOMEPATH
    if (!cHomeDir) {
        cHomeDir = getenv("HOMEPATH");
    }
    string homeDir = cHomeDir;
    homeDir += "/CS330/sprites/goomba.tiff";
    
    cout<<"\n cd:" << homeDir <<endl;
    
    
    
    FILE *fp = fopen(homeDir.c_str(), "r");
    unsigned char *texture = new unsigned char[4 * 256 * 256];
    if (fread(texture, sizeof(unsigned char), 4 * 256 * 256, fp)
        != 4* 256 *256) {
        fprintf(stderr, "error reading %s", "sprites/goomba.tiff");
    }
    fclose(fp);
    
    
    glGenTextures(1, &textureGoomba);
    glBindTexture(GL_TEXTURE_2D, textureGoomba);
    
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL );        
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_LINEAR );        
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                    GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                    GL_CLAMP );
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 256, 256, GL_RGBA,
                      GL_UNSIGNED_BYTE, texture);
    delete [] texture;
   

}

//---------------------------------------------------------

Goomba::~Goomba()
{
    
}

//---------------------------------------------------------

void Goomba::draw()
{
	    
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, textureGoomba);
    
    glBegin( GL_QUADS );
    glTexCoord2d(0.0,0.0); glVertex2d(left(),top());
    glTexCoord2d(1.0,0.0); glVertex2d(right(),top());
    glTexCoord2d(1.0,1.0); glVertex2d(right(),bottom());
    glTexCoord2d(0.0,1.0); glVertex2d(left(),bottom());
    glEnd();
  
    glDisable(GL_TEXTURE_2D);
    
}

//---------------------------------------------------------
