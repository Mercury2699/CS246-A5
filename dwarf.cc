#include "dwarf.h"
#include "treasure.h"

Dwarf::Dwarf(int HP, int Atk, int Def, double treasure):
	Player{HP, Atk, Def, treasure}{
		race = PCRace::Dwarf;
	}

// void Dwarf::pickUpTreasure(Treasure *t) {
// 	setTreasure(2 * t->getValue());
// }




