#ifndef PH_H
#define PH_H

#include "potion.h"

class PH : public Potion {

	public:
	PH(Player *p);
	void effect() override;
	void remove() override;
};

#endif