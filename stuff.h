#ifndef STUFF_H
#define STUFF_H

#include "textDisplay.h"

// class Player;
// class Character;

enum Type {Plyr, Enmy, Trsr, Ptn, Itm};

class Stuff {
    protected:
    Type type;

    public:
    virtual char getChar() const = 0;
    Type getType() {return type;}
};

#endif
