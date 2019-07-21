#include "dwarf.h"

Dwarf::Dwarf():
	Character(100, 20, 30){}

void Dwarf::pickUpTreasure(Treasure *t) {
	setTreasure(2 * t->value());
}