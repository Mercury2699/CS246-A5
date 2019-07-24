#ifndef GOBLIN_H
#define GOBLIN_H

#include "enemy.h"

class Item;

class Goblin : public Enemy {
    Goblin(Item *i): Enemy{70, 5, 10, i} {}
    public:
    char getChar() override;
};

#endif


