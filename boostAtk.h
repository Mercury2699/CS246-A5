#ifndef BOOSTATK_H
#define BOOSTATK_H

#include "potion.h"

class Player;

class BoostAtk : public Potion {

	using Player::effect;
	using Player::remove;

	public:
	BoostAtk(Player *p);
	void effect() override;
	void remove() override;
};

#endif





