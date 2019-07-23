#include "PH.h"

PH::PH(Player *p):
	Potion{p}{}

void PH::effect() {
	getP()->applyPotion(*this);
}

void PH::remove() {
	getP()->remove();
}