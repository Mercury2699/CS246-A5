#ifndef PHOENIX_H
#define PHOENIX_H

#include "enemy.h"
class Phoenix : public Enemy {
    public:
    Phoenix(Item *i): Enemy{50, 35, 20, i}{}
    char getChar() const override;
};
#endif
