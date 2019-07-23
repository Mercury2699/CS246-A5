#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "treasure.h"

class BoostAtk;
class WoundAtk;
class BoostDef;
class WoundDef;
class RestorHP;
class PoisonHP;

class Player : public Character {

	double treasure = 0;
	bool hasSuit = false, hasCompass = false;
	const int maxHP;

	protected:
	void setTreasure(double);
	bool getSuit();

	public:
	Player(int HP, int Atk, int Def, double treasure);
	void virtual pickUpTreasure(Treasure *);
	void virtual applyPotion(RestorHP &rh);
	void virtual applyPotion(PoisonHP &ph);
	void virtual applyPotion(BoostAtk &ba);
	void virtual applyPotion(WoundAtk &wa);
	void virtual applyPotion(BoostDef &bd);
	void virtual applyPotion(WoundDef &wd);
	void virtual removePotion(BoostAtk &ba);
	void virtual removePotion(WoundAtk &wa);
	void virtual removePotion(BoostDef &bd);
	void virtual removePotion(WoundDef &wd);
	void setCompass(bool);
	void setSuit(bool);
	void attack(Character *) override;
	void beAttacked(Character *) override;
	void virtual remove() = 0;
	void virtual effect() = 0;
	char getChar() override;
	int getMaxHP() const;
};

#endif
