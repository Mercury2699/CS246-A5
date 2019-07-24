#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"
class Merchant : public Enemy {
    // Merchant is inited with MerchantHoard by default;
    Merchant(): Enemy{30, 70, 5, new Treasure{4}}{}
    Merchant(Item * it): Enemy{30, 70, 5, it}{}
    public:
    char getChar() override;
};

#endif
