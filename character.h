#ifndef CHARACTER_H
#define CHARACTER_H

#include "stuff.h"
class Character : public Stuff {

	int HP;
	int Atk;
	int Def;

	const int maxHP;

	public:
	Character(int HP, int Atk, int Def);
	virtual void attack(Character *) = 0;
	virtual bool isDead();
	virtual void beAttacked(Character *) = 0;

	protected:
	int getHP();
	void setHP(int);
	int getAtk();
	void setAtk(int);
	int getDef();
	void setDef(int);
	int getMaxHp() const;
	virtual void attack(Character *) = 0;
	bool isDead();
	virtual void beAttacked(Character *) = 0;
};

#endif
