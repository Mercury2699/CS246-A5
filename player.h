#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "treasure.h"

class BA;
class WA;
class BD;
class WD;

class Player : public Character {

	double treasure;
	bool hasSuit;

	public:
	Player(int HP, int Atk, int Def, double treasure);
	void virtual pickUpTreasure(Treasure *);
	void virtual applyPotion(BA &ba);
	void virtual applyPotion(WA &wa);
	void virtual applyPotion(BD &bd);
	void virtual applyPotion(WD &wd);
	void virtual removePotion(BA &ba);
	void virtual removePotion(WA &wa);
	void virtual removePotion(BD &bd);
	void virtual removePotion(WD &wd);
	void attack(Character *) override;
	void virtual remove() = 0;
	void virtual effect() = 0;
	char getState() override;

	protected:
	void setTreasure(double);
	void setSuit(bool);
	bool getSuit();
};

#endif
