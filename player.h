#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character {

	double treasure;
	bool hasSuit;

	public:
	Player(double treasure);
	void virtual pickUpTreasure(Treasure *);
	void virtual applyPotion(Potion *) = 0;
	void attack(Character *) override;
	~Player() = 0;
	
	protected:
	void setTreasure(double);
	void setSuit(bool);
	bool getSuit();
};

#endif
