#ifndef BD_H
#define BD_H

#include "potion.h"

class BD : public Potion {

	public:
	BD(Player *p);
	void effect() override;
	void remove() override;
};

#endif