#include "RH.h"

RH::RH(Player *p):
	Potion{p}{}

void RH::effect() {
	getP()->applyPotion(*this);
}

void RH::remove() {
	getP()->remove();
}