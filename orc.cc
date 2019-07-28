#include "orc.h"

Orc::Orc(int HP, int Atk, int Def) : Player{HP, Atk, Def}{
	race = "Orc";
}

void Orc::addTreasure(double val){
	treasure += val / 2;
}


