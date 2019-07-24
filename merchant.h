#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"
class Merchant : public Enemy {
    Merchant(): Enemy{30, 70, 5, new Treasure{4}}{}
};

#endif
