#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "enemy.h"
class Werewolf : public Enemy {
    public:
    Werewolf(Item *i): Enemy{120, 30, 5, i} {}
    char getChar() const override;
};
#endif
