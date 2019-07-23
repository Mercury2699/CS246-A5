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
	int getAtk();
	int getDef();
	virtual void attack(Character *) = 0;
	virtual bool isDead();
	virtual void beAttacked(Character *) = 0;

	protected:
	void setHP(int);
	void setAtk(int);
	void setDef(int);
};

#endif
