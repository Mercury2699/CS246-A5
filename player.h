#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "treasure.h"

class RestorHP;
class PoisonHP;
class BoostAtk;
class BoostDef;
class WoundAtk;
class WoundDef;

class Player : public Character {

	double treasure = 0;
	bool hasSuit = false, hasCompass = false;
	const int maxHP;
	const int defaultAtk;
	const int defaultDef;

	protected:
	void setTreasure(double);
	bool getSuit();
	int getDefaultAtk();
	int getDefaultDef();
	int getMaxHP() const;

	public:
	Player(int HP, int Atk, int Def, double treasure);
	void virtual pickUpTreasure(Treasure *);
	void applyPotion(RestorHP &rh);
	void applyPotion(PoisonHP &ph);
	void applyPotion(BoostAtk &ba);
	void applyPotion(BoostDef &bd);
	void virtual applyPotion(WoundAtk &wa);
	void virtual applyPotion(WoundDef &wd);
	void virtual remove();
	void setCompass(bool);
	void setSuit(bool);
	void attack(Character *) override;
	void beAttacked(Character *) override;
	char getChar() override;
};

#endif
