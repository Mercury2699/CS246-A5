#include "restorHP.h"

RestorHP::RestorHP(Player *p):
	Potion{p}{}

void RestorHP::effect() {
	getP()->applyPotion(*this);
}

void RestorHP::remove() {
	getP()->remove();
}



