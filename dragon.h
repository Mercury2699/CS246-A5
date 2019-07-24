#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Item;

class Dragon : public Enemy {
    // Dragon must be initialized with an Item (Dragon Hoard or Barrier Suit)
    Dragon(Item * it): Enemy{150, 20, 20, it} {} 
    public:
    char getChar() const override;
};

#endif

