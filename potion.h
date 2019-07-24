#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "player.h"
#include "human.h"
#include "dwarf.h"
#include "orc.h"
#include "elves.h"

class Potion : public Item {
	type = Type::Ptn;
};

class BoostDef : public Potion {
	void effect(Human &h) {
		h.setDef(h.getDef() + 5);
	}
	void effect(Dwarf &d) {
		d.setDef(d.getDef() + 5);
	}
	void effect(Orc &o) {
		o.setDef(o.getDef() + 5);
	}
	void effect(Elves &e) {
		e.setDef(e.getDef() + 5);
	}
};

class BoostAtk : public Potion {
	void effect(Human &h) {
		h.setAtk(h.getAtk() + 5);
	}
	void effect(Dwarf &d) {
		d.setAtk(d.getAtk() + 5);
	}
	void effect(Orc &o) {
		o.setAtk(o.getAtk() + 5);
	}
	void effect(Elves &e) {
		e.setAtk(e.getAtk() + 5);
	}
};

class PoisonHP : public Potion {
	void effect(Player *pc) {
		pc->setDef(pc->getDef() + 5);
	}
};

class RestorHP : public Potion {
	void effect(Player *pc) {
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



