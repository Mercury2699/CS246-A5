#ifndef TROLL_H
#define TROLL_H
#include "enemy.h"


class Troll : public Enemy {
    public:
    Troll(Item *i): Enemy{120, 25, 15, i} {}
    char getChar() const override;
};




#endif



