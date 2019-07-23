#ifndef ORC_H
#define ORC_H
#include "player.h"

#include "player.h"
class Orc : public Player {
	
	public:
	Orc(int HP = 180, int Atk = 30, int Def = 25, double treasure = 0);
	void pickUpTreasure(Treasure *) override;
};

#endif
