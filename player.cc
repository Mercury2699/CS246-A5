#include "player.h"
#include "treasure.h"
Player::Player(int HP, int Atk, int Def, double treasure):
	Character{HP, Atk, Def}, treasure{treasure}{}

Player::~Player() {}

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




