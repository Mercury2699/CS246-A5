#include "woundAtk.h"

WoundAtk::WoundAtk(Player *p):
	Potion{p}{}

void WoundAtk::effect() {
	getP()->applyPotion(*this);
}

void WoundAtk::remove() {
	getP()->removePotion(*this);
	getP()->remove();
}


