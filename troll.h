#ifndef TROLL_H
#define TROLL_H
#include "enemy.h"


class Troll : public Enemy {
    Troll(Item *i): Enemy{120, 25, 15, i} {}
    public:
    char getChar() override;
};




#endif



