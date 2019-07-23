#ifndef RESTORHP_H
#define RESTORHP_H

#include "potion.h"

class RestorHP : public Potion {

	using Player::effect;
	using Player::remove;

	public:
	RestorHP(Player *p);
	void effect() override;
	void remove() override;
};

#endif


