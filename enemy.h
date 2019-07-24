#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>
#include <memory>
#include "character.h"

class Treasure;

class Enemy : public Character {
	protected:
	std::unique_ptr<Treasure> t;
	bool hostile = false;

	public:
	virtual char getChar() = 0;
	virtual void becomeHostile() { hostile = true; }
	Enemy(int HP, int Atk, int Def, Treasure *t) : Character{HP, Atk, Def}, t{t} {
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

