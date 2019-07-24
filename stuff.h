#ifndef STUFF_H
#define STUFF_H

#include "textDisplay.h"

struct Stuff {
    virtual char getChar() = 0;
    virtual void effect(Human &h) = 0;
    virtual void effect(Dwarf &d) = 0;
    virtual void effect(Orc &o) = 0;
    virtual void effect(Elves &e) = 0;
    virtual void attack(Stuff *) = 0;
    virtual void beAttacked(Stuff *) = 0;
    virtual bool isDead() = 0;
    virtual void remove() = 0;

    virtual int getHP() = 0;
	virtual int getAtk() = 0;
	virtual int getDef() = 0;
};

#endif
