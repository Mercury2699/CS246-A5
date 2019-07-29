#include "potion.h"
#include "player.h"

void BoostDef::effect(std::shared_ptr<Player> pc) {
	pc->setDef(pc->getDef() + 5);
}

void BoostAtk::effect(std::shared_ptr<Player> pc) {
	pc->setAtk(pc->getAtk() + 5);
}

void RestorHP::effect(std::shared_ptr<Player> pc) {
	int newHP = (pc->getHP() + 10) <= pc->getMaxHP() ? (pc->getHP() + 10) : pc->getMaxHP();
	pc->setHP(newHP);
}

void PoisonHP::effect(std::shared_ptr<Player> pc) {
	if(pc->getRace() == "Elves"){
		int newHP = (pc->getHP() + 10) <= pc->getMaxHP() ? (pc->getHP() + 10) : pc->getMaxHP();
		pc->setHP(newHP);
	} else {
		int newHP = (pc->getHP() - 10) >= 0 ? (pc->getHP() - 10) : 0;
		pc->setHP(newHP);
	}
}

void WoundAtk::effect(std::shared_ptr<Player> pc) {
	if(pc->getRace() == "Elves"){
		pc->setAtk(pc->getAtk() + 5);
	} else {
		pc->setAtk(pc->getAtk() - 5 >= 0 ? pc->getAtk() - 5 : 0);
	}
}

void WoundDef::effect(std::shared_ptr<Player> pc) {
	if(pc->getRace() == "Elves"){
		pc->setDef(pc->getDef() + 5);
	} else {
		pc->setDef(pc->getDef() - 5 >= 0 ? pc->getDef() - 5 : 0);
	}
}



