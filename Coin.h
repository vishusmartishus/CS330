// John (Jack) Johnson, Jamie Veals
//------------------------------------------------------------

#ifndef _COIN_H
#define _COIN_H

//------------------------------------------------------------

#include "Drawable.h"
#include <string>
#include <sstream>
//------------------------------------------------------------

class Coin:public Drawable{

//------------------------------------------------------------

private:
    GLuint texture_;
public:
	Coin()
    {
        
        // Mac environment variable for home directory
        char *cHomeDir = NULL;
        
        cHomeDir = getenv("HOME");
        
        // I think Windows uses HOMEPATH
        if (!cHomeDir) {
            cHomeDir = getenv("HOMEPATH");
        }
        std::string homeDir = cHomeDir;
        
        homeDir += "/CS330/sprites/coin0.tex";
        
        
        
        FILE *fp = fopen(homeDir.c_str(), "r");
        unsigned char *texture = new unsigned char[4 * 256 * 256];
        if (fread(texture, sizeof(unsigned char), 4 * 256 * 256, fp)
            != 4* 256 *256) {
            fprintf(stderr, "error reading %s", homeDir.c_str());
        }
        fclose(fp);
        
        glGenTextures(1, &texture_);
        glBindTexture(GL_TEXTURE_2D, texture_);
        
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

	virtual ~Coin()
	{

	}

	// OpenGL abstract method to draw object
	virtual void draw();
	// Returns object type COIN
	int objectType() { return COIN; }
};



#endif