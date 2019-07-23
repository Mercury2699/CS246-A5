#include "BD.h"

BD::BD(Player *p):
	Potion{p}{}

void BD::effect() {
	getP()->effect();
	getP()->applyPotion(*this);
}

void BD::remove() {
	getP()->removePotion(*this);
	getP()->remove();
}