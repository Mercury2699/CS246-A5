#include "player.h"
#include "treasure.h"
Player::Player(int treasure):
	treasure{treasure}{}

Player::~Player() {}

Player::setTreasure(int t) {
	treasure = t;
}

Player::pickUpTreasure(Treasure *t) {
	setTreasure(t->value());
}

Player::applyPotion(Potion *p) {
	p->effect();
}




