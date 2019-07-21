#ifndef CHARACTER_H
#define CHARACTER_H

#include "stuff.h"
class Character : public Stuff {

	int HP;
	int Atk;
	int Def;

	public:
	Character(int HP, int Atk, int Def);
	int getHP();
	void setHP();
	int getAtk();
	int getDef();
	virtual void attack(Character *) = 0;
	virtual bool isDead() = 0;
	virtual void beAttacked(Character *);
};

#endif
