#ifndef BOOSTDEF_H
#define BOOSTDEF_H

#include "potion.h"

class BoostDef : public Potion {

	using Player::effect;
	using Player::remove;

	public:
	BoostDef(Player *p);
	void effect() override;
	void remove() override;
};

#endif





