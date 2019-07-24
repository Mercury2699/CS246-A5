#ifndef ITEM_H
#define ITEM_H

#include "stuff.h"
#include "player.h"

class Item : public Stuff {
    Item(){type = Type::Itm;}
};

class BarrierSuit : public Item {
    void effect(Player & pc) {
        pc.setSuit(true);
    }
    char getChar() { return 'B'; }
};

struct Compass : public Item {
    void effect(Player & pc) {
        pc.setCompass(true);
    }
    char getChar() { return 'C'; }
};


#endif
