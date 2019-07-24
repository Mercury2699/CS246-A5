#ifndef ITEM_H
#define ITEM_H

#include "stuff.h"
#include "player.h"

class Stuff;

class Item : public Stuff {
    public:
    Item(){ this->type = Type::Itm;}
    virtual char getChar() = 0;
    virtual void effect(Player *) = 0;
};

class BarrierSuit : public Item {
    void effect(Player * pc) override {
        pc->setSuit(true);
    }

    char getChar() override { return 'B'; }
};

struct Compass : public Item {
    void effect(Player * pc) override {
        pc->setCompass(true);
    }

    char getChar() override { return 'C'; }
};


#endif
