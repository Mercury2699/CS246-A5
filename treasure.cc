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

char Treasure::getChar() const {
    return 'G';
}

void Treasure::setCollect() {
	canCollect = true;
}

void Treasure::effect(std::shared_ptr<Player> pc) {
	pc->setTreasure(pc->getTreasure() + val);
}



