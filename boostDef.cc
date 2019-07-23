#include "boostDef.h"

BoostDef::BoostDef(Player *p):
	Potion{p}{}

void BoostDef::effect() {
	getP()->effect();
	getP()->applyPotion(*this);
}

void BoostDef::remove() {
	getP()->removePotion(*this);
	getP()->remove();
}






