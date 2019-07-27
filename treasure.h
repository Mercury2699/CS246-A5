#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
#include "player.h"

class Treasure final : public Item {
	int val;
	bool canCollect = true; // for DragonHoard should be false
	std::shared_ptr<Stuff> dragon = nullptr;

	public: 
	Treasure(int val);
	int getValue();
	char getChar() const override;
	std::string getName() const override;
	void setCollect() override;
	bool isDragonHoard() override;
	void effect(std::shared_ptr<Player>) override;
	std::shared_ptr<Stuff> getDragon() override {return dragon; }
	void setDragon(std::shared_ptr<Stuff> d) override {dragon = d; }
};



#endif


