#include "orc.h"

Orc::Orc(int HP, int Atk, int Def):
	Character{HP, Atk, Def}{}

Orc::pickUpTreasure(Treasure *t) {
	setTreasure(0.5 * t->getValue());
}

Orc::applyPotion(Potion *p) {
	p->effect(*this);
}