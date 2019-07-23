#include "potion.h"

Potion::Potion(Player *p):
	P{P} {
		cp = p;
	}

Player *Potion::getP() {
	return p;
}

