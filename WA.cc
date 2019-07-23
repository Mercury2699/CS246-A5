#include "WA.h"

WA::WA(Player *p):
	Potion{p}{}

void WA::effect() {
	getP()->effect();
	getP()->applyPotion(*this);
}

void WA::remove() {
	getP()->removePotion(*this);
	getP()->remove();
}