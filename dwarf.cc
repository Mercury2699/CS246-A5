#include "dwarf.h"

Dwarf::Dwarf(int HP, int Atk, int Def) : Player{HP, Atk, Def}{
	race = "Dwarf";
}

void Dwarf::addTreasure(double val){
	treasure += val * 2;
}



