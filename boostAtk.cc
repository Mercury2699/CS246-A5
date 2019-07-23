#include "boostAtk.h"

BoostAtk::BoostAtk(Player *p):
	Potion{p}{}

void BoostAtk::effect() {
	getP()->applyPotion(*this);
}

void BoostAtk::remove() {
	getP()->removePotion(*this);
	getP()->remove();
}




