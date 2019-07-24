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

enum class PCRace {Human, Elves, Dwarf, Orc};

class Player : public Character {
	protected:
	double treasure = 0;
	bool hasSuit = false, hasCompass = false;
	const int maxHP;
	const int defaultAtk;
	const int defaultDef;
	PCRace race;

	public:
	Player(int HP, int Atk, int Def, double treasure);
	void virtual pickUpTreasure(Treasure *);
	void virtual applyPotion(Stuff *);
	void virtual removePotion();
	void attack(Stuff *) override;
	void beAttacked(Stuff *) override;

	void setCompass(bool);
	void setSuit(bool);
	void setTreasure(double);
	char getChar() override;
	bool getSuit();
	Race getRace();
	int getDefaultAtk();
	int getDefaultDef();
	int getMaxHP() const;
};

#endif

