#ifndef RH_H
#define RH_H

#include "potion.h"

class RH : public Potion {

	public:
	RH(Player *p);
	void effect() override;
	void remove() override;
};

#endif