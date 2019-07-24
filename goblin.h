#ifndef GOBLIN_H
#define GOBLIN_H

#include "enemy.h"

class Goblin : public Enemy {
    Phoenix(Treasure *t): Enemy{70, 5, 10, t}{}
};

#endif


