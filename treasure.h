#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
#include "player.h"

class Treasure final : public Item {
	int val;
	bool canCollect = true; // for DragonHoard should be false

	public: 
	Treasure(int val);
	int getValue();
	char getChar() const override;
	void setCollect();
	void effect(std::shared_ptr<Player>) override;
};



#endif


