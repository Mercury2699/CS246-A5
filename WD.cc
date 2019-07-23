#include "wd.cc"

WD::WD(Player *p):
	Potion{p}{}

void WD::effect() {
	getP()->applyPotion(*this);
}

void WD::remove() {
	getP()->removePotion(*this);
	getP()->remove();
}