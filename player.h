#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "treasure.h"

class BA;
class WA;
class BD;
class WD;
class RH;
class PH;

class Player : public Character {

	double treasure;
	bool hasSuit;
	const int maxHP;

	public:
	Player(int HP, int Atk, int Def, double treasure);
	void virtual pickUpTreasure(Treasure *);
	void virtual applyPotion(RH &rh);
	void virtual applyPotion(PH &ph);
	void virtual applyPotion(BA &ba);
	void virtual applyPotion(WA &wa);
	void virtual applyPotion(BD &bd);
	void virtual applyPotion(WD &wd);
	void virtual removePotion(BA &ba);
	void virtual removePotion(WA &wa);
	void virtual removePotion(BD &bd);
	void virtual removePotion(WD &wd);
	void attack(Character *) override;
	void beAttacked(Character *) override;
	void virtual remove() = 0;
	void virtual effect() = 0;
	char getChar() override;
	int getMaxHP() const;

	protected:
	void setTreasure(double);
	void setSuit(bool);
	bool getSuit();
};

#endif
