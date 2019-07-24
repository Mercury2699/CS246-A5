#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "player.h"

class Human;
class Dwarf;
class Elves;
class Orc;

class Potion : public Item {};

class BoostDef : public Potion {
	void effect(Human &h) override {
		h.setDef(h.getDef() + 5);
	}
	void effect(Dwarf &d) override {
		d.setDef(d.getDef() + 5);
	}
	void effect(Orc &o) override {
		o.setDef(o.getDef() + 5);
	}
	void effect(Elves &e) override {
		e.setDef(e.getDef() + 5);
	}
};

class BoostAtk : public Potion {
	void effect(Human &h) override {
		h.setAtk(h.getAtk() + 5);
	}
	void effect(Dwarf &d) override {
		d.setAtk(d.getAtk() + 5);
	}
	void effect(Orc &o) override {
		o.setAtk(o.getAtk() + 5);
	}
	void effect(Elves &e) override {
		e.setAtk(e.getAtk() + 5);
	}
};

class PoisonHP : public Potion {
	void effect(Player *pc) override {
		pc->setDef(pc->getDef() + 5);
	}
};

class RestorHP : public Potion {
	void effect(Player *pc) override {
		pc->setDef(pc->getDef() + 5);
	}
};

class WoundAtk : public Potion {
	void effect(Player *pc) override {
		pc->setDef(pc->getDef() + 5);
	}
};

class WoundDef : public Potion {};
#endif



