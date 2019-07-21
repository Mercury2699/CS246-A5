#ifndef DWARF_H
#define DWARF_H
#include "player.h"


class Dwarf : public Player {
	
	public:
	Dwarf();
	void pickUpTreasure(Treasure *) override;
};

#endif
