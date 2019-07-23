#ifndef WD_H
#define WD_H

#include "potion.h"

class WD : public Potion {
	
	public:
	WD(Player *p);
	void effect() override;
	void remove() override;
};

#endif