#ifndef TROLL_H
#define TROLL_H
#include "enemy.h"


class Troll : public Enemy {
    Troll(Treasure *t): Enemy{120, 25, 15, t}{}
    public:
    char getChar() override;
};




#endif



