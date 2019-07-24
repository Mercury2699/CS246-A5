#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "enemy.h"
class Werewolf : public Enemy {
    public:
    Werewolf(Treasure *t): Enemy{120, 30, 5, t} {}
    char getChar() override;
};
#endif
