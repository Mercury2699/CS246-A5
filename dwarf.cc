#include "dwarf.h"

Dwarf::Dwarf(int HP, int Atk, int Def, double treasure):
	Player{HP, Atk, Def, treasure}{}

void Dwarf::pickUpTreasure(Treasure *t) {
	setTreasure(2 * t->getValue());
}

void Dwarf::applyPotion(Potion *p) {
	p->effect(*this);
}