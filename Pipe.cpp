//------------------------------------------------------------
// include header file Coin.h
#include "Pipe.h"
// include header file Scene.h
#include "Level.h"
#include <string>
#include <sstream>
//------------------------------------------------------------
void Pipe::draw()
{
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable( GL_TEXTURE_2D );
    
    if (type_ == 0) {
        glBindTexture( GL_TEXTURE_2D, texture_[0]);
    }
    else{
        glBindTexture( GL_TEXTURE_2D, texture_[1]);
    }
    
    
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

void Pipe::setType(double type)
{
    type_ = type;
}

void Pipe::sprite()
{
    
    // Mac environment variable for home directory
    char *cHomeDir = NULL;
    
    cHomeDir = getenv("HOME");
    
    // I think Windows uses HOMEPATH
    if (!cHomeDir) {
        cHomeDir = getenv("HOMEPATH");
    }
    std::string homeDir = cHomeDir;
    std::string iName;
    homeDir += "/CS330/sprites/pipe";
    
    std::string pos;
    std::stringstream out;
    
    for (int i = 0; i<=1; ++i) {
        std::stringstream out;
        //Generates Filename
        iName = homeDir;
        out<<i;
        pos = out.str();
        iName += pos;
        iName += ".tex";
        
        FILE *fp = fopen(iName.c_str(), "r");
        unsigned char *texture = new unsigned char[4 * 512 * 256];
        if (fread(texture, sizeof(unsigned char), 4 * 512 * 256, fp)
            != 4* 512 *256) {
            fprintf(stderr, "error reading %s", iName.c_str());
        }
        fclose(fp);
        
        glGenTextures(1, &texture_[i]);
        glBindTexture(GL_TEXTURE_2D, texture_[i]);
        
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL );        
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        GL_LINEAR_MIPMAP_NEAREST );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                        GL_LINEAR );        
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                        GL_CLAMP );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                        GL_CLAMP );
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 512, 256, GL_RGBA,
                          GL_UNSIGNED_BYTE, texture);
        delete [] texture;
        
    }
}