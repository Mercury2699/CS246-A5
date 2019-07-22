#include "dwarf.h"

Dwarf::Dwarf(int HP, int Atk, int Def):
	Character{Hp, Atk, Def}{}

void Dwarf::pickUpTreasure(Treasure *t) {
	setTreasure(2 * t->getValue());
}

void Dwarf::applyPotion(Potion *p) {
	p->effect(*this);
}