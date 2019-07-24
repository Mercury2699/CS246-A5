#include "treasure.h"

#include "player.h"

Treasure::Treasure(int val): val{val} {
	if (val >= 6){
		canCollect = false;
	}
}

int Treasure::getValue() { 
    return val; 
}

char Treasure::getChar() {
    return 'G';
}

void Treasure::setCollect() {
	canCollect = true;
}

void Treasure::effect(Player * pc) {
	pc->setTreasure(pc->getTreasure() + val);
}




