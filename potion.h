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
	public:
	void effect(Elves &e) override {
		e.setDef(e.getDef() + 5);
	}
	void effect(Human &h) override {
		h.setDef(h.getDef() + 5);
	}

	void effect(Dwarf &d) override {
		d.setDef(d.getDef() + 5);
	}

	void effect(Orc &o) override {
		o.setDef(o.getDef() + 5);
	}
};

class BoostAtk : public Potion {
	public:
	void effect(Elves &e) override {
		e.setAtk(e.getAtk() + 5);
	}
	void effect(Human &h) override {
		h.setAtk(h.getAtk() + 5);
	}

	void effect(Dwarf &d) override {
		d.setAtk(d.getAtk() + 5);
	}

	void effect(Orc &o) override {
		o.setAtk(o.getAtk() + 5);
	}
};

class RestorHP : public Potion {
	public:
	void effect(Elves &e) override {
		int newHP = (e.getHP() + 10) <= e.getMaxHP() ? (e.getHP() + 10) : e.getMaxHP();
		e.setHP(newHP);
	}
	void effect(Human &h) override {
		int newHP = (h.getHP() + 10) <= h.getMaxHP() ? (h.getHP() + 10) : h.getMaxHP();
		h.setHP(newHP);
	}

	void effect(Dwarf &d) override {
		int newHP = (d.getHP() + 10) <= d.getMaxHP() ? (d.getHP() + 10) : d.getMaxHP();
		d.setHP(newHP);
	}

	void effect(Orc &o) override {
		int newHP = (o.getHP() + 10) <= o.getMaxHP() ? (o.getHP() + 10) : o.getMaxHP();
		o.setHP(newHP);
	}
};

class PoisonHP : public Potion {
	public:
	void effect(Elves &e) override {
		int newHP = (e.getHP() + 10) <= e.getMaxHP() ? (e.getHP() + 10) : e.getMaxHP();
		e.setHP(newHP);
	}

	void effect(Human &h) override {
		int newHP = (h.getHP() - 10) >= 0 ? (h.getHP() - 10) : 0;
		h.setHP(newHP);
	}

	void effect(Dwarf &d) override {
		int newHP = (d.getHP() - 10) >= 0 ? (d.getHP() - 10) : 0;
		d.setHP(newHP);
	}

	void effect(Orc &o) override {
		int newHP = (o.getHP() - 10) >= 0 ? (o.getHP() - 10) : 0;
		o.setHP(newHP);
	}
};

class WoundAtk : public Potion {
	public:
	void effect(Elves &e) override {
		e.setAtk(e.getAtk() + 5);
	}

	void effect(Human &h) {
		h.setAtk(h.getAtk() - 5);
	}
	void effect(Dwarf &d) {
		d.setAtk(d.getAtk() - 5);
	}
	void effect(Orc &o) {
		o.setAtk(o.getAtk() - 5);
	}
};

class WoundDef : public Potion {
	public:
	void effect(Elves &e) override {
		e.setDef(e.getDef() + 5);
	}
	void effect(Human &h) {
		h.setDef(h.getDef() - 5);
	}
	void effect(Dwarf &d) {
		d.setDef(d.getDef() - 5);
	}
	void effect(Orc &o) {
		o.setDef(o.getDef() - 5);
	}
};
#endif



