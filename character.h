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
	void setHP(int);
	int getAtk();
	void setAtk(int);
	int getDef();
	void setDef(int);
	virtual void attack(Character *) = 0;
	virtual bool isDead();
	virtual void beAttacked(Character *) = 0;
};

#endif
