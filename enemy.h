#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>
#include <memory>
#include "character.h"

class Item;

class Enemy : public Character {
	protected:
	std::shared_ptr<Item> i; // Item includes Suit, Compass, and Treasuress
	bool hostile = false;

	public:
	virtual char getChar() = 0;
	virtual void becomeHostile() { hostile = true; }
	Enemy(int HP, int Atk, int Def, Item *i) : Character{HP, Atk, Def}, i{i} {
		type = Type::Enmy;
	}
	void attack(Character *c) {
		c->beAttacked(this);
	}
	void beAttacked(Character *c) {
		setHP(getHP()-ceil((100 / (100 + getDef())) * c->getAtk()));
	}
	
};

#endif

