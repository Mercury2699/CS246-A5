#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"


#include "character.h"
class Enemy : public Character {
	Treasure *t;

	public:
	Enemy(Treasure *t);
	void attack(Character *) override;

};

#endif
