#ifndef STUFF_H
#define STUFF_H

#include "textDisplay.h"

class Player;
class Character;

enum Type {Plyr, Enmy, Trsr, Ptn, Itm};

class Stuff {
    protected:
    Type type;

    public:
    virtual char getChar() = 0;
    virtual void attack(Character *) = 0;
    virtual void beAttacked(Character *) = 0;
    virtual void effect(Player *) = 0;
    virtual bool isDead() = 0;
    Type getType() {return type;}
};

#endif
