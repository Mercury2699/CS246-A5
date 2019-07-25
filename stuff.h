#ifndef STUFF_H
#define STUFF_H

#include "textDisplay.h"

// class Player;
// class Character;

enum Type {Plyr, Enmy, Trsr, Ptn, Itm, Str};

class Stuff {
    protected:
    Type type;

    public:
    virtual char getChar() const = 0;
    Type getType() {return type;}
};

class Stair final : public Stuff {
    // Type type; inherited from Stuff
    bool canDisplay = false;

    public:
    Stair() {this->type = Type::Str;}
    char getChar() const override {return '/';} // inherited from Stuff
};



#endif
