#include "poisonHP.h"

PoisonHP::PoisonHP(Player *p):
	Potion{p}{}

void PoisonHP::effect() {
	getP()->applyPotion(*this);
}

void PoisonHP::remove() {
	getP()->remove();
}


