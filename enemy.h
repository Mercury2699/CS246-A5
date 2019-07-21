#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"


#include "character.h"
class Enemy : public Character {
	
	bool hostile;

	public:
	Enemy(bool hostile);
	bool isHostile();
	void setHostile(bool hostile);
};

#endif
