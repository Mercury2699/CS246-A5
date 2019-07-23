#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"


class Treasure;

class Enemy : public Character {
	Treasure *t;

	public:
	Enemy(int HP, int Atk, int Def, Treasure *t);
	void attack(Character *) override;

};

#endif
