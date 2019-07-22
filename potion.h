#ifndef POTION_H
#define POTION_H

#include "item.h"
class Potion : public Item, public Decorator {

	public:
	void virtual effect(Human &) = 0;
	void virtual effect(Dwarf &) = 0;
	void virtual effect(Elves &) = 0;
	void virtual effect(Orc &) = 0;
};

#endif
