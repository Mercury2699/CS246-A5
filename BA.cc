#include "BA.h"

BA::BA(Player *p):
	Potion{p}{}

void BA::effect() {
	getP()->applyPotion(*this);
}

void BA::remove() {
	getP()->removePotion(*this);
	getP()->remove();
}