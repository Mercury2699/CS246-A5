#ifndef PHOENIX_H
#define PHOENIX_H

#include "enemy.h"
class Phoenix : public Enemy {
    public:
    Phoenix(Treasure *t): Enemy{50, 35, 20, t}{}
    char getChar() override;
};
#endif
