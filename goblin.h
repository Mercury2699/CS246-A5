#ifndef GOBLIN_H
#define GOBLIN_H

#include "enemy.h"

class Item;

class Goblin : public Enemy {
    public:
    Goblin(Item *i): Enemy{70, 5, 10, i} {}
    char getChar() const override;
};

#endif


