#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Treasure;
class Potion;

enum class PCRace {Human, Elves, Dwarf, Orc};

class Player : public Character {
	protected:
	int x, y;
	double treasure = 0;
	bool hasSuit = false, hasCompass = false, killedMerch = false;
	const int maxHP;
	const int defaultAtk;
	const int defaultDef;
	PCRace race;

	public:
	Player(int HP, int Atk, int Def, double treasure);
	void virtual pickUpTreasure(Treasure *);
	void virtual applyPotion(Potion *);
	void virtual removePotion();
	void attack(Character *) override;
	void beAttacked(Character *) override;
	void setPosn(int x, int y);
	int getX();
	int getY();
	void setCompass(bool);
	void setSuit(bool);
	void setTreasure(double);
	double getTreasure();
	void killedMerchant();
	bool hasKilledMerch();
	char getChar() override;
	bool getSuit();
	PCRace getRace();
	int getDefaultAtk();
	int getDefaultDef();
	int getMaxHP() const;
	virtual ~Player() = default;
};

#endif

