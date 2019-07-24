#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"
#include "treasure.h"

class Merchant : public Enemy {
    // protected:
	// int HP; inherited from Character
	// int Atk; inherited from Character
	// int Def; inherited from Character
	// Type type; inherited from Stuff
	// std::shared_ptr<Item> i; inherited from Enemy
        // Item includes Suit, Compass, and Treasuress
	// bool hostile = false; inherited from Enemy

    public:
    // Merchant is inited with MerchantHoard by default;
    Merchant(): Enemy{30, 70, 5, new Treasure{4}}{}
    Merchant(std::shared_ptr<Item> it): Enemy{30, 70, 5, it}{}
    char getChar() const override; // inherited from Stuff
    // int getHP() { return HP; } inherited from Character
	// int getAtk() { return Atk; } inherited from Character
	// int getDef() { return Def; } inherited from Character
	// bool isDead() { return (HP <= 0); } inherited from Character
	// void setHP(int hp) { HP = hp; } inherited from Character
	// void setAtk(int atk) { Atk = atk; } inherited from Character
	// void setDef(int def) { Def = def; } inherited from Character
	// void becomeHostile(); inherited from Enemy
	// void beAttacked(std::shared_ptr<Character> c) override; inherited from Enemy
};

#endif
