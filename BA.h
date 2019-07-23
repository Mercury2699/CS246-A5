#ifndef BA_H
#define BA_H

#include "potion.h"

class Player;

class BA : public Potion {

	public:
	BA(Player *p);
	void effect() override;
	void remove() override;
};

#endif