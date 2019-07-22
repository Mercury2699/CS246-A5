#include "elves.h"

Elves::Elves(int HP, int Atk, int Def, double treasure):
	Player{HP, Atk, Def, treasure}{}

Elves::applyPotion(Potion *p) {
	p->effect(*this);
}