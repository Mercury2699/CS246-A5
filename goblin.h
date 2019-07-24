#ifndef GOBLIN_H
#define GOBLIN_H

#include "enemy.h"

class Goblin : public Enemy {
    Goblin(Treasure *t): Enemy{70, 5, 10, t} {}
    public:
    char getChar() override;
};

#endif


