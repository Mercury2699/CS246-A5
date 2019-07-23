#include "player.h"
#include "treasure.h"

Player::Player(int HP, int Atk, int Def, double treasure):
	Character{HP, Atk, Def}, treasure{treasure}{}

void Player::setTreasure(double t) {
	treasure = t;
}

void Player::pickUpTreasure(Treasure *t) {
	setTreasure(t->getValue());
}

void Player::attack(Character *c) {
	c->setHP(c->getHP()-((100 / (100 + c->getDef())) * getAtk()));
	c->attack(this);
}

void Player::applyPotion(BA &ba) {
	setAtk(getAtk() + 5);
}

void Player::applyPotion(WA &wa) {
	setAtk(getAtk() - 5);
}

void Player::applyPotion(BD &bd) {
	setAtk(getDef() + 5);
}

void Player::applyPotion(WD &wd) {
	setAtk(getDef() - 5);
}

void Player::removePotion(BA &ba) {
	setAtk(getAtk() - 5);
}

void Player::removePotion(WA &wa) {
	setAtk(getAtk() + 5);
}

void Player::removePotion(BD &bd) {
	setAtk(getDef() - 5);
}

void Player::removePotion(WD &wd) {
	setAtk(getDef() + 5);
}

char Player::getState() {
	return '@';
}




