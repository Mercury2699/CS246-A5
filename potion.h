#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "player.h"

// enum Potype { BoostAtk, BoostDef, RestoreHP, WoundAtk, WoundDef, PoisonHP };

class Potion : public Item {
	Type type = Type::Ptn;
	// Potype potype;
	public:
	char getChar() override {return 'P';}
};

class BoostDef : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override {
		pc->setDef(pc->getDef() + 5);
	}
};

class BoostAtk : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override {
		pc->setAtk(pc->getAtk() + 5);
	}
};

class RestorHP : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override {
		int newHP = (pc->getHP() + 10) <= pc->getMaxHP() ? (pc->getHP() + 10) : pc->getMaxHP();
		pc->setHP(newHP);
	}
};

class PoisonHP : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override {
		if(pc->getRace() == PCRace::Elves){
			int newHP = (pc->getHP() + 10) <= pc->getMaxHP() ? (pc->getHP() + 10) : pc->getMaxHP();
			pc->setHP(newHP);
		} else {
			int newHP = (pc->getHP() - 10) >= 0 ? (pc->getHP() - 10) : 0;
			pc->setHP(newHP);
		}
	}
};

class WoundAtk : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override {
		if(pc->getRace() == PCRace::Elves){
			pc->setAtk(pc->getAtk() + 5);
		} else {
			pc->setAtk(pc->getAtk() - 5);
		}

	}
};

class WoundDef : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override {
		if(pc->getRace() == PCRace::Elves){
			pc->setDef(pc->getDef() + 5);
		} else {
			pc->setDef(pc->getDef() - 5);
		}

	}
};


#endif



