#include "orc.h"

Orc::Orc(int HP, int Atk, int Def, double treasure):
	Player{HP, Atk, Def, treasure}{}

Orc::pickUpTreasure(Treasure *t) {
	setTreasure(0.5 * t->getValue());
}

