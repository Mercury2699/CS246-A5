#ifndef STUFF_H
#define STUFF_H

#include "textDisplay.h"

enum Type {Plyr, Enmy, Trsr, Ptn, Itm};
class Human;
class Dwarf;
class Orc;
class Elves;

class Stuff {
    protected:
    Type type;

    public:
    virtual char getChar() = 0;
    virtual void effect(Human &h) = 0;
    virtual void effect(Dwarf &d) = 0;
    virtual void effect(Orc &o) = 0;
    virtual void effect(Elves &e) = 0;
    virtual void attack(Stuff *) = 0;
    virtual void beAttacked(Stuff *) = 0;
    virtual bool isDead() = 0;
    virtual void remove() = 0;
    Type getType() {return type;}
    virtual int getHP() = 0;
	virtual int getAtk() = 0;
	virtual int getDef() = 0;
    virtual void setHP(int hp) = 0;
	virtual void setAtk(int atk) = 0;
	virtual void setDef(int def) = 0;
};

#endif
