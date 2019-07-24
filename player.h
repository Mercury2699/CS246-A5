#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "character.h"

class Cell;
class Treasure;
class Potion;

enum class PCRace {Human, Elves, Dwarf, Orc};

class Player : public Character {
	protected:
	// int HP; inherited from Character
	// int Atk; inherited from Character
	// int Def; inherited from Character
	// Type type; inherited from Stuff
	std::shared_ptr<Cell> currPos;
	double treasure = 0;
	bool hasSuit = false, hasCompass = false, killedMerch = false;
	const int maxHP;
	const int defaultAtk;
	const int defaultDef;
	PCRace race;
	
	public:
	// Type getType(); inherited from Stuff
	// int getHP() { return HP; } inherited from Character
	// int getAtk() { return Atk; } inherited from Character
	// int getDef() { return Def; } inherited from Character
	// bool isDead() { return (HP <= 0); } inherited from Character
	// void setHP(int hp) { HP = hp; } inherited from Character
	// void setAtk(int atk) { Atk = atk; } inherited from Character
	// void setDef(int def) { Def = def; } inherited from Character
	Player(int HP, int Atk, int Def, double treasure);
	void virtual pickUpTreasure(std::shared_ptr<Treasure>);
	void virtual applyPotion(std::shared_ptr<Potion>);
	void virtual removePotion();
	void attack(std::shared_ptr<Character>) override;
	void beAttacked(std::shared_ptr<Character>) override;
	// void setPosn(int x, int y);
	// int getX();
	// int getY();
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

