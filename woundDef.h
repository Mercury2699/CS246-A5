#ifndef WOUNDDEF_H
#define WOUNDDEF_H

#include "potion.h"

class WoundDef : public Potion {

	using Player::effect;
	using Player::remove;
	
	public:
	WoundDef(Player *p);
	void effect() override;
	void remove() override;
};

#endif




