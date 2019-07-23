#ifndef WOUNDATK_H
#define WOUNDATK_H

#include "potion.h"

class WoundAtk : public Potion {
	
	using Player::effect;
	using Player::remove;

	public:
	WoundAtk(Player *p);
	void effect() override;
	void remove() override;
};

#endif



