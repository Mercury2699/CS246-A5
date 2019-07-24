#ifndef STUFF_H
#define STUFF_H

#include "textDisplay.h"
#include "player.h"

enum Type {Plyr, Enmy, Trsr, Ptn, Itm};

class Stuff {
    protected:
    Type type;

    public:
    virtual char getChar() = 0;
    virtual void attack(Stuff *) = 0;
    virtual void beAttacked(Stuff *) = 0;
    virtual void effect(Player *) = 0;
    virtual bool isDead() = 0;
    Type getType() {return type;}
};

#endif
