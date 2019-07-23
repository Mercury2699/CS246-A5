#include "elves.h"

Elves::Elves(int HP, int Atk, int Def, double treasure):
	Player{HP, Atk, Def, treasure}{}

Elves::applyPotion(WA &wa) {
	setAtk(getAtk() + 5);
}

Elves::applyPotion(WD &wd) {
	setDef(getDef() + 5);
}

Elves::removePotion(WA &wa) {
	setAtk(getAtk() - 5);
}

Elves::removePotion(WD &wd) {
	setDef(getDef() - 5);
}