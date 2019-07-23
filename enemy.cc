#include "enemy.h"

Enemy::Enemy(Treasure *t):
	Character{HP, Atk, Def, t{t}{}

Enemy::attack(Character *c) {
	c->beAttacked(this);
}

Enemy::beAttacked(Character *c) {
	setHP(getHP()-((100 / (100 + getDef())) * c->getAtk()));
}