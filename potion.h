#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "player.h"
class Human;
class Dwarf;
class Elves;
class Orc;

class Potion : public Item, public Player {

	Player *p;

	protected:
	Player *getP();

	public:
	Potion(Player *);
};

#endif
