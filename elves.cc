#include "elves.h"

Elves::Elves(int HP, int Atk, int Def):
	Character{HP, Atk, Def}{}

Elves::applyPotion(Potion *p) {
	p->effect(*this);
}