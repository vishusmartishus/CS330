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

GLuint textureNum;

//---------------------------------------------------------

Goomba::Goomba()
{
	setKillsBottom(true);
	setKillsSide(true);
	setKillsTop(false);
	setPoints(0);
	setXVelocity(2.0);
	setYVelocity(0.0);
    
    
    FILE *fp = fopen("/Users/rwatters/Desktop/goomba.tiff", "r");
    unsigned char *texture = new unsigned char[4 * 16 * 16];
    if (fread(texture, sizeof(unsigned char), 4 * 16 * 16, fp)
        != 4* 16 *16) {
        fprintf(stderr, "error reading %s", "/Users/rwatters/Desktop/goomba.tiff");
    }
    fclose(fp);
    
    
    glGenTextures(1, &textureNum);
    glBindTexture(GL_TEXTURE_2D, textureNum);
    
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL );        
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_LINEAR );        
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                    GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                    GL_CLAMP );
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 16, 16, GL_RGBA,
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
    glBindTexture( GL_TEXTURE_2D, textureNum);
    
    glBegin( GL_QUADS );
    glTexCoord2d(0.0,0.0); glVertex2d(left(),top());
    glTexCoord2d(1.0,0.0); glVertex2d(right(),top());
    glTexCoord2d(1.0,1.0); glVertex2d(right(),bottom());
    glTexCoord2d(0.0,1.0); glVertex2d(left(),bottom());
    glEnd();
  
    glDisable(GL_TEXTURE_2D);
    
}

//---------------------------------------------------------
