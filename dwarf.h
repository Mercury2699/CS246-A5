#ifndef DWARF_H
#define DWARF_H
#include "player.h"


class Dwarf : public Player {
	
	public:
	Dwarf(int HP = 100, int Atk = 20, int Def = 30, double treasure = 0);
	// void pickUpTreasure(Treasure *) override;
};

#endif
