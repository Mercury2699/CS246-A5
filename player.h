#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "treasure.h"
#include "potion.h"

class Player : public Character {

	double treasure;
	bool hasSuit;

	public:
	Player(int HP, int Atk, int Def, double treasure);
	void virtual pickUpTreasure(Treasure *);
	void virtual applyPotion(Potion *) = 0;
	void attack(Character *) override;
	virtual ~Player() = 0;
	
	protected:
	void setTreasure(double);
	void setSuit(bool);
	bool getSuit();
};

#endif
