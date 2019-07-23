#ifndef WA_H
#define WA_H

#include "potion.h"

class WA : public Potion {
	
	public:
	WA(Player *p);
	void effect() override;
	void remove() override;
};

#endif