#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>
#include <memory>
#include "character.h"

class Item;

class Enemy : public Character {
	protected:
	// Type type; inherited from Stuff
	// int HP; inherited from Character
	// int Atk; inherited from Character
	// int Def; inherited from Character
	std::shared_ptr<Item> i; // Item includes Suit, Compass, and Treasuress
	bool hostile = false;

	public:
	// virtual char getChar() const = 0; inherited from Stuff
	// int getHP() { return HP; } inherited from Character
	// int getAtk() { return Atk; } inherited from Character
	// int getDef() { return Def; } inherited from Character
	// bool isDead() { return (HP <= 0); } inherited from Character
	// void setHP(int hp) { HP = hp; } inherited from Character
	// void setAtk(int atk) { Atk = atk; } inherited from Character
	// void setDef(int def) { Def = def; } inherited from Character
	void becomeHostile() { hostile = true; }
	Enemy(int HP, int Atk, int Def, std::shared_ptr<Item> i) : Character{HP, Atk, Def}, i{i} {
		type = Type::Enmy;
	}
	void beAttacked(std::shared_ptr<Character> c) override {
		setHP(getHP()-ceil((100 / (100 + getDef())) * c->getAtk()));
	}
};

#endif

