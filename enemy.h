#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>
#include "character.h"


class Treasure;

class Enemy : public Character {
	Treasure *t;

	public:
	Enemy(int HP, int Atk, int Def, Treasure *t) : Character{HP, Atk, Def}, t{t} {
		type = Type::Enmy;
	}
	void attack(Character *c) override {
		c->beAttacked(this);
	}
	void beAttacked(Character *c) override {
		setHP(getHP()-ceil((100 / (100 + getDef())) * c->getAtk()));
	}

};

#endif

