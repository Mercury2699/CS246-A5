#ifndef ELVES_H
#define ELVES_H
#include "player.h"

#include "player.h"
class Elves : public Player {

	public:
	Elves(int HP = 140, Atk = 30, Def = 10);
	void applyPotion(Potion *);
};

#endif
