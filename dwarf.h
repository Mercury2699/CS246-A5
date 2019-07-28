#ifndef DWARF_H
#define DWARF_H
#include "player.h"


class Dwarf final : public Player {
	// protected:
	// Type type; inherited from Stuff
	// int HP; inherited from Character
	// int Atk; inherited from Character
	// int Def; inherited from Character
	// std::shared_ptr<Cell> currPos; inherited from Player
	// double treasure = 0; inherited from Player
	// bool hasSuit = false, hasCompass = false, killedMerch = false; inherited from Player
	// const int maxHP; inherited from Player
	// const int defaultAtk; inherited from Player
	// const int defaultDef; inherited from Player
	// std::string race; inherited from Player

	public:
	Dwarf(int HP = 100, int Atk = 20, int Def = 30);
	// Type getType(); inherited from Stuff
	// int getHP() { return HP; } inherited from Character
	// int getAtk() { return Atk; } inherited from Character
	// int getDef() { return Def; } inherited from Character
	// bool isDead() { return (HP <= 0); } inherited from Character
	// void setHP(int hp) { HP = hp; } inherited from Character
	// void setAtk(int atk) { Atk = atk; } inherited from Character
	// void setDef(int def) { Def = def; } inherited from Character
	// void removePotion(); inherited from Player
	// void beAttacked(std::shared_ptr<Stuff>) override; inherited from Player
	// void setCell(std::shared_ptr<Cell>); inherited from Player
	// void setCompass(bool); inherited from Player
	// void setSuit(bool); inherited from Player
	void addTreasure(double) override; // inherited from Player
	// double getTreasure() const; inherited from Player
	// bool hasKilledMerch() const; inherited from Player
	// char getChar() const override; inherited from Player
	// bool getSuit() const; inherited from Player
	// string getRace() const; inherited from Player
	// int getDefaultAtk() const; inherited from Player
	// int getDefaultDef() const; inherited from Player
	// int getMaxHP() const; inherited from Player
};

#endif



