#ifndef BARRIERSUIT_H
#define BARRIERSUIT_H
#include "item.h"
#include "player.h"

class BarrierSuit : public Item {
    void effect(Player & pc) override {
        pc.setSuit(true);
    }
};
#endif




