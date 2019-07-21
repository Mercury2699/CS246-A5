#ifndef CHARACTER_H
#define CHARACTER_H

#include "stuff.h"
class Character : public Stuff {

	int HP;
	int Atk;
	int Def;

	public:
	Character(int HP, int Atk, int Def);
	void virtual attack(Character *defender) = 0;
	bool isDead();

};

#endif
