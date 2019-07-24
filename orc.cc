#include "orc.h"
#include "treasure.h"

Orc::Orc(int HP, int Atk, int Def, double treasure):
	Player{HP, Atk, Def, treasure}{}

void Orc::pickUpTreasure(Treasure *t) {
	setTreasure(0.5 * t->getValue());
}

