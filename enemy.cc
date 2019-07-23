#include "enemy.h"
#include <cmath>

Enemy::Enemy(int HP, int Atk, int Def, Treasure *t):
	Character{HP, Atk, Def}, t{t}{}

void Enemy::attack(Character *c) {
	c->beAttacked(this);
}

void Enemy::beAttacked(Character *c) {
	setHP(getHP()-ceil((100 / (100 + getDef())) * c->getAtk()));
}


