#ifndef ITEM_H
#define ITEM_H

#include "stuff.h"
#include "player.h"

class Item : public Stuff {};

class BarrierSuit : public Item {
    void effect(Player & pc) {
        pc.setSuit(true);
    }
};

struct Compass : public Item {
    void effect(Player & pc) {
        pc.setCompass(true);
    }
};


#endif
