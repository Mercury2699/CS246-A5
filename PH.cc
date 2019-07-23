#include "PH.h"

PH::PH(Player *p):
	Potion{p}{}

void PH::effect() {
	int newHP = (P->getHP() - 10) >= 0 ? (P->getHP() - 10) : 0;
	getP()->setHP(newHP);
}

void PH::remove() {
	getP()->remove();
}