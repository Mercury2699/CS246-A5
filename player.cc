#include <cmath>
#include "player.h"
#include "potion.h"
#include "treasure.h"

Player::Player(int HP, int Atk, int Def):
	Character{HP, Atk, Def}, maxHP{HP}, defaultAtk{Atk}, defaultDef{Def}{
		type = Type::Plyr;
	}

void Player::setTreasure(double t) {
	treasure = t;
}

double Player::getTreasure() const {return treasure;}

void Player::setSuit(bool suit) {
	hasSuit = suit;
}

void Player::setCompass(bool comp) {
	hasCompass = comp;
}

void Player::setCell(std::shared_ptr<Cell> c){
	currPos = c;
}

std::shared_ptr<Cell> Player::getCell(){
	return currPos;
}

bool Player::getSuit() const {
	return hasSuit;
}

int Player::getDefaultAtk() const {
	return defaultAtk;
}

int Player::getDefaultDef() const {
	return defaultDef;
}

void Player::beAttacked(std::shared_ptr<Stuff> c) {
	if (getSuit()) {
		setHP(getHP() - ceil(ceil(((100 / (100 + getDef())) * c->getAtk())) / 2));
	} else {
		setHP(getHP()- ceil((100 / (100 + getDef())) * c->getAtk()));
	}
}


bool Player::hasKilledMerch() const {
	return killedMerch;
};

void Player::removePotion() {
	setAtk(getDefaultAtk());
	setDef(getDefaultDef());
}

char Player::getChar() const {
	return '@';
}

std::string Player::getRace() const {
	return race;
}

int Player::getMaxHP() const {
	return maxHP;
}




