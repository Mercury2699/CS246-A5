#include "woundDef.h"

WoundDef::WoundDef(Player *p):
	Potion{p}{}

void WoundDef::effect() {
	getP()->applyPotion(*this);
}

void WoundDef::remove() {
	getP()->removePotion(*this);
	getP()->remove();
}




