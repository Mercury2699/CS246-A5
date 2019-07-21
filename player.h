#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character {

	int treasure;

	public:
	Player(int treasure);
	void virtual pickUpTreasure(Treasure *);
	void virtual applyPotion(Potion *);
	~Player() = 0;
	
	protected:
	void setTreasure(int);
};

#endif
