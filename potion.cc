#include "potion.h"

Potion::Potion(Player *p):
	Player{*p}, p{p}{}

Player *Potion::getP() {
	return p;
}

