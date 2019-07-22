#ifndef POTION_H
#define POTION_H

#include "item.h"
class Human;
class Dwarf;
class Elves;
class Orc;

class Potion : public Item {

	public:
	void virtual effect(Human &) = 0;
	void virtual effect(Dwarf &) = 0;
	void virtual effect(Elves &) = 0;
	void virtual effect(Orc &) = 0;
};

#endif
