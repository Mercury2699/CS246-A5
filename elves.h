#ifndef ELVES_H
#define ELVES_H
#include "player.h"

#include "player.h"
class Elves : public Player {

	public:
	Elves(int HP = 140, int Atk = 30, int Def = 10, double treasure = 0);
	void applyPotion(Potion *);
};

#endif
