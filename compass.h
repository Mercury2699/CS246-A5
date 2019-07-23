#ifndef COMPASS_H
#define COMPASS_H
#include "item.h"
#include "player.h"


class Compass : public Item {
    public:
    void effect(Player &) override;
};

#endif
