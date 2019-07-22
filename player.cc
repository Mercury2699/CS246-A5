#include "player.h"
#include "treasure.h"
Player::Player(double treasure):
	treasure{treasure}{}

Player::~Player() {}

Player::setTreasure(Treasure *t) {
	treasure = t->getValue();
}

Player::pickUpTreasure(Treasure *t) {
	setTreasure(t->getValue());
}

Player::attack(Character *c) {
	c->setHP(c->getHP()-((100 / (100 + c->getDef())) * getAtk()));
	c->attack(this);
}




