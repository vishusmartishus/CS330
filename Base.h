// Jamie Veals, Jay Bondzeleske, John (Jack) Johnson
//------------------------------------------------------------

#ifndef _BASE_H
#define _BASE_H

//------------------------------------------------------------

// Constant object types that other groups will use to create items and enemies
const int FLAG = 1;
const int BREAKABLE = 2;
const int QUESTION = 3;
const int FIREFLOWER = 4;
const int COIN = 5;
const int MARIO = 6;
const int GOOMBA = 7;
const int MUSHROOM = 8;
const int PLANT = 9;
const int SHELL = 10;
const int STAR = 11;
const int TURTLE = 12;
const int ENEMYFIREBALL = 13;
const int MARIOFIREBALL = 14;
const int REGULAR = 15;
const int PIPE = 16;
const int OFFQUESTION = 17;
const int BACKGROUND = 18;


class Base {

//------------------------------------------------------------ 

public:

    Base()
    {

    }

	virtual ~Base()
	{

	}

	// Abstract method to define an object by returning an integer
	virtual int objectType();
    // OpenGL abstract method to draw object
    virtual void draw(bool update)=0;
    // By default an item isn't movable
    virtual bool isMovable() const { return false; }
    // Getters for the left coordinate, right coordinate, top coordinate, and bottom coordinate
    double left() const { return left_; }
    double right() const { return right_; }
    double top() const { return top_; }
    double bottom() const { return bottom_; }
    // Setters for the left coordinate, right coordinate, top coordinate, and bottom coordinate
    void setLeft(double left);
    void setRight(double right);
    void setTop(double top);
    void setBottom(double bottom);

//------------------------------------------------------------

private:
    // Private variables for the left coordinate, right coordinate, top coordinate, and bottom coordinate
    double left_, right_, bottom_, top_;
};

//------------------------------------------------------------

// Inline methods
//------------------------------------------------------------

// Sets the object type to 0
inline int Base::objectType()
{
    return 0;
}

//------------------------------------------------------------

// Sets left coordinate
inline void Base::setLeft(double left)
{
    left_ = left;
}
 
 //------------------------------------------------------------

 // Sets right coordinate
 inline void Base::setRight(double right)
 {
 right_ = right;
 }

 //------------------------------------------------------------

 // Sets top coordinate
 inline void Base::setTop(double top)
 {
 top_ = top;
 }

 //------------------------------------------------------------

 // Sets bottom coordinate
 inline void Base::setBottom(double bottom)
 {
 bottom_ = bottom;
 }

//------------------------------------------------------------

#endif