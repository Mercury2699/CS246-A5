#ifndef BD_H
#define BD_H

#include "potion.h"

class BD : public Potion {

	public:
	void virtual effect(Human &) override;
	void virtual effect(Dwarf &) override;
	void virtual effect(Elves &) override;
	void virtual effect(Orc &) override;
};

#endif