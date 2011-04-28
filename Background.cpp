// Russell Watterson
//------------------------------------------------------------

#include "Background.h"
#include "Level.h"
#include <string>


//------------------------------------------------------------

void Background::draw()
{
	//Set proper blending for alpha
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, texture_);
    
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

void Background::sprite()
{
    //Array of background element types
    std::string types[11] = {"bush0", "bush1", "bush2", "cloud0", "cloud1", "cloud2", "mountain0", "mountain1", "trunk0", "trunk1", "trunk2"};
    
    // Mac environment variable for home directory
    char *cHomeDir = NULL;
    
    cHomeDir = getenv("HOME");
    
    // I think Windows uses HOMEPATH
    if (!cHomeDir) {
        cHomeDir = getenv("HOMEPATH");
    }
    
    std::string homeDir = cHomeDir;
    
    homeDir += "/CS330/sprites/";
    homeDir +=types[kind_];
    homeDir +=".tex";
    
    
    
    //Read in the texture file
    FILE *fp = fopen(homeDir.c_str(), "r");
    unsigned char *texture = new unsigned char[4 * width_ * height_ * 4];
    if (fread(texture, sizeof(unsigned char), 4 * width_ * height_ * 4, fp)
        != 4* width_ *height_ * 4) {
        fprintf(stderr, "error reading %s", homeDir.c_str());
    }
    
    fclose(fp);
    
    //Bind Texture to a GLuint
    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_);
    
    //Set paramaters for how the texture is displayed
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
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, (2*width_), (2*height_) , GL_RGBA,
                      GL_UNSIGNED_BYTE, texture);
    delete [] texture;
    
}

