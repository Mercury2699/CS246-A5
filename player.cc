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
	double damage = ceil((100 / (100 + static_cast<double>(this->getDef()))) * c->getAtk());
	if (getSuit()) {
		setHP(getHP() - ceil(damage / 2) <= 0 ? 0 : getHP() - ceil(damage / 2));
	} else {
		setHP(getHP() - damage <= 0 ? 0 : getHP() - damage);
		std::cout << "Setting HP to:" << (getHP()- damage) << std::endl;
	}
}

void Player::setKilledMerch(bool has){
	killedMerch = has;
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




