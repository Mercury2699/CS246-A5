#ifndef POISONHP_H
#define POISONHP_H

#include "potion.h"

class PoisonHP : public Potion {

	using Player::effect;
	using Player::remove;

	public:
	PoisonHP(Player *p);
	void effect() override;
	void remove() override;
};

#endif


