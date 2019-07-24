#include "elves.h"

Elves::Elves(int HP, int Atk, int Def, double treasure):
	Player{HP, Atk, Def, treasure}{}

void Elves::applyPotion(WoundAtk &wa) {
	setAtk(getAtk() + 5);
}

void Elves::applyPotion(WoundDef &wd) {
	setDef(getDef() + 5);
}




