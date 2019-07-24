#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
#include "player.h"

class Treasure : public Item {
	int val;
	bool canCollect = true; // for DragonHoard should be false

	public: 
	Treasure(int val);
	int getValue();
	char getChar() override;
	void setCollect();
	void effect(Player *) override;
};



#endif


