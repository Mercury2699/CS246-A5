#include "player.h"
#include "treasure.h"
#include <cmath>

Player::Player(int HP, int Atk, int Def, double treasure):
	Character{HP, Atk, Def}, treasure{treasure}, maxHP{HP}{}

void Player::setTreasure(double t) {
	treasure = t;
}

void Player::setSuit(bool suit) {
	hasSuit = suit;
}

bool Player::getSuit() {
	return hasSuit;
}

void Player::pickUpTreasure(Treasure *t) {
	setTreasure(t->getValue());
}

void Player::attack(Character *c) {
	c->beAttacked(this);
	c->attack(this);
}

void Player::beAttacked(Character *c) {
	if (getSuit()) {
		setHP(getHP() - ceil(ceil(((100 / (100 + getDef())) * c->getAtk())) / 2));
	} else {
		setHP(getHP()- ceil((100 / (100 + getDef())) * c->getAtk()));
	}
}

void Player::applyPotion(BoostAtk &ba) {
	setAtk(getAtk() + 5);
}

void Player::applyPotion(WoundAtk &wa) {
	setAtk(getAtk() - 5);
}

void Player::applyPotion(BoostDef &bd) {
	setAtk(getDef() + 5);
}

void Player::applyPotion(WoundDef &wd) {
	setAtk(getDef() - 5);
}

void Player::applyPotion(RestorHP &rh) {
	int newHP = (getHP() + 10) <= getMaxHP() ? (getHP() + 10) : getMaxHP();
	setHP(newHP);
}

void Player::applyPotion(PoisonHP &ph) {
	int newHP = (getHP() - 10) >= 0 ? (getHP() - 10) : 0;
	setHP(newHP);
}

void Player::removePotion(BoostAtk &ba) {
	setAtk(getAtk() - 5);
}

void Player::removePotion(WoundAtk &wa) {
	setAtk(getAtk() + 5);
}

void Player::removePotion(BoostDef &bd) {
	setAtk(getDef() - 5);
}

void Player::removePotion(WoundDef &wd) {
	setAtk(getDef() + 5);
}

char Player::getChar() {
	return '@';
}

int Player::getMaxHP() const {
	return maxHP;
}




