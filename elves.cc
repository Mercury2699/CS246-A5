#include "elves.h"

Elves::Elves(int HP, int Atk, int Def, double treasure):
	Player{HP, Atk, Def, treasure}{}

Elves::applyPotion(WoundAtk &wa) {
	setAtk(getAtk() + 5);
}

Elves::applyPotion(WoundDef &wd) {
	setDef(getDef() + 5);
}

Elves::removePotion(WoundAtk &wa) {
	setAtk(getAtk() - 5);
}

Elves::removePotion(WoundDef &wd) {
	setDef(getDef() - 5);
}





