#include "enemy.h"

Enemy::Enemy(Treasure *t):
	Character{HP, Atk, Def, t{t}{}

Enemy::attack(Character *c) {
	if (c->getSuit()) {
		c.setHP(c.getHP() - ceiling (ceiling(((100 / (100 + c->getDef())) * getAtk())) / 2));
	} else {
		c->setHP(c->getHP()-((100 / (100 + c->getDef())) * getAtk()));
	}
}