#include "treasure.h"

#include "player.h"

Treasure::Treasure(int val): val{val} {
	type = Type::Trsr;
	if (val >= 6){
		canCollect = false;
	}
}

int Treasure::getValue() { 
    return val; 
}

std::string Treasure::getName() const {
	if (val == 1) return "Normal Hoard";
	if (val > 1 && val < 4) return "Small Hoard";
	if (val >= 4 && val < 6) return "Merchant Hoard";
	else return "DRAGON HOARD!!!";
}

char Treasure::getChar() const {
    return 'G';
}

void Treasure::setCollect() {
	canCollect = true;
}

bool Treasure::isDragonHoard() {
	if (canCollect) return false;
	return true;
}

void Treasure::effect(std::shared_ptr<Player> pc) {
	pc->addTreasure(val);
}

