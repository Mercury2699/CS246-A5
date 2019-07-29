#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <string>
#include "character.h"

class Cell;
class Treasure;
class Potion;

// enum class PCRace {Human, Elves, Dwarf, Orc};

class Player : public Character{
	protected:
	// int HP; inherited from Character
	// int Atk; inherited from Character
	// int Def; inherited from Character
	// Type type; inherited from Stuff
	double treasure = 0;
	bool hasSuit = false, hasCompass = false, killedMerch = false;
	const int maxHP;
	const int defaultAtk;
	const int defaultDef;
	std::string race;
	
	public:
	// Type getType(); inherited from Stuff
	// int getHP() { return HP; } inherited from Character
	// int getAtk() { return Atk; } inherited from Character
	// int getDef() { return Def; } inherited from Character
	// bool isDead() { return (HP <= 0); } inherited from Character
	// void setHP(int hp) { HP = hp; } inherited from Character
	// void setAtk(int atk) { Atk = atk; } inherited from Character
	// void setDef(int def) { Def = def; } inherited from Character
	Player(int HP, int Atk, int Def);
	void removePotion();
	void beAttacked(std::shared_ptr<Stuff>) override;
	void setCompass(bool);
	void setSuit(bool);
	virtual void addTreasure(double);
	double getTreasure() const;
	bool hasKilledMerch() const;
	void setKilledMerch(bool);
	char getChar() const override;
	bool getSuit() const;
	std::string getRace() const;
	int getDefaultAtk() const;
	int getDefaultDef() const;
	int getMaxHP() const;
	virtual ~Player() = default;
};

#endif

