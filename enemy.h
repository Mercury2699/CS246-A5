#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>
#include <memory>
#include "character.h"

class Item;

class Enemy : public Character {
	protected:
	// int HP; inherited from Character
	// int Atk; inherited from Character
	// int Def; inherited from Character
	// Type type; inherited from Stuff
	std::shared_ptr<Item> i; // Item includes Suit, Compass, and Treasuress
	bool hostile = false;

	public:
	// int getHP() { return HP; } inherited from Character
	// int getAtk() { return Atk; } inherited from Character
	// int getDef() { return Def; } inherited from Character
	// bool isDead() { return (HP <= 0); } inherited from Character
	// void setHP(int hp) { HP = hp; } inherited from Character
	// void setAtk(int atk) { Atk = atk; } inherited from Character
	// void setDef(int def) { Def = def; } inherited from Character
	virtual char getChar() = 0;
	virtual void becomeHostile() { hostile = true; }
	Enemy(int HP, int Atk, int Def, Item *i) : Character{HP, Atk, Def}, i{i} {
		type = Type::Enmy;
	}
	// void attack(std::shared_ptr<Character> c) {
	// 	c->beAttacked(std::make_shared<Character> (this));
	// }
	void beAttacked(std::shared_ptr<Character> c) {
		setHP(getHP()-ceil((100 / (100 + getDef())) * c->getAtk()));
	}
	
};

#endif

