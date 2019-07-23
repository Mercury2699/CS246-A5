#include "RH.h"

RH::RH(Player *p):
	Potion{p}{}

void RH::effect() {
	int newHP = (p->getHP() + 10) <= getMaxHP() ? (p->getHP() + 10) : getMaxHP();
	getP()->setHP(newHP);
}

void PH::remove() {
	getP()->remove();
}