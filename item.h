#ifndef ITEM_H
#define ITEM_H
#include "stuff.h"

class Player;

class Item : public Stuff {
    public:
    virtual void effect(Player &) = 0;
};
#endif
