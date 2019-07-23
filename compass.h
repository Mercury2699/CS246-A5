#ifndef COMPASS_H
#define COMPASS_H
#include "item.h"
#include "player.h"


struct Compass : public Item {
    void effect(Player & pc) override {
        pc.setCompass(true);
    }
};

#endif


