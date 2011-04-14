// FireFlower.h
// Jamie Veals, John (Jack) Johnson, Jay Bondzeleske
//------------------------------------------------------------
// If FireFlower.h is not defined, defines it
#ifndef _FIREFLOWER_H
#define _FIREFLOWER_H
//------------------------------------------------------------
// Includes the Drawable.h file
#include "Drawable.h"
#include <string>
#include <sstream>
//------------------------------------------------------------
// Class FireFlower that inherits from Drawable
class FireFlower:public Drawable{
//------------------------------------------------------------
private:
    GLuint texture_;
public:
	// Constructor for FireFlower
	FireFlower()
    {
        // Mac environment variable for home directory
        char *cHomeDir = NULL;
        
        cHomeDir = getenv("HOME");
        
        // I think Windows uses HOMEPATH
        if (!cHomeDir) {
            cHomeDir = getenv("HOMEPATH");
        }
        std::string homeDir = cHomeDir;
        
        homeDir += "/CS330/sprites/flower0.tex";
        
        
        
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
	// Destructor for FireFlower
	virtual ~FireFlower()
	{
	}
	virtual void draw();
	// Returns object type
	int objectType() { return FIREFLOWER; }
};

#endif